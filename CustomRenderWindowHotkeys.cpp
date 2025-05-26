#include "GameForms.h"
#include "GameObjects.h"
#include "GameData.h"
#include "GameSettings.h"
#include "GECKUtility.h"
#include "NavMeshPickPreventer.h"

#include <CommCtrl.h>

namespace CustomRenderWindowHotkeys
{
	void PlaceXMarker()
	{
		NiPoint3 pos, rot;
		if (RenderWindow::GetMousePos(&pos, &rot))
		{
			TESObjectSTAT* xMarker = *(TESObjectSTAT**)0xEDDA54;
			if (auto ref = DataHandler::GetSingleton()->CreateReferenceAtLocation(xMarker, &pos, &NiPoint3::ZERO, 0))
			{
				CdeclCall(0x44F470);
				CdeclCall(0x44F260, ref); // RenderWindow::AddRef

				HistoryManager::GetSingleton()->AddAction(2, RenderWindow::SelectedData::GetSelected());

				if (*(byte*)0xECFB74) // CellView::bLoaded
				{
					auto pos = &RenderWindow::SelectedData::GetSelected()->pos;
					CdeclCall(0x42E3C0, &pos, 1); // CellView::Refresh
				}
			}
		}
	}

	void ToggleRefVisible(TESObjectREFR* ref)
	{
		if (auto node = ref->Get3D())
		{
			if (node = ThisCall<NiNode*>(0x68B370, node, 0xF1FDD4)) // NiRTTI::HasType(&NiNode::ms_RTTI);
			{
				node->SetAlphaRecurse(1.0F);
				node->m_flags &= ~0x200001;
				node->UpdatePropertiesUpward();
			}
		}
	}

	void SetAllObjectsVisible()
	{
		RunCallbackOnAllCellRefs(ToggleRefVisible);
	}

	static bool bAllDisabledRefsHidden = false;
	void GetAnyDisabledRefsVisible(TESObjectREFR* ref)
	{
		if (ref->IsDisabled())
		{
			if (auto node = ref->Get3D())
			{
				if (node->IsNiNode())
				{
					if (node->IsVisible())
					{
						bAllDisabledRefsHidden = false;
					}
				}
			}
		}
	}

	void SetIsDisabledRefHidden(TESObjectREFR* ref)
	{
		if (ref->IsDisabled())
		{
			if (auto node = ref->Get3D())
			{
				if (node->IsNiNode())
				{
					node->SetVisible(!bAllDisabledRefsHidden);
				}
			}
		}
	}

	void ToggleShowDisabledObjects()
	{
		bAllDisabledRefsHidden = true;
		RunCallbackOnAllCellRefs(GetAnyDisabledRefsVisible);
		bAllDisabledRefsHidden = !bAllDisabledRefsHidden;
		RunCallbackOnAllCellRefs(SetIsDisabledRefHidden);
	}

	void LinkSelectedRefs()
	{
		auto selected = RenderWindow::SelectedData::GetSelected();
		if (selected->selectedForms && selected->selectedForms->next && selected->numItems == 2)
		{
			if (auto ref1 = CdeclCall<TESObjectREFR*>(0xC5D114, selected->selectedForms->ref, 0, 0xE8C57C, 0xE8E3E4, 0)) // DYNAMIC_CAST(TESForm, TESObjectREFR)
			{
				if (auto ref2 = CdeclCall<TESObjectREFR*>(0xC5D114, selected->selectedForms->next->ref, 0, 0xE8C57C, 0xE8E3E4, 0)) // DYNAMIC_CAST(TESForm, TESObjectREFR)
				{
					if (ref2->CanSetLinkedRef())
					{
						if (ref1->Unk_43() && ref1->Unk_4E())
						{
							ref1->MarkAsModified();
							ref1->SetLinkedRef(ref2);
							ref1->RedrawLinkedRefs();
							SendMessageA(RenderWindow::GetWindow(), 0x40Au, 0, 0);
							Console_Print("RENDER WINDOW: Linked %s (%08X) to %s (%08X)", ref1->GetEditorID(), ref1->refID, ref2->GetEditorID(), ref2->refID);
							return;
						}
					}
					else
					{
						Console_Print("RENDER WINDOW: %s (%08X) cannot be set as a linked ref", ref2->GetEditorID(), ref2->refID);
					}
				}
			}
		}
		PlaySound("SystemExclamation", NULL, SND_ASYNC);
	}

