#pragma once

/*
editable fields
dialogs edited

136
137
138
140
144
145
147
156
165
196
262
264
280
285
286
287
289
302
314
329
342
3219
3227
3229
3237
3239
3244
3246
3247
3251
3262
3266
3267
3268
3271
3272
3277
3278
3282
3286
3288
3290
3327
3352
3353
3354
3368
3369
3374
41512

buggy package dialog 3300, SysListView32 2644

*/


/* TODO
Creature + Leveled creature/character windows
NPC
GameEffects->BaseEffect
Items->Ammo
Items->LeveledItem
Items->Weapon
SpecialEffects->Explosion
WorldObjects->Container

MultiCombo Boxes
0x6017A0
0x49A091
*/

void ResizeFormListWindow(HWND hWnd, WORD newWidth, WORD newHeight)
{
	static const WORD RIGHT_PADDING = 50;
	static const WORD BOTTOM_PADDING = 100;
	static const WORD BUTTON_BOTTOM_PADDING = 30;

	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	RECT idRect;
	HWND idTextField = GetDlgItem(hWnd, 5500);
	GetWindowRect(idTextField, &idRect);
	LONG height = idRect.bottom - idRect.top;
	SetWindowPos(idTextField, NULL, NULL, NULL, newWidth - RIGHT_PADDING, height, SWP_NOMOVE);

	HWND listView = GetDlgItem(hWnd, 2445);
	SetWindowPos(listView, NULL, NULL, NULL, newWidth - RIGHT_PADDING + 20, newHeight - BOTTOM_PADDING, SWP_NOMOVE);

	// move the bottom buttons
	HWND OkButton = GetDlgItem(hWnd, 1);
	HWND CancelButton = GetDlgItem(hWnd, 2);
	HWND LeftArrowButton = GetDlgItem(hWnd, 4008);
	HWND RightArrowButton = GetDlgItem(hWnd, 4009);

	POINT pos;

	pos.x = newWidth / 2 - 90;
	pos.y = newHeight - BUTTON_BOTTOM_PADDING;
	SetWindowPos(OkButton, NULL, pos.x, pos.y, NULL, NULL, SWP_NOSIZE);

	pos.x = newWidth / 2 + 20;
	pos.y = newHeight - BUTTON_BOTTOM_PADDING;
	SetWindowPos(CancelButton, NULL, pos.x, pos.y, NULL, NULL, SWP_NOSIZE);

	pos.x = newWidth / 2 - 30;
	pos.y = newHeight - BUTTON_BOTTOM_PADDING - 25;
	SetWindowPos(LeftArrowButton, NULL, pos.x, pos.y, NULL, NULL, SWP_NOSIZE);

	pos.x = newWidth / 2 + 10;
	pos.y = newHeight - BUTTON_BOTTOM_PADDING - 25;
	SetWindowPos(RightArrowButton, NULL, pos.x, pos.y, NULL, NULL, SWP_NOSIZE);

	InvalidateRect(hWnd, &clientRect, true);
}

// FormList dialog (3274)
BOOL CALLBACK FormListCallback(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_SIZE)
	{
		// the callback is shared, only filter for the FormList dialog (classname is AlchemyClass)
		char className[256];
		if (GetClassNameA(hDlg, className, ARRAYSIZE(className)) > 0)
		{
			if (!strcmp(className, "AlchemyClass"))
			{
				WORD width = LOWORD(lParam);
				WORD height = HIWORD(lParam);
				ResizeFormListWindow(hDlg, width, height);
			}
		}
		else
		{
			return true;
		}
	}
	return CallWindowProc((WNDPROC)0x480110, hDlg, msg, wParam, lParam);
}

