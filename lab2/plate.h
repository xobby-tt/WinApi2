#pragma once

#include <windows.h> 

#include <vector> 
using namespace std;

class Plate {
private:
	int x, y;
	int R;
	const int Color = COLOR_GRAYTEXT;
public:
	Plate(int x, int y, int R);
	int GetX();
	int GetY();
	int IsPointInside(int x, int y);
	void SetSize(int size);
	void MoveBy(int dx, int dy);
	void Draw(HDC hDC);
	void Erase(HDC hDC);
};
