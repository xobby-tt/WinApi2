#pragma once
#include <windows.h>

int RegisterPlatesWindow();

LRESULT CALLBACK PlatesWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);