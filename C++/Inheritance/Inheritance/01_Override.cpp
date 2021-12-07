#include <iostream>
using namespace std;

class BaseClass
{
protected :
	int BaseMem;

public :
	BaseClass() { BaseMem = 10; }

public :
	void Print() const { cout << "BaseMem : " << BaseMem << endl; }
};

class DerivedClass : public BaseClass
{
protected :
	int DerivedMem;

public :
	DerivedClass() { DerivedMem = 20; }

public :
	// Override : 기반 클래스의 함수를 파생클래스에서 다른 기능을 가질 수 있도록 재정의 하는 것을 의미합니다.
	// Override 를 하기 위해서는 함수명과 매개변수의 타입이 동일하여야 합니다.
	void Print() const
	{
		cout << "BaseMem    : " << BaseMem    << endl;
		cout << "DerivedMem : " << DerivedMem << endl;
	}

	void Print(int integer)
	{
		BaseMem = integer;
		cout << "BaseMem    : " << BaseMem    << endl;
		cout << "DerivedMem : " << DerivedMem << endl;
	}
};

int main()
{
	DerivedClass myClass;
	
	// 함수의 호출 기준은 객체를 선언할 떄의 자료형을 기준으로 호출합니다.
	myClass.Print();

	return 0;
}