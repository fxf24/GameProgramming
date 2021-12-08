#include <iostream>
#include <combaseapi.h>
using namespace std;


// __interface 인터페이스
// 순수 가상 함수와 가상 소멸자로만 이루어진 클래스입니다.
// 특정 기능만을 상속 시키고 싶을 때 사용합니다.
// 접근제한자를 명시하지 않는다면 public으로 간주됩니다.

// combaseapi interface
// __interface 키워드가 만들어지기 전에 사용하던 인터페이스 구조체입니다.
// 멤버 변수를 선언하실 수 있습니다.
// combaseapi.h 가 필요합니다.
// PURE를 제공합니다.

// 인터페이스명을 I 접두사를 붙여주는 것이 좋습니다.
interface IAPIInterface
{
	int a = 10;
	virtual void HelloInterface() PURE;
	
	virtual ~IAPIInterface() = default;
};

__interface IMyInterface
{
	//int a;
	virtual void HelloInterface() = 0;
};

class MyClass1 : public IAPIInterface
{
public :
	// IAPIInterface을(를) 통해 상속됨
	virtual void HelloInterface() override
	{
		a = 20;
		cout << "a : " << a << endl;
		cout << "IAPIInterface:: Hello Interface !" << endl;
	}

	virtual ~MyClass1() = default;
};

class MyClass2 : public IMyInterface
{
public :
	// IMyInterface을(를) 통해 상속됨
	virtual void HelloInterface() override
	{
		cout << "IMyInterface:: Hello Interface !" << endl;
	}

	virtual ~MyClass2() = default;
};

int main()
{
	// 인터페이스 객체는 선언할 수 없습니다.
	// IAPIInterface iAPIInterface;
	// IMyInterface iMyInterface;

	MyClass1 myClass1;
	myClass1.HelloInterface();

	MyClass2 myClass2;
	myClass2.HelloInterface();
	return 0;
}