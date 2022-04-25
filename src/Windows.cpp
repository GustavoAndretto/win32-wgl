#include "Windows.hpp"
#include "WindowHandler.hpp"

#include <string>
#include <memory>

std::wstring string_to_wstring(const std::string& text)
{
	if (!text.empty())
	{
		// Get size
		INT bSize = MultiByteToWideChar(
			CP_UTF8,
			0,
			text.c_str(),
			static_cast<INT>(text.size()),
			NULL,
			0);

		std::unique_ptr<WCHAR[]> bString(new WCHAR[bSize]);

		// Convert
		MultiByteToWideChar(
			CP_UTF8,
			0,
			text.c_str(),
			-1,
			bString.get(),
			bSize);

		return std::wstring(bString.get(), bSize);
	}

	return std::wstring();
}

static BOOL G_ClassRegistered = FALSE;

const WCHAR* GetRegisterClassName() 
{
	return L"_WindowContextW_";
}

const WCHAR* GetWndPropName() 
{
	return L"_WindowPropW_";
}

INT TranslateKey(WPARAM wParam)
{
	return static_cast<INT>(wParam);
}

INT TranslateMouseKey(UINT uMsg, WPARAM wParam)
{
	enum : INT { MouseLeftKey = 1, MouseRightKey = 2, MouseMiddleKey = 3 };

	switch(uMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
		return MouseLeftKey;
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
		return MouseRightKey;
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
		return MouseMiddleKey;
	case WM_XBUTTONDOWN:
	case WM_XBUTTONUP:
		return MouseMiddleKey + GET_XBUTTON_WPARAM(wParam);
	}

	return 0;
}

INT GetMouseKeyState(UINT uMsg)
{
	enum : INT { MouseKeyRelease, MouseKeyPress };

	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_XBUTTONDOWN:
		return MouseKeyPress;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	case WM_XBUTTONUP:
		return MouseKeyRelease;
	}

	return 0;
}

INT GetKeyToggleState(INT key)
{
	if ((GetKeyState(VK_SCROLL) & 0x0001) != 0)
	{
		return VK_KEY_TOGGLE;
	}

	return VK_KEY_UNTOGGLE;
}

INT GetKeyState(WPARAM wParam, LPARAM lParam)
{
	INT state = 0;
	INT pressState = static_cast<INT>(lParam >> 0x1E);

	switch (wParam)
	{
	case VK_SCROLL:
		{
			state |= GetKeyToggleState(VK_SCROLL);
		}
		break;
	case VK_NUMLOCK:
		{
			state |= GetKeyToggleState(VK_NUMLOCK);
		}
		break;
	case VK_CAPITAL:
		{
			state |= GetKeyToggleState(VK_CAPITAL);
		}
	}

	switch (pressState)
	{
	case WM_KEY_PRESS:
		state |= VK_KEY_PRESS;
		break;
	case WM_KEY_REPEAT:
		state |= VK_KEY_REPEAT;
		break;
	case WM_KEY_RELEASE:
		state |= VK_KEY_RELEASE;
	}

	return state;
}

INT GetKeyMods()
{
	INT mods = 0;

	if (GetKeyState(VK_LSHIFT) & 0x8000)
	{
		//combo |= VK_MOD_LSHIFT;
	}
	else if (GetKeyState(VK_RSHIFT) & 0x8000)
	{
		//combo |= VK_MOD_RSHIFT;
	}

	if (GetKeyState(VK_LCONTROL) & 0x8000)
	{
		//combo |= VK_MOD_LCONTROL;
	}
	else if (GetKeyState(VK_RCONTROL) & 0x8000)
	{
		//combo |= VK_MOD_RCONTROL;
	}

	if (GetKeyState(VK_LMENU) & 0x8000)
	{
		//combo |= VK_MOD_LALTERNATE;
	}
	else if (GetKeyState(VK_RMENU) & 0x8000)
	{
		//combo |= VK_MOD_RALTERNATE;
	}

	if (GetKeyState(VK_LWIN) & 0x8000)
	{
		//combo |= VK_MOD_LSUPER;
	}
	else if (GetKeyState(VK_RWIN) & 0x8000)
	{
		//combo |= VK_MOD_RSUPER;
	}

	return mods;
}

