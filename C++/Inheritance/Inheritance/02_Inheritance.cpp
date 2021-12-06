#include <iostream>
using namespace std;

// 재생산성
// 파생 클래스는 기반 클래스의 기능을 물려받습니다.

class BaseClass
{
public :
	int MyInt;

public :
	inline int GetMyInt() const
	{
		return MyInt;
	}

	inline void SetMyInt(int integer)
	{
		MyInt = integer;
	}
};

class DerivedClass : public BaseClass
{
	// 확장성
	// 기반 클래스의 기능이 아닌 다른 기능을 추가시킬 수 있습니다.
public : 
	float MyFloat;

public :
	DerivedClass(int integer, float real)
	{
		// 파생 클래스는 기반 클래스의 기능을 물려받습니다.
		MyInt = integer;
		MyFloat = real;
	}

public :
	void PrintMember() const
	{
		cout << "MyInt : " << MyInt << endl;
		cout << "MyFloat : " << MyFloat << endl;
	}
};

int main()
{
	DerivedClass dc = DerivedClass(10, 3.14);

	dc.PrintMember();

	// 기반 클래스의 함수를 호출 할 수 있습니다.
	dc.SetMyInt(50);
	cout << "derivedClass::MyInt : " << dc.GetMyInt() << endl;

	BaseClass baseClass;

	// 파생 클래스에서 부터 정의된 함수이므로 기반 클래스에서는 사용하실 수 없습니다.
	// baseClass.PrintMember(); - Error -

	// 기반클래스의 생성자와 소멸자는 상속 받지 않습니다.

	return 0;
}