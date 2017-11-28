#include "ServeWindow.h"

int RegisterServeWindow() {
	WNDCLASS wcl;
	wcl.hInstance = GetModuleHandle(NULL);
	wcl.lpszClassName = L"ServeWindowClass";
	wcl.lpfnWndProc = ServeWindowProc;
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpszMenuName = NULL;
	wcl.hIcon = NULL;
	wcl.hCursor = LoadCursor(NULL, IDC_CROSS);
	wcl.hbrBackground = (HBRUSH)(1 + COLOR_WINDOW);
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	return RegisterClass(&wcl);
}

LRESULT CALLBACK ServeWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hDC = BeginPaint(hWnd, &ps); // �������� �������� ����������
		SelectObject(hDC, GetStockObject(BLACK_PEN));
		SelectObject(hDC, GetStockObject(WHITE_BRUSH));
		Rectangle(hDC, 0, 0, 600, 600);
		EndPaint(hWnd, &ps); // ���������� �������� ����������
		break;
	}
	case WM_LBUTTONDOWN: // ������� ����� ������ ������������ "����"
						 // ������� ������ � �������� ������ ��� ������
	{
		LastHole = new HOLE(ms.xPos, ms.yPos, 5); // ������� ����� ������-���������,
		Plate.AddHole(LastHole); // ��������� ��� �� ��������
		LastHole->Draw(GetWindowDC(hWnd)); // � ����� �� ������
		Mode = CHANGE_SIZE; // ��������� � ����� ��������� ������� �������
		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