void ResizeObjectPalette(HWND hWnd, WORD newWidth, WORD newHeight)
{
	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	HWND listView = GetDlgItem(hWnd, 1018);
	SetWindowPos(listView, NULL, NULL, NULL, 200, newHeight - 90, SWP_NOMOVE);

	// move the bottom buttons
	HWND NewButton = GetDlgItem(hWnd, 1124);
	HWND LoadButton = GetDlgItem(hWnd, 5097);
	HWND SaveButton = GetDlgItem(hWnd, 1000);
	HWND SaveAsButton = GetDlgItem(hWnd, 1986);
	HWND MergeButton = GetDlgItem(hWnd, 1988);

	SetWindowPos(NewButton, NULL, 8, newHeight - 42, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(LoadButton, NULL, 78, newHeight - 30, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(SaveButton, NULL, 78, newHeight - 55, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(SaveAsButton, NULL, 148, newHeight - 55, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(MergeButton, NULL, 148, newHeight - 30, NULL, NULL, SWP_NOSIZE);

	InvalidateRect(hWnd, &clientRect, true);
}

// objects palette window (375)
BOOL CALLBACK ObjectPaletteCallback(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_SIZE)
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		ResizeObjectPalette(hDlg, width, height);
	}
	return CallWindowProc((WNDPROC)0x40D190, hDlg, msg, wParam, lParam);
}

#define USE_REPORT_USED_IN_THESE_CELLS_TEXT_ID 1102
void ResizeUseReportWindow(HWND hWnd, WORD newWidth, WORD newHeight)
{
	static const WORD LEFT_PADDING = 10;
	static const WORD RIGHT_PADDING = 40;
	static const WORD BOTTOM_PADDING = 100;
	static const WORD BUTTON_BOTTOM_PADDING = 30;
	static const WORD INTER_LIST_PADDING = 40;
	static const WORD BUTTON_SIZE = 39;

	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	int List1Height = newHeight / 2 - INTER_LIST_PADDING;
	int List1Width = newWidth - RIGHT_PADDING + 20;
	HWND listView1 = GetDlgItem(hWnd, 1637);
	SetWindowPos(listView1, NULL, NULL, NULL, List1Width, List1Height, SWP_NOMOVE);

	HWND UsedInTheseCellsText = GetDlgItem(hWnd, USE_REPORT_USED_IN_THESE_CELLS_TEXT_ID);
	SetWindowPos(UsedInTheseCellsText, NULL, LEFT_PADDING, newHeight / 2, NULL, NULL, SWP_NOSIZE);

	HWND listView2 = GetDlgItem(hWnd, 1638);
	SetWindowPos(listView2, NULL, LEFT_PADDING, List1Height + 1.5 * INTER_LIST_PADDING, newWidth - RIGHT_PADDING + 20, (newHeight / 2) - 60, NULL);

	// move the bottom buttons
	HWND OkButton = GetDlgItem(hWnd, 1);
	POINT newButtonPos;
	newButtonPos.x = newWidth / 2 - BUTTON_SIZE;
	newButtonPos.y = newHeight - BUTTON_BOTTOM_PADDING;

	SetWindowPos(OkButton, NULL, newButtonPos.x, newButtonPos.y, NULL, NULL, SWP_NOSIZE);

	InvalidateRect(hWnd, &clientRect, true);
}

// Use Report window (220)
BOOL CALLBACK UseReportCallback(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_SIZE)
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		ResizeUseReportWindow(hDlg, width, height);
	}
	return CallWindowProc((WNDPROC)0x468860, hDlg, msg, wParam, lParam);
}

UInt32 originalBGSListFormDialogFn;
char __fastcall BGSListForm__DialogCallback(BGSListForm* listForm, void* edx, HWND hDlg, int msg, unsigned int wParam, int lParam, UInt32* a6)
{
	if (msg == WM_SIZE)
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		ResizeFormListWindow(hDlg, width, height);
	}
	return ThisCall<char>(originalBGSListFormDialogFn, listForm, hDlg, msg, wParam, lParam, a6);
}

void ResizeDialogueWindow(HWND hWnd, WORD newWidth, WORD newHeight)
{
	constexpr int TOPIC_EDITOR = 151;
	constexpr int DIALOGUE_TREE = 347;
	if (auto xSubWindow = (DialogExtraSubWindow*)Window_GetExtraData(hWnd, kMenuExtra_DialogExtraSubWindow))
	{
		if (xSubWindow->subWindow)
		{
			auto dialogWindow = xSubWindow->subWindow->dialogWindow;

			if (xSubWindow->menuID == TOPIC_EDITOR)
			{
				static const WORD LIST_VIEW_OFFSET = 200;
				static const WORD LIST_VIEW_WIDTH = 195;
				auto leftListView = GetDlgItem(hWnd, 2064);
				SetWindowPos(leftListView, NULL, NULL, NULL, LIST_VIEW_WIDTH, newHeight - LIST_VIEW_OFFSET, SWP_NOMOVE);

				auto topicListView = GetDlgItem(hWnd, 1448);
				SetWindowPos(topicListView, NULL, NULL, NULL, LIST_VIEW_WIDTH + 2, newHeight - 73, SWP_NOMOVE);

				// TODO - handle resizing the rest of the controls
			}
			else if (xSubWindow->menuID == DIALOGUE_TREE)
			{
			}
		}

		RECT clientRect;
		GetClientRect(hWnd, &clientRect);
		InvalidateRect(hWnd, &clientRect, true);
	}
}

