#include <windows.h>
#include "ServeWindow.h"
#include "Plates.h"

#define idPlates 1001
#define idForks 1002
#define idSpoons 1003
#define idGlasses 1004
#define idNapkins 1005
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
	wcl.hbrBackground = (HBRUSH)(1 + COLOR_WINDOW);
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;

	if (!RegisterClass(&wcl))
		return 0;

	HWND hWnd;
	hWnd = CreateWindow(L"MainWindowClass", L"Api", WS_OVERLAPPEDWINDOW,
		500, 250, 900, 600, HWND_DESKTOP, NULL, hThisInst, NULL);
	ShowWindow(hWnd, nWinMode);
	UpdateWindow(hWnd);

	RegisterServeWindow();
	CreateWindow(L"ServeWindowClass", L"", WS_CHILD | WS_VISIBLE,
		0, 0, 600, 600, hWnd, NULL, hThisInst, NULL);

	RegisterPlatesWindow();

	plates = CreateWindow(L"BUTTON", L"Plates", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 700, 40, 100, 90, hWnd, (HMENU)idPlates, hThisInst, NULL);
	forks = CreateWindow(L"BUTTON", L"Forks", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 700, 140, 100, 90, hWnd, (HMENU)idForks, hThisInst, NULL);
	spoons = CreateWindow(L"BUTTON", L"Spoons", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 700, 240, 100, 90, hWnd, (HMENU)idSpoons, hThisInst, NULL);
	glasses = CreateWindow(L"BUTTON", L"Glasses", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 700, 340, 100, 90, hWnd, (HMENU)idGlasses, hThisInst, NULL);
	napkins = CreateWindow(L"BUTTON", L"Napkins", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 700, 440, 100, 90, hWnd, (HMENU)idNapkins, hThisInst, NULL);

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
		if (HIWORD(wParam) == BN_CLICKED)
			switch (LOWORD(wParam))
			{
			case idPlates: {
				platesClick(hWnd);
				break;
			}
			default:
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			}
	}

	default: 
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

void destroyMenu() {
	SendMessage(plates, WM_CLOSE, 0, 0);
	SendMessage(forks, WM_CLOSE, 0, 0);
	SendMessage(spoons, WM_CLOSE, 0, 0);
	SendMessage(glasses, WM_CLOSE, 0, 0);
	SendMessage(napkins, WM_CLOSE, 0, 0);
}

void platesClick(HWND hWnd) {

	destroyMenu();

	CreateWindow(L"Plates", L"", WS_CHILD | WS_VISIBLE,
		600, 0, 300, 600, hWnd, NULL, hInst, NULL);

}
