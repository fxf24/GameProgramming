#include <iostream>
using namespace std;

// 생성자
// - 객체를 만드는 자료형과 같은 이름을 가지는 함수입니다.
// - 객체를 선언(생성)할 때 호출되며, 선언후에 호출이 불가능합니다.
// - 선언과 동시에 멤버들의 값을 초기화하고 싶을 때 사용합니다.

class Default
{
public:
	int Memvar;
};

class Constructor
{
public:
	int Memvar;

public:
	// 생성자를 정의하고 있기 때문에
	// C++이 제공하는 기본 생성자를 사용하실 수 없습니다.
	Constructor()
	{
		Memvar = 10;
	}
	// 생성자는 오버로딩이 가능합니다.
	Constructor(int integer)
	{
		Memvar = integer;
	}
};

int main()
{
	// 생성자 호출
	Constructor myClass = Constructor(30);

	cout << "myClass::Memvar : " << myClass.Memvar << endl;

	int myInt = int(10);
	cout << "myInt : " << myInt << endl;

	// C++ 에서는 생성자를 정의하지 않는다면
	// 모든 멤버의 값을 기본값으로 바꾸는 기본 생성자를 제공합니다. 컴파일러가 제공
	Default myClass2 = Default();
	cout << "myClass2::Memvar : " << myClass2.Memvar << endl;
	return 0;
}