INT GetScancode(LPARAM lParam)
{
	return static_cast<INT>(lParam >> 0x10) & 0x1ff;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	WindowHandler windowHandler(static_cast<Window*>(ImplGetProp(hWnd)));

	switch (uMsg)
	{
	case WM_PAINT:
		{
			PAINTSTRUCT ps;
			windowHandler.draw();
			BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
	case WM_XBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
	case WM_XBUTTONUP:
		{
			INT key = TranslateMouseKey(uMsg, wParam);
			INT state = GetMouseKeyState(uMsg);
			INT mods = GetKeyMods();

			windowHandler.mouseKeyEvent(key, state, mods);
		}
		break;
	case WM_MOUSELEAVE:
		{
			windowHandler.trackMouse(false);
			windowHandler.mouseLeaveEvent();
		}
		break;
	case WM_MOUSEMOVE:
		{
			int x = LOWORD(lParam);
			int y = HIWORD(lParam);

			windowHandler.mouseMoveEvent(x, y);

			if (!windowHandler.mouseTracked())
			{
				TRACKMOUSEEVENT tme;
				ZeroMemory(&tme, sizeof(TRACKMOUSEEVENT));
				tme.cbSize = sizeof(TRACKMOUSEEVENT);
				tme.dwFlags = TME_LEAVE;
				tme.hwndTrack = hWnd;
				TrackMouseEvent(&tme);

				windowHandler.trackMouse(true);
				windowHandler.mouseEnterEvent();
			}
		}
		break;
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
		{
			INT key = TranslateKey(wParam);
			INT state = GetKeyState(wParam, lParam);
			INT mods = GetKeyMods();
			INT scancode = GetScancode(lParam);

			windowHandler.keyEvent(key, state, mods, scancode);
		}
		break;
	case WM_MOVE:
		{
			windowHandler.moveEvent(LOWORD(lParam), HIWORD(lParam));
		}
		break;
	case WM_SIZE:
		{
			if (wParam == SIZE_MINIMIZED)
			{
				windowHandler.minimizeEvent();
			}
			else if (wParam == SIZE_MAXIMIZED)
			{
				windowHandler.maximizeEvent();
			}
			else if (wParam == SIZE_RESTORED)
			{
				windowHandler.restoreEvent();
			}

			windowHandler.resizeEvent(LOWORD(lParam), HIWORD(lParam));
		}
		break;
	case WM_CLOSE:
		{
			windowHandler.closeEvent();
		}
		break;
	case WM_DESTROY:
		{
			PostQuitMessage(EXIT_SUCCESS);
		}
	default: 
		return DefWindowProcW(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

INT WINAPI ImplExecute(void)
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (GetMessageW(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return static_cast<INT>(msg.wParam);
}


BOOL WINAPI ImplRegisterClass(void)
{
	if (G_ClassRegistered == FALSE)
	{
		WNDCLASSEXW wcex;
		ZeroMemory(&wcex, sizeof(WNDCLASSEXW));

		wcex.cbSize = sizeof(WNDCLASSEXW);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.hInstance = GetModuleHandleW(NULL);
		wcex.lpszClassName = GetRegisterClassName();
		wcex.hCursor = LoadCursorW(NULL, static_cast<LPCWSTR>(IDC_ARROW));
		wcex.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
		wcex.lpfnWndProc = WndProc;

		if (RegisterClassExW(&wcex) == NULL)
		{
			return FALSE;
		}

		G_ClassRegistered = TRUE;
	}

	return TRUE;
}

void WINAPI ImplUnregisterClass(void)
{
	if (G_ClassRegistered == TRUE)
	{
		UnregisterClassW(GetRegisterClassName(), GetModuleHandle(NULL));

		G_ClassRegistered = FALSE;
	}
}

BOOL WINAPI ImplCreateWindow(HWND& hWnd)
{

	//WS_EX_APPWINDOW

	hWnd = CreateWindowExW(
		WS_EX_APPWINDOW,
		GetRegisterClassName(),
		GetRegisterClassName(),
		0,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		NULL,
		NULL);

	if (hWnd == NULL)
	{
		return FALSE;
	}

	ImplDisableCaption(hWnd);

	return TRUE;
}

void WINAPI ImplDestroyWindow(HWND hWnd)
{
	DestroyWindow(hWnd);
}

void WINAPI ImplResizeWindow(HWND hWnd, INT width, INT height)
{
	SetWindowPos(hWnd, 0, 0, 0, width, height, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
}

void WINAPI ImplMoveWindow(HWND hWnd, INT x, INT y)
{
	RECT rect{ x, y, x, y };
	AdjustWindowRectEx(&rect, WS_THICKFRAME, FALSE, WS_EX_APPWINDOW);
	SetWindowPos(hWnd, NULL, rect.left, rect.top, 0, 0, SWP_NOACTIVATE | SWP_NOSIZE | SWP_NOZORDER);
}

void WINAPI ImplSetWindowText(HWND hWnd, LPCWSTR text)
{
	SetWindowTextW(hWnd, text);
}

void WINAPI ImplSetWindowText(HWND hWnd, LPCSTR text)
{
	ImplSetWindowText(hWnd, string_to_wstring(text).c_str());
}

void WINAPI ImplRequestCloseWindow(HWND hWnd)
{
	CloseWindow(hWnd);
}

void WINAPI ImplShowWindow(HWND hWnd)
{
	ShowWindow(hWnd, SW_SHOW);
}

void WINAPI ImplHideWindow(HWND hWnd)
{
	ShowWindow(hWnd, SW_HIDE);
}

void WINAPI ImplMinimizeWindow(HWND hWnd)
{
	ShowWindow(hWnd, SW_MINIMIZE);
}

void WINAPI ImplMaximizeWindow(HWND hWnd)
{
	ShowWindow(hWnd, SW_MAXIMIZE);
}

void WINAPI ImplRestoreWindow(HWND hWnd)
{
	ShowWindow(hWnd, SW_RESTORE);
}

void WINAPI ImplUpdateWindow(HWND hWnd)
{
	UpdateWindow(hWnd);
}

void WINAPI ImplSetProp(HWND hWnd, HANDLE handle)
{
	SetPropW(hWnd, GetWndPropName(), handle);
}

HANDLE WINAPI ImplGetProp(HWND hWnd)
{
	return GetPropW(hWnd, GetWndPropName());
}

void WINAPI ImplRemoveProp(HWND hWnd)
{
	RemovePropW(hWnd, GetWndPropName());
}

void WINAPI ImplEnableSystemMenu(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) | WS_SYSMENU);
}

void WINAPI ImplDisableSystemMenu(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) & ~WS_SYSMENU);
}

void WINAPI ImplEnableCaption(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) | WS_CAPTION | WS_EX_TOOLWINDOW);
}

void WINAPI ImplDisableCaption(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) & ~WS_CAPTION);
}

void WINAPI ImplEnableCloseButton(HWND hWnd)
{
	EnableMenuItem(GetSystemMenu(hWnd, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
}

void WINAPI ImplDisableCloseButton(HWND hWnd)
{
	EnableMenuItem(GetSystemMenu(hWnd, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
}

void WINAPI ImplEnableMinimizeButton(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) | WS_MINIMIZEBOX);
}

void WINAPI ImplDisableMinimizeButton(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
}

void WINAPI ImplEnableMaximizeButton(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) | WS_MAXIMIZEBOX);
}

void WINAPI ImplDisableMaximizeButton(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
}

void WINAPI ImplEnableResize(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) | WS_THICKFRAME);
}

void WINAPI ImplDisableResize(HWND hWnd)
{
	SetWindowLongW(hWnd, GWL_STYLE, GetWindowLongW(hWnd, GWL_STYLE) & ~WS_THICKFRAME);
}