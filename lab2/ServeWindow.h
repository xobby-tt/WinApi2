#pragma once
#include <windows.h>

int RegisterServeWindow();

LRESULT CALLBACK ServeWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
/*
// ��������� ��� ������� ���������� ��������� ������������ "����" 
typedef struct {
	int xPos,           // ���������� ��������� ���� 
		yPos;
	int lButtonPressed, // ��������� ������ ���� 
		rButtonPressed,
		mButtonPressed;
	int shiftPressed,   // ��������� ������ �������� 
		controlPressed;
} MouseState;

// ������� ��� ������� ���������� ��������� ������������ "����" 
void ExtractMouseParams(WPARAM wParam, LPARAM lParam, MouseState * ms);
*/