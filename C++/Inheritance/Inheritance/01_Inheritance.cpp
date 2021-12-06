#include <iostream>
using namespace std;

// 상속성
// 기반 클래스의 기능을 파생 클래스가 물려받아 나아가 확장하는 개념을 의미합니다.
// 같은 코드를 중복적으로 작성하는 것을 방지하여 생산성을 높이는 기법입니다.

// 기반 클래스를 작성합니다.
class BaseClass
{
public :
	// 기반 클래스의 생성자를 정의합니다.
	BaseClass()
	{
		cout << "Base Class Constructor Call!" << endl;
	}

	// 기반 클래스의 소멸자를 정의합니다.
	~BaseClass()
	{
		cout << "Base Class Finalizer Call!" << endl;
	}
};

// 기반 클래스의 파생 클래스를 선언합니다.
// 상속 방법 
//				   : "접근제한자" "상속받을 클래스명"
class DerivedClass : public BaseClass
{
public :
	// 파생 클래스의 생성자를 정의합니다.
	DerivedClass()
	{
		cout << "Derived Class Constructor Call!" << endl;
	}

	// 파생 클래스의 소멸자를 정의합니다.
	~DerivedClass()
	{
		cout << "Derived Class Finalizer Call!" << endl;
	}
};

int main()
{
	// 파생 클래스의 형식을 동적할당합니다.
	DerivedClass* myClass = new DerivedClass();

	delete myClass;
	myClass = nullptr;

	// 상속관계에서의 생성자 / 소멸자 호출 순서
	// 생성자
	// - 최상위 기반 클래스의 생성자부터 호출되며 최하위 파생 클래스 생성자
	//   순서로 호출 됩니다.
	// 소멸자
	// - 최하위 파생 클래스의 소멸자부터 호출되며 최상위 기반 클래스 소멸자
	//   순서로 호출 됩니다.

	return 0;
}