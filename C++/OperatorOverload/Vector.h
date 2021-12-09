#pragma once
#include <iostream>
using namespace std;

#define FORCEINLINE __forceinline

// 연산자 오버로딩
// - 기존에 존재하던 연산자의 기본 기능 이외에 다른 기능을 추가하는 것을 의미합니다.

// 다음과 같은 연산자는 오버로딩이 불가능합니다.
// - .  : 멤버 선택 
// - :: : 범위 지정 
// - ?  : 조건
// - #  : 문자열 전처리기 변환
// - ## : 전처리기 연결

class Vector final
{
private :
	float X;
	float Y;

public :
	Vector() : X(0.f), Y(0.f) {};
	Vector(float x, float y) : X(x), Y(y) {};

	void PrintVector() const
	{
		printf("[ %.1f, %.1f ] \n", X, Y);
	}

};