	void ToggleSelectedRefPersists()
	{
		auto selected = RenderWindow::SelectedData::GetSelected();
		bool bHasNonPersistentRefs = false;
		for (auto ref : *selected)
		{
			if (!ref->IsPersistent())
			{
				bHasNonPersistentRefs = true;
				break;
			}
		}
		
		for (auto ref : *selected)
		{
			ref->SetPersistent(bHasNonPersistentRefs);
		}
	}

	enum CustomHotkey
	{
		kHotkey_NONE = 0x47, // max ID of the vanilla IDs
		kHotkey_FIRST,
		kHotkey_ToggleShowLightMarkers = kHotkey_FIRST,
		kHotkey_SetAllObjectsVisible,
		kHotkey_PlaceXMarker,
		kHotkey_NavMeshIgnoreLastPick,
		kHotkey_NavMeshIgnoreSelectedPicks,
		kHotkey_ToggleShowDisabledObjects,
		kHotkey_LinkRefs,
		kHotkey_ToggleRefPersists,
	};

	static RenderWindowHotkey CustomHotkeys[] =
	{
		RenderWindowHotkey("Toggle show light markers", "ToggleShowLightMarkers", 'I', RenderWindowHotkey::kRenderWindowPreferenceFlag_NONE, RenderWindowHotkey::kRenderHotkeyCategory_Visibility),
		RenderWindowHotkey("Set all objects visible", "SetAllObjectsVisible", VK_OEM_4, RenderWindowHotkey::kRenderWindowPreferenceFlag_NONE, RenderWindowHotkey::kRenderHotkeyCategory_Visibility),
		RenderWindowHotkey("Place xMarker", "PlaceXMarker", 'O'),
		RenderWindowHotkey("Navmesh: Ignore last picked form", "NavMeshIgnoreLastPick", 'K', RenderWindowHotkey::kRenderWindowPreferenceFlag_Navmesh, RenderWindowHotkey::kRenderHotkeyCategory_Navmesh),
		RenderWindowHotkey("Navmesh: Ignore selected forms", "NavMeshIgnoreSelectedPicks", 'K', RenderWindowHotkey::kRenderWindowPreferenceFlag_Shift, RenderWindowHotkey::kRenderHotkeyCategory_Navmesh),
		RenderWindowHotkey("Toggle show disabled objects", "ToggleShowDisabledObjects", 'N', RenderWindowHotkey::kRenderWindowPreferenceFlag_NONE, RenderWindowHotkey::kRenderHotkeyCategory_Visibility),
		RenderWindowHotkey("Link selected refs", "LinkRefs", 'J'),
		RenderWindowHotkey("Toggle ref persists", "ToggleRefPersists", 'K'),
	};

	void HandleHotkey(UInt32 hotkey)
	{
		switch (hotkey)
		{
		case kHotkey_ToggleShowLightMarkers:
			SetIsShowLightMarkers(!GetIsShowLightMarkers());
			break;

		case kHotkey_PlaceXMarker:
			PlaceXMarker();
			break;

		case kHotkey_SetAllObjectsVisible:
			SetAllObjectsVisible();
			break;

		case kHotkey_NavMeshIgnoreLastPick:
			NavMeshPickPreventer::OnKeyDown(false);
			break;

		case kHotkey_NavMeshIgnoreSelectedPicks:
			NavMeshPickPreventer::OnKeyDown(true);
			break;

		case kHotkey_ToggleShowDisabledObjects:
			ToggleShowDisabledObjects();
			break;

		case kHotkey_LinkRefs:
			LinkSelectedRefs();
			break;
		case kHotkey_ToggleRefPersists:
			ToggleSelectedRefPersists();
			break;
		}
	}

	void __cdecl PopulateList(HWND hDlg)
	{
		auto listView = GetDlgItem(hDlg, 5142);
		for (int i = 0; i < _ARRAYSIZE(CustomHotkeys); ++i)
		{
			CdeclCall(0x41A020, listView, &CustomHotkeys[i], 0, -1); // ListView::InsertItem
		}
	}

	void AddCustomHotkey(RenderWindowHotkey::KeyCombo combo, unsigned int hotkey)
	{
		void* hotkeysNiTMap = (void*)0xE8CF3C;
		ThisCall(0x50D880, hotkeysNiTMap, combo.data, kHotkey_FIRST + hotkey);
	}

