#pragma once
#include <iostream>
using namespace std;

// class 템플릿
// - 제공되는 기능과 내부의 행동이 모두 동일하지만
//   사용하는 형식이 서로 다른 클래스를 찍어 낼 수 있는 틀을 의미합니다.
// - 만약 템플릿을 사용하는 클래스라면 선언부에 모든 내용을 정의해야합니다.

template <typename T>
class TemplateClass
{
private:
	T value1;
	T value2;
	int value3;

public:
	TemplateClass(T value1, T value2) : value1(value1), value2(value2), value3(10) {};

	void GetValues() const
	{
		cout << "T Size : " << sizeof(T) << endl;
		cout << "value1 : " <<    value1 << endl;
		cout << "value2 : " <<    value2 << endl;
		cout << "value3 : " <<    value3 << endl;
	}

	T Add()
	{
		return value1 + value2;
	}
};
