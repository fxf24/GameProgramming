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

public :
	// 연산자 오버로딩 방법
	// 반환 타입 / operator"오버로딩할 연산자" / (피연산자)
	// 반환 타입 : 연산이 완료된 후 나올 결과값으로 쓸 타입
	// 피연산자  : 연산의 대상이 되는 데이터

#pragma region Arithmetic Operator Overloading
	FORCEINLINE Vector operator+(const Vector& value)
	{
		return Vector(X + value.X, Y + value.Y);
	}

	FORCEINLINE Vector operator+(const float& value)
	{
		return Vector(X + value, Y + value);
	}

	FORCEINLINE Vector operator-(const Vector& value)
	{
		return Vector(X - value.X, Y - value.Y);
	}

	FORCEINLINE Vector operator*(const Vector& value)
	{
		return Vector(X * value.X, Y * value.Y);
	}
#pragma endregion

#pragma region Assignment Operator Overloading
	FORCEINLINE Vector operator/(const Vector& value)
	{
		return Vector(X / value.X, Y / value.Y);
	}

	FORCEINLINE void operator+=(const Vector& value)
	{
		X += value.X;
		Y += value.Y;
	}

	FORCEINLINE void operator-=(const Vector& value)
	{
		X -= value.X;
		Y -= value.Y;
	}

	FORCEINLINE void operator*=(const Vector& value)
	{
		X *= value.X;
		Y *= value.Y;
	}

	FORCEINLINE void operator/=(const Vector& value)
	{
		X /= value.X;
		Y /= value.Y;
	}
#pragma endregion
	
#pragma region Increment, Decrement Operator Overloading
	FORCEINLINE void operator++(const int value)
	{
		X++;
		Y++;
	}
	FORCEINLINE void operator--(const int value)
	{
		X--;
		Y--;
	}
#pragma endregion

};