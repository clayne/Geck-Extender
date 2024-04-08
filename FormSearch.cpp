#include "GameAPI.h"
#include "GameForms.h"
#include "GameData.h"
#include <CommCtrl.h>
extern HWND g_MainHwnd;

namespace FormSearch
{
    constexpr int IDD_INPUTDIALOG = 101;
    constexpr int IDC_INPUTEDIT = 1001;

    void GetCellCoords(NiPoint3& pos, TESObjectCELL* cell)
    {
        if (cell->IsInterior())
        {
            pos = NiPoint3::ZERO;
        }
        else
        {
            pos.x = 2048 + (cell->GetPosX() << 12);
            pos.y = 2048 + (cell->GetPosY() << 12);
            pos.z = 0;
        }
    }

    bool DoLookupForm(HWND hwndDlg)
    {
        char formName[256];
        GetDlgItemText(hwndDlg, IDC_INPUTEDIT, formName, sizeof(formName));

        if (*formName)
        {
            auto form = GetFormByName(formName);
            if (!form)
            {
                char* endPtr = nullptr;
                if (int formID = strtoul(formName, &endPtr, 16); endPtr && !*endPtr)
                {
                    form = LookupFormByID(formID);
                }
            }

            if (form)
            {
                if (form->typeID == kFormType_Cell || form->typeID == kFormType_Land)
                {
                    TESObjectCELL* cell = form->typeID == kFormType_Land
                        ? (TESObjectCELL*)(UInt32(form) + 0x34) : (TESObjectCELL*)form;

                    NiPoint3 pos;
                    GetCellCoords(pos, cell);
                    CdeclCall(0x465490, &pos, cell);
                    if (!cell->IsInterior())
                    {
                        cell->GetLandHeight(&pos, &pos.z);
                        CdeclCall(0x4652D0, &pos);
                    }
                }
                else
                {
                    (*(void(__thiscall**)(__int32, HWND, __int32, __int32))(*(__int32*)form + 0x164))((__int32)form, g_MainHwnd, 0, 1);
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    WNDPROC originalEditProc;
    LRESULT CALLBACK InputEditSubclassProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        if (msg == WM_KEYDOWN)
        {
            if (wParam == VK_RETURN)
            {
                auto parent = GetParent(hwnd);
                if (DoLookupForm(parent))
                {
                    EndDialog(parent, IDOK);
                    return TRUE;
                }
                return FALSE;
            }
            else if (wParam == VK_ESCAPE)
            {
                EndDialog(GetParent(hwnd), IDCANCEL);
                return TRUE;
            }
            else if (wParam == 'A' && GetKeyState(VK_CONTROL) < 0)
            {
                // Select All
                SendMessage(hwnd, EM_SETSEL, 0, -1);
                return TRUE;
            }
        }
        return CallWindowProc(originalEditProc, hwnd, msg, wParam, lParam);
    }

    BOOL CALLBACK InputDialogProc(HWND hwndDlg, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        if (msg == WM_COMMAND)
        {
            switch (LOWORD(wParam))
            {
            case IDOK:
            {
                if (DoLookupForm(hwndDlg))
                {
                    DestroyWindow(hwndDlg);
                }
                return TRUE;
            }
            case IDCANCEL:
            {
                DestroyWindow(hwndDlg);
                return TRUE;
            }
            }
        }
        return FALSE;
    }

    void ShowInputDialog(HINSTANCE hInstance, HWND hwndParent) {
        // Create the dialog window
        HWND hwndDlg = CreateWindowEx(WS_EX_DLGMODALFRAME,
            WC_DIALOG, "Lookup Form",
            WS_VISIBLE | WS_CAPTION | WS_SYSMENU,
            CW_USEDEFAULT, CW_USEDEFAULT, 200, 100,
            hwndParent, NULL, hInstance, NULL);

        HWND hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
            WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            10, 10, 180, 20,
            hwndDlg, (HMENU)IDC_INPUTEDIT, hInstance, NULL);

        HWND hwndOK = CreateWindowEx(0, "BUTTON", "OK",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
            50, 40, 50, 20,
            hwndDlg, (HMENU)IDOK, hInstance, NULL);

        HWND hwndCancel = CreateWindowEx(0, "BUTTON", "Cancel",
            WS_CHILD | WS_VISIBLE,
            110, 40, 50, 20,
            hwndDlg, (HMENU)IDCANCEL, hInstance, NULL);

        SetWindowLongPtr(hwndDlg, DWLP_DLGPROC, (LONG_PTR)InputDialogProc);
        originalEditProc = (WNDPROC)SetWindowLongPtr(hwndEdit, GWLP_WNDPROC, (LONG_PTR)InputEditSubclassProc);

        // Set focus to the edit control
        SetFocus(hwndEdit);

        // Show the dialog window
        ShowWindow(hwndDlg, SW_SHOW);
    }

    void Show()
    {
        HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(nullptr);
        ShowInputDialog(hInstance, g_MainHwnd);
    }
}