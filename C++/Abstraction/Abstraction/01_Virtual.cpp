#include <iostream>
using namespace std;

// 다형성
// 동일한 함수명을 호출하여 다양한 실행 결과를 나타내거나 (오버로딩)
// 객체들의 자료형에 따라 함수를 호출하여 다양한 실행결과를 나타낼 수 (오버라이딩)있는 속성입니다.

class BaseClass
{
protected :
	int BaseMem;

public :
	virtual ~BaseClass() { cout << "BaseClass Finalizer Call !" << endl; }

public :
	// virtual : 가상의
	// 가상함수
	// virtual 키워드를 반환형 앞에 작성하여 선언할 수 있습니다.
	// 파생 클래스에서 재정의할 것을 기대하는 메서드입니다.
	// 가리키는 객체의 자료형이 아닌 가리키고 있는 객체의 자료형을 기준으로 함수를 호출합니다.
	// 파생 클래스에서 기반 클래스의 가상함수를 재정의 한다면
	// 파생 클래스에서 재정의한 함수 또한 가상함수가 됩니다.
	
	virtual void Print() const
	{
		cout << "BaseMem : " << BaseMem << endl;
	}
};

class DerivedClass1 : public BaseClass
{
protected:
	int DerivedMem;

public:
	DerivedClass1(int base, int derived)
	{
		BaseMem = base;
		DerivedMem = derived;
	}
	virtual ~DerivedClass1() { cout << "DerivedClass Finalizer Call !" << endl; }

public:
	// overrride : 부모의 메서드를 재정의 하고 있는 지 파생클래스에서부터 
	//			   선언하고 있는 가상함수인지를 확인할 수 있는 키워드 입니다.
	virtual void Print() const override
	{
		cout << "BaseMem    : " << BaseMem << endl;
		cout << "DerivedMem : " << DerivedMem << endl;
	}

	// 파생 클래스부터 선언한 가상함수이므로 오류가 나타납니다.
	// virtual void AddTen() override {} - Error -

	// final : 다음 파생클래스에서 해당 함수를 더 이상 재정의 할 수 없도록 지정하는 키워드 입니다.
	virtual void Final() final {}
};

class DerivedClass2 : public DerivedClass1
{
public :
	// final 키워드를 작성한 함수를 재정의 하므로 에러
	// virtual void Final() override {} - Error -

};
int main()
{
	BaseClass* myClass = new DerivedClass1(10, 20);
	myClass->Print();

	delete myClass;
	myClass = nullptr;

	return 0;
}