	void __cdecl AddKeysToMap()
	{
		for (int i = 0; i < _ARRAYSIZE(CustomHotkeys); ++i)
		{
			AddCustomHotkey(CustomHotkeys[i].kCombo, i);
		}
	}

	RenderWindowHotkey::eKeys __cdecl GetPressedHotkeyID(char aiKeyCode, bool abShift, bool abControl, bool abAlt, bool abIsZ, bool abIsNavMesh)
	{
		auto hotkey = CdeclCall<RenderWindowHotkey::eKeys>(0x412F00, aiKeyCode, abShift, abControl, abAlt, abIsZ, abIsNavMesh);
		if (hotkey > RenderWindowHotkey::kRenderHotkey_COUNT)
		{
			// workaround for the landscape edit hotkey being the same as the toggle lights key by default...
			if (RenderWindow::InLandscapeEditingMode())
			{
				UInt8 pressedFlags = 0;
				if (abShift) pressedFlags |= RenderWindowHotkey::kRenderWindowPreferenceFlag_Shift;
				if (abControl) pressedFlags |= RenderWindowHotkey::kRenderWindowPreferenceFlag_Ctrl;
				if (abAlt) pressedFlags |= RenderWindowHotkey::kRenderWindowPreferenceFlag_Alt;
				if (abIsZ) pressedFlags |= RenderWindowHotkey::kRenderWindowPreferenceFlag_Z;
				if (abIsNavMesh) pressedFlags |= RenderWindowHotkey::kRenderWindowPreferenceFlag_Navmesh;
				auto combo = RenderWindowHotkey::KeyCombo(aiKeyCode, pressedFlags);
				if (hotkey == kHotkey_ToggleShowLightMarkers && (RenderWindowHotkey::GetArray()[RenderWindowHotkey::kRenderHotkey_OpenTextureUseDialog].kCombo.data & ~0x8000) == combo.data)
				{
					return RenderWindowHotkey::kRenderHotkey_OpenTextureUseDialog;
				}
			}

			HandleHotkey(hotkey);
		}
		return hotkey;
	}

	constexpr const char* INI_SECTION = "Render Window";
	char IniPath[MAX_PATH];
	void SetupINIPath()
	{
		GetModuleFileNameA(NULL, IniPath, MAX_PATH);
		strcpy((char*)(strrchr(IniPath, '\\') + 1), "Data\\nvse\\plugins\\GeckExtender\\Hotkeys.ini");
	}

	void ReadINI()
	{
		for (int i = 0; i < _ARRAYSIZE(CustomHotkeys); ++i)
		{
			unsigned short combo = GetPrivateProfileIntA(INI_SECTION, CustomHotkeys[i].sInternalName, 0xFFFF, IniPath);
			if (combo != 0xFFFF)
			{
				CustomHotkeys[i].kCombo.data = combo;
			}
		}
	}

	void SaveINI()
	{
		char buffer[0x10];
		for (int i = 0; i < _ARRAYSIZE(CustomHotkeys); ++i)
		{
			_itoa(CustomHotkeys[i].kCombo.data, buffer, 10);
			WritePrivateProfileStringA(INI_SECTION, CustomHotkeys[i].sInternalName, buffer, IniPath);
		}
	}

	void RestoreDefaults()
	{
		for (int i = 0; i < _ARRAYSIZE(CustomHotkeys); ++i)
		{
			RenderWindowHotkey* hotkey = &CustomHotkeys[i];
			hotkey->kCombo = hotkey->kDefaultCombo;
		}
	}

	void __cdecl OnRestoreDefaults()
	{
		CdeclCall(0x413230);
		RestoreDefaults();
	}

	void __cdecl OnSaveChanges()
	{
		CdeclCall(0x412CE0);
		SaveINI();
	}

	void __cdecl OnCancelChanges()
	{
		CdeclCall(0x4130D0);
		ReadINI();
	}

	void InitHooks()
	{
		// add support for custom render window preferences
		WriteRelJump(0x412D8B, UInt32(PopulateList));
		WriteRelJump(0x412FF0, UInt32(AddKeysToMap));

		WriteRelCall(0x456975, UInt32(GetPressedHotkeyID));

		WriteRelCall(0x4134B5, UInt32(OnRestoreDefaults));
		WriteRelCall(0x4134A6, UInt32(OnSaveChanges));
		WriteRelCall(0x41348A, UInt32(OnCancelChanges));
	}

	void Init()
	{
		InitHooks();
		SetupINIPath();
		ReadINI();
	}
}