#include <iostream>
using namespace std;

// 추상화
// 모델링 기법을 의미하며 공통된 부분, 특정 특성을 분리해 재조합하는 속성입니다. 

// 추상 클래스
// 순수 가상함수를 하나 이상 포함한 클래스를 의미합니다.
// 완전하지 않는 클래스이므로 인스턴스화가 불가능합니다.
// abstract 키워드를 이용하여 순수가상함수를 포함하지 않아도
// 추상 클래스임을 명시할 수 있습니다.
// 
class AbstractClass abstract
{
protected :
	int MyInt;

public :
	// 순수 가상 함수
	// 선언부만 존재하며 정의부가 존재하지 않는 함수를 말합니다.
	// 반드시 상속받는 파생 클래스에서 재정의를 해주셔야 합니다.
	// = 0 을 작성하여 선언하실 수 있습니다.
	virtual void AddTen() = 0;

	virtual void Print() const { cout << "MyInt : " << MyInt << endl; }

	virtual ~AbstractClass() = default;
};

class DerivedClass final : public AbstractClass
{
public :
	DerivedClass() { MyInt = 0; }
	virtual ~DerivedClass() = default;

public :
	// AbstractClass을(를) 통해 상속됨
	virtual void AddTen() override
	{
		MyInt += 10;
	}
	
public :
	virtual void Print() const final override
	{
		cout << "MyInt : " << MyInt << endl;
	}
};

int main()
{
	// 추상 클래스는 완전하지 않은 클래스이므로
	// 객체 선언, 인스턴스화가 불가능합니다.
	// AbstractClass myclass;

	DerivedClass* myClass = new DerivedClass();
	myClass->AddTen();
	myClass->Print();

	delete myClass;
	myClass = nullptr;

	return 0;
}