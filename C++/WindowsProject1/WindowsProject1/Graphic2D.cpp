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
// 2. SelectObject()로 Mypen을 등록시킨다
// 3. Drawing
// 4. 다시 원래대로 반환한다.
// 5. 생성되었던 Obejct를 지운다.
void Graphic2D::DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int width, COLORREF rgb)
{
	HPEN MyPen;		// 내가 사용하고자 하는 Pen
	HPEN OldPen;	// 기존에 사용되었던 Pen

	// PS_SOLID : 실선
	// 1. 그리고자 하는 Object 생성 (Pen, Brush, Bitmap)
	MyPen = CreatePen(PS_SOLID, width, rgb);
	
	// 2. Object 등록하고 기존에 사용되었던 Pen 정보를 OldPen에 저장
	OldPen = static_cast<HPEN>(SelectObject(hdc, MyPen));

	// 3. Drawing
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);

	// 4. OldPen으로 복귀 시킨다.
	SelectObject(hdc, OldPen);

	// 5. 생성되었던 MyPen을 Delete한다.
	DeleteObject(MyPen);
}

// DrawRectangle
// 1. MyBrush, OldBrush 을 생성한다.
// 2. SelectObject()로 MyBrush를 등록시킨다
// 3. Drawing
// 4. 다시 원래대로 반환한다.
// 5. 생성되었던 Object를 지운다.
void Graphic2D::DrawRectangle(HDC hdc, int left, int top, int right, int bottom, COLORREF rgb)
{
	HBRUSH MyBrush;		// 내가 사용하고자 하는 Brush
	HBRUSH OldBrush;	// 기존에 사용되었던 Brush

	// 1. 그리고자 하는 Object 생성 (Pen, Brush, Bitmap)
	MyBrush = CreateSolidBrush(rgb);

	// 2. Object 등록하고 기존에 사용되었던 Pen 정보를 OldPen에 저장
	OldBrush = static_cast<HBRUSH>(SelectObject(hdc, MyBrush));

	// 3. Drawing
	Rectangle(hdc, left, top, right, bottom);

	// 4. OldBrush로 복귀시킨다.
	SelectObject(hdc, OldBrush);

	// 5. 생성되었던 MyBrush를 지운다.
	DeleteObject(MyBrush);
}

// 1. Myfont를 생성
// 2. Myfont를 사용하게 하고, 그 전에 사용되었던 Font를 OldFont에 저장한다.
// 3. Drawing 
// 4. OldFont로 복귀한다.
// 5. MyFont를 Delete
void Graphic2D::DrawString(HDC hdc, wstring value, int x, int y, int size, COLORREF rgb)
{
	// 1. FontCreate
	HFONT MyFont;
	HFONT OldFont;
	LOGFONT lf;
	wstring strFontName = L"Segoe UI";

	lf.lfHeight			= size;
	lf.lfWidth			= 0;
	lf.lfEscapement		= 0;
	lf.lfOrientation	= 0;	// 수평 : 0, 수직 : 1
	lf.lfWeight			= 400;	// 보통, 굵게
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfCharSet		= HANGEUL_CHARSET;
	lf.lfOutPrecision	= 0;
	lf.lfClipPrecision	= 0;
	lf.lfQuality		= 0;
	lf.lfPitchAndFamily	= 0;
	wcscpy(lf.lfFaceName, strFontName.c_str());
	//WCHAR     lfFaceName[LF_FACESIZE];

	MyFont = CreateFontIndirect(&lf);

	// 2. MyFont를 사용하게 하고, 그전에 사용되었던 Font를 OldFont에 저장한다.
	OldFont = (HFONT)SelectObject(hdc, MyFont);

	// 3. Drawing 
	SetTextColor(hdc, rgb);
	SetBkMode(hdc, TRANSPARENT); // 글자뒤의 배경을 투명처리
	TextOut(hdc, x, y, value.c_str(), value.length());

	// 4. OldFont로 복귀
	SelectObject(hdc, OldFont);
	DeleteObject(MyFont);
}


