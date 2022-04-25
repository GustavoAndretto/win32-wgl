#pragma once
#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif // !NOMINMAX
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // !WIN32_LEAN_AND_MEAN
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif // !VC_EXTRALEAN
#ifndef UNICODE
#define UNICODE
#endif
#include <Windows.h>
#include "WinExtendedDefs.hpp"
#endif // !_WIN32

INT WINAPI ImplExecute(void);

BOOL WINAPI ImplRegisterClass(void);

void WINAPI ImplUnregisterClass(void);

BOOL WINAPI ImplCreateWindow(HWND& hWnd);

void WINAPI ImplDestroyWindow(HWND hWnd);

void WINAPI ImplResizeWindow(HWND hWnd, INT width, INT height);

void WINAPI ImplMoveWindow(HWND hWnd, INT x, INT y);

void WINAPI ImplSetWindowText(HWND hWnd, LPCWSTR text);

void WINAPI ImplSetWindowText(HWND hWnd, LPCSTR text);

void WINAPI ImplRequestCloseWindow(HWND hWnd);

void WINAPI ImplDestroyWindow(HWND hWnd);

void WINAPI ImplShowWindow(HWND hWnd);

void WINAPI ImplHideWindow(HWND hWnd);

void WINAPI ImplMinimizeWindow(HWND hWnd);

void WINAPI ImplMaximizeWindow(HWND hWnd);

void WINAPI ImplRestoreWindow(HWND hWnd);

void WINAPI ImplUpdateWindow(HWND hWnd);

void WINAPI ImplSetProp(HWND hWnd, HANDLE handle);

HANDLE WINAPI ImplGetProp(HWND hWnd);

void WINAPI ImplRemoveProp(HWND hWnd);

void WINAPI ImplEnableSystemMenu(HWND hWnd);

void WINAPI ImplDisableSystemMenu(HWND hWnd);

void WINAPI ImplEnableCaption(HWND hWnd);

void WINAPI ImplDisableCaption(HWND hWnd);

void WINAPI ImplEnableCloseButton(HWND hWnd);

void WINAPI ImplDisableCloseButton(HWND hWnd);

void WINAPI ImplEnableMinimizeButton(HWND hWnd);

void WINAPI ImplDisableMinimizeButton(HWND hWnd);

void WINAPI ImplEnableMaximizeButton(HWND hWnd);

void WINAPI ImplDisableMaximizeButton(HWND hWnd);

void WINAPI ImplEnableResize(HWND hWnd);

void WINAPI ImplDisableResize(HWND hWnd);