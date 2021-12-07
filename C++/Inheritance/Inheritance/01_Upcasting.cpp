#include <iostream>
using namespace std;

class BaseClass
{
protected:
	int BaseMem;

public:
	BaseClass() { BaseMem = 10; }

public:
	void Print() const { cout << "BaseMem : " << BaseMem << endl; }
};

class DerivedClass : public BaseClass
{
protected:
	int DerivedMem;

public:
	DerivedClass() { DerivedMem = 20; }
	~DerivedClass() { cout << "Derived Finalizer Call" << endl; }

public:
	void Print() const
	{
		cout << "BaseMem    : " << BaseMem << endl;
		cout << "DerivedMem : " << DerivedMem << endl;
	}
};

int main()
{
	// Upcasting
	// 파생 클래스의 객체를 기반 클래스의 포인터로 가리키는 것을 의미합니다.
	BaseClass* myClass = new DerivedClass();
	
	myClass->Print();

	((DerivedClass*)myClass)->Print();

	// () : C 언어에서부터 제공하는 형변환 연산자입니다.
	//      모든 자료형에 대하여 강제적으로 형변환이 가능하며
	//      논리적으로 맞지 않는 형변환도 허용합니다.
	const char* str = "Hello";
	(int)str;

	// static_cast<int>(str); - Error - 
	// static_cast<Type>() : C++ 에서부터 제공하는 형변환 연산자입니다.
	// 논리적으로 맞는 타입에 대해서 형변환을 허용하고 논리적으로 맞지않는 형변환에 대해서는 허용을 하지 않습니다.

	static_cast<DerivedClass*>(myClass)->Print();

	delete myClass;
	myClass = nullptr;
	return 0;
}