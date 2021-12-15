#pragma once
class Graphic2D
{
public :
	static void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int width, COLORREF rgb);
	static void DrawRectangle(HDC hdc, int left, int top, int right, int bottom, COLORREF rgb);
public :
	Graphic2D();
	~Graphic2D();
};

