#pragma once
#include <windows.h>

int RegisterServeWindow();

LRESULT CALLBACK ServeWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
/*
// структура для анализа параметров сообщений манипулятора "мышь" 
typedef struct {
	int xPos,           // координаты указателя мыши 
		yPos;
	int lButtonPressed, // состояние кнопок мыши 
		rButtonPressed,
		mButtonPressed;
	int shiftPressed,   // состояние клавиш регистра 
		controlPressed;
} MouseState;

// функция для анализа параметров сообщений манипулятора "мышь" 
void ExtractMouseParams(WPARAM wParam, LPARAM lParam, MouseState * ms);
*/