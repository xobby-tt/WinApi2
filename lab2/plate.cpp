#include "plate.h" 

#include <math.h> 
#include <stdlib.h> 
#include <random> 

Plate::Plate(int x, int y, int R) {
	this->x = x;
	this->y = y;
	this->R = R;
}

int Plate::GetX() {
	return x;
}

int Plate::GetY() {
	return y;
}

int Plate::IsPointInside(int x, int y) {
	if (pow(x - this->x, 2) + pow(y - this->y, 2) <= R*R) {
		return 1;
	}
	else {
		return 0;
	}
}

void Plate::SetSize(int size) {
	R = size;
}

void Plate::MoveBy(int dx, int dy) {
	x += dx;
	y += dy;
}

void Plate::Draw(HDC hDC) {
	HPEN oldPen = (HPEN)SelectObject(hDC, CreatePen(PS_SOLID, 1, Color));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, CreateSolidBrush(Color));
	Ellipse(hDC, x - R, y - R, x + R + 1, y + R + 1);
	DeleteObject(SelectObject(hDC, oldPen));
	DeleteObject(SelectObject(hDC, oldBrush));
}

void Plate::Erase(HDC hDC) {
	SelectObject(hDC, GetStockObject(WHITE_PEN));
	SelectObject(hDC, GetStockObject(WHITE_BRUSH));
	Ellipse(hDC, x - R, y - R, x + R + 1, y + R + 1);
}
