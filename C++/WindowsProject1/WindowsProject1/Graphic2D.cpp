#include "framework.h"
#include "Graphic2D.h"
// Gdi Plus
// png파일을 사용하기 위해
// Gdiplus를 사용하려면
// 1. include
//    #include  <ole2.h>
//    #include  <gdiplus.h>
// 2. library
//    #pragma comment(lib,"Gdiplus.lib")
// 3. Window Create된후  --> Startup
//   static ULONG_PTR gdiplusToken = NULL;
//	 GdiplusStartupInput gdiplusStartInput;
//   GdiplusStartup(&gdiplusToken, &gdiplusStartInput, NULL);
// 4. Window가 종료될때   --> Shutdown
//   GdiplusShutdown(gdiplusToken);
//

#include <ole2.h> // Obejct Linking And Emedded : WinOD (OLE, Activex Com Object)
#include <gdiplus.h>

#pragma comment(lib, "Gdiplus.lib")
#pragma comment(lib, "msimg32.lib")		// #pragma 컴파일 지시기

using namespace Gdiplus;
static ULONG_PTR gdiplusToken = NULL;

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

// 1. MemoryDC Create
// 2. MyBitmap을 사용하게 하고 그전에 사용되었던 Bitmap을 OldBitmap으로 저장한다.

void Graphic2D::DrawBitmap(HDC hdc, wstring fileName, int x, int y)
{
	// 1. MemoryDC Create
	HDC MemDC = CreateCompatibleDC(hdc);

	// 2. Bitmap Create
	HBITMAP MyBitmap = (HBITMAP)LoadImage(NULL, // hinstance --> *.exe
		fileName.c_str(),						// Bitmap File Name
		IMAGE_BITMAP,							// Type IMAGE_BITMAP, IMAGE_ICON, IMAGE_CURSOR
		0,										// cx
		0,										// cy
		LR_LOADFROMFILE | LR_CREATEDIBSECTION); // DIB (Device Independet Bitmap)

	// 3. Bitmap정보를 얻어오기 --> 렌더링시 Bitmap Size얼마인지
	BITMAP bitmap;
	GetObject(MyBitmap, sizeof(BITMAP), &bitmap);

	int Width = bitmap.bmWidth;
	int Height = bitmap.bmHeight;
	
	// 4. MyBitmap을 사용가능하게 한다
	HBITMAP OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);
	
	// 5. Rendering
	BitBlt(hdc, x, y, Width, Height, MemDC, 0, 0, SRCCOPY); // 고속복사

	// 6. OldBitmap, MyBitmap
	SelectObject(MemDC, OldBitmap);
	DeleteObject(MyBitmap);
	DeleteDC(MemDC);

}

void Graphic2D::GdiPlusStartUp()
{
	GdiplusStartupInput gdiplusStartInput;
	GdiplusStartup(&gdiplusToken, &gdiplusStartInput, NULL);

}

void Graphic2D::GdiPlusShutDown()
{
	GdiplusShutdown(gdiplusToken);
}

void Graphic2D::GdiPlusDrawImage(HDC hdc, wstring strFileName, POINT position, POINT offset, POINT offsetSize)
{
	Image* image = new Image(strFileName.c_str());
	Graphics graphic(hdc);
	
	//graphic.DrawImage(image, position.x, position.y, 1300, 1300);
	
	RectF dest{ (float)position.x, (float)position.y, (float)(offsetSize.x * 2.0f), (float)(offsetSize.y * 2.0f) };

	graphic.DrawImage(image, dest, (float)offset.x, (float)offset.y, (float)offsetSize.x, (float)offsetSize.y, UnitPixel);
	//graphic.DrawImage(image, position.x, position.y, 0, 0, 30, 50, UnitPixel);
	
	delete image;
}


