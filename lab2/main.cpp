#include <windows.h>
#include "ServeWindow.h"
#include "Plates.h"

#define idPlate 1001
#define idFork 1002
#define idSpoon 1003
#define idGlass 1004
#define idNapkin 1005
#define idTitle 1006

HINSTANCE hInst;

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wPatam, LPARAM lParam);
LRESULT CALLBACK PlatesWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void platesClick(HWND);
void forksClick(HWND);
void spoonsClick(HWND);
void glassesClick(HWND);
void napkinsClick(HWND);

void destroyMenu();

HWND plates;
HWND forks;
HWND spoons;
HWND glasses;
HWND napkins;

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nWinMode) {
	WNDCLASS wcl;
	wcl.hInstance = hThisInst;
	wcl.lpszClassName = L"MainWindowClass";
	wcl.lpfnWndProc = MainWindowProc;
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpszMenuName = NULL;
	wcl.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)(1+COLOR_WINDOW);
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;

	if (!RegisterClass(&wcl))
		return 0;

	HWND hWnd;
	hWnd = CreateWindow(L"MainWindowClass", L"Api", WS_OVERLAPPEDWINDOW,
		500, 250, 900, 600, HWND_DESKTOP, NULL, hThisInst, NULL);
	ShowWindow(hWnd, nWinMode);
	

	RegisterServeWindow();
	CreateWindow(L"ServeWindowClass", L"", WS_CHILD | WS_VISIBLE,
		0, 0, 600, 600, hWnd, NULL, hThisInst, NULL);

	plates = CreateWindow(L"BUTTON", L"Plate", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_BORDER, 700, 40, 100, 90, hWnd, (HMENU)idPlate, hThisInst, NULL);
	forks = CreateWindow(L"BUTTON", L"Fork", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_BORDER, 700, 140, 100, 90, hWnd, (HMENU)idFork, hThisInst, NULL);
	spoons = CreateWindow(L"BUTTON", L"Spoon", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_BORDER, 700, 240, 100, 90, hWnd, (HMENU)idSpoon, hThisInst, NULL);
	glasses = CreateWindow(L"BUTTON", L"Glass", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_BORDER, 700, 340, 100, 90, hWnd, (HMENU)idGlass, hThisInst, NULL);
	napkins = CreateWindow(L"BUTTON", L"Napkin", WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON| WS_BORDER, 700, 440, 100, 90, hWnd, (HMENU)idNapkin, hThisInst, NULL);

	HFONT hFontText = CreateFont(30, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, NULL);
	SendDlgItemMessage(hWnd, idPlate, WM_SETFONT, WPARAM(hFontText), TRUE);
	SendDlgItemMessage(hWnd, idFork, WM_SETFONT, WPARAM(hFontText), TRUE);
	SendDlgItemMessage(hWnd, idSpoon, WM_SETFONT, WPARAM(hFontText), TRUE);
	SendDlgItemMessage(hWnd, idGlass, WM_SETFONT, WPARAM(hFontText), TRUE);
	SendDlgItemMessage(hWnd, idNapkin, WM_SETFONT, WPARAM(hFontText), TRUE);
	UpdateWindow(hWnd);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND: {
		if (HIWORD(wParam) == BN_CLICKED) {
			boolean btnClicked = false;
			int id = 0;
			for (int j = 1001; j <= 1006; j++)
			{
				btnClicked = IsDlgButtonChecked(hWnd, j);
				if (btnClicked) {
					id = j;
					break;
				}
			}
			switch (LOWORD(wParam))
			{
			case idPlate: {
				//platesClick(hWnd);
				break;
			}
			default:
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
		}
	}

	default: 
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}


void platesClick(HWND hWnd) {


	CreateWindow(L"Plates", L"", WS_CHILD | WS_VISIBLE,
		600, 0, 300, 600, hWnd, NULL, hInst, NULL);

}