BOOL CALLBACK DialogueWindowCallback(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_SIZE)
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		ResizeDialogueWindow(hDlg, width, height);
		// TODO - the menu needs to resize when switching tabs too...
	}
	return CallWindowProc((WNDPROC)0x57FA00, hDlg, msg, wParam, lParam);
}



/* Load ESP/ESM Dialogs

List1 1056
Set as Active File 1121 -
Details 1185 -
"Created by" Edit 1025
"Summary" Edit 1024
"Parent Master" Edit 1057
OK Button 1 -
Cancel Button 2 -
TES Files 1101
Created By 1102
Summary 1103
Parent Masters 1104
Created On 1105
Last Modified 1106
"Created On" Date 1026 -
"Created On" Time 1027 -
File Version 2406
Current 2407
"File Version" 1681
"Current" 1682
"Last Modified" Date 1028 -
"Last Modified" Time 1029 -
*/

void ResizeLoadEspEsmWindow(HWND hWnd, WORD newWidth, WORD newHeight)
{
	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	HWND listView = GetDlgItem(hWnd, 1056);
	SetWindowPos(listView, NULL, NULL, NULL, 531, newHeight - 80, SWP_NOMOVE);

	// move the bottom buttons
	HWND SetActiveFileButton = GetDlgItem(hWnd, 1121);
	HWND DetailsButton = GetDlgItem(hWnd, 1185);
	HWND OkButton = GetDlgItem(hWnd, 1);
	HWND CancelButton = GetDlgItem(hWnd, 2);

	int newButtonHeight = newHeight - 38;
	SetWindowPos(SetActiveFileButton, NULL, 11, newButtonHeight, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(DetailsButton, NULL, 151, newButtonHeight, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(OkButton, NULL, newWidth - 189, newButtonHeight - 5, NULL, NULL, SWP_NOSIZE);
	SetWindowPos(CancelButton, NULL, newWidth - 109, newButtonHeight - 5, NULL, NULL, SWP_NOSIZE);

	InvalidateRect(hWnd, &clientRect, true);
}

void ResizeGlobalsWindow(HWND hWnd, WORD newWidth, WORD newHeight)
{
	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	static const WORD LIST_VIEW_OFFSET = 22;
	static const WORD LIST_VIEW_WIDTH = 477;
	auto listView = GetDlgItem(hWnd, 2064);
	SetWindowPos(listView, NULL, NULL, NULL, LIST_VIEW_WIDTH, newHeight - LIST_VIEW_OFFSET, SWP_NOMOVE);

	InvalidateRect(hWnd, &clientRect, true);
}

void ResizeGamesettingsWindow(HWND hWnd, WORD newWidth, WORD newHeight)
{
	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	static const WORD LIST_VIEW_OFFSET = 40;
	static const WORD LIST_VIEW_WIDTH = 612;
	auto listView = GetDlgItem(hWnd, 2064);
	SetWindowPos(listView, NULL, NULL, NULL, LIST_VIEW_WIDTH, newHeight - LIST_VIEW_OFFSET, SWP_NOMOVE);

	InvalidateRect(hWnd, &clientRect, true);
}

BOOL CALLBACK GlobalsWindowCallback(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_SIZE)
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		ResizeGlobalsWindow(hDlg, width, height);
	}
	return CallWindowProc((WNDPROC)0x480B70, hDlg, msg, wParam, lParam);
}

BOOL CALLBACK GamesettingsWindowCallback(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_SIZE)
	{
		WORD width = LOWORD(lParam);
		WORD height = HIWORD(lParam);
		ResizeGamesettingsWindow(hDlg, width, height);
	}
	return CallWindowProc((WNDPROC)0x480B70, hDlg, msg, wParam, lParam);
}
