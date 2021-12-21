#pragma once
// Class : 캡슐화, 정보은닉성, 다형성, 상속성, 추상화
// 
// class 내에 선언된 static 함수, static 변수는 C++ 에서
// 전역으로 사용된것 처럼 이용이 된다.
//
class Graphic2D
{
public :
	static void DrawLine(HDC hdc, int x1, int y1, int x2, int y2, int width, COLORREF rgb);
	static void DrawRectangle(HDC hdc, int left, int top, int right, int bottom, COLORREF rgb);
	static void DrawString(HDC hdc, wstring value, int x, int y, int size, COLORREF rgb);

public :
	Graphic2D();
	~Graphic2D();
};

