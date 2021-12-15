#include "framework.h"
#include "Graphic2D.h"

// 생성자/ 소멸자
Graphic2D::Graphic2D()
{
}

Graphic2D::~Graphic2D()
{
}


// DrawLine 
// 1. MyPen, OldPen 을 생성한다.
// 2. CreatePen 으로 색상 등록
// 3. SelectObject()로 Mypen을 등록시킨다
// 4. Drawing
// 5. 다시 반환한다.
void Graphic2D::DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int width, COLORREF rgb)
{
	HPEN MyPen, OldPen;

	// PS_SOLID : 선이 꽉참
	MyPen = CreatePen(PS_SOLID, width, rgb);

	OldPen = static_cast<HPEN>(SelectObject(hdc, MyPen));

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);

	static_cast<HPEN>(SelectObject(hdc, OldPen));
}

void Graphic2D::DrawRectangle(HDC hdc, int left, int top, int right, int bottom, COLORREF rgb)
{
	Rectangle(hdc, left, top, right, bottom);
}

