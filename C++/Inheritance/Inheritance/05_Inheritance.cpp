#include <iostream>
using namespace std;

class BaseClass
{
protected :
	int Integer1;
	int Integer2;

public :
	// BaseClass() = default;

	// : 생성자 초기화 리스트
	//   생성자 선언부에서 멤버들의 값을 초기화 할 수 있습니다.
	BaseClass(int integer1, int integer2) : Integer1(integer1), Integer2(integer2)
	{
		// Integer1 = integer1;
		// Integer2 = integer2;
	}
};

class DerivedClass : public BaseClass
{
protected :
	int Integer3;

public :
	DerivedClass(int integer1, int integer2, int integer3) : BaseClass(integer1, integer2)
	{
		Integer3 = integer3;
	}

public :
	void PrintMember() const
	{
		cout << "Integer1 : " << Integer1 << endl;
		cout << "Integer2 : " << Integer2 << endl;
		cout << "Integer3 : " << Integer3 << endl;
	}
};

int main()
{
	DerivedClass dc = DerivedClass(10, 20, 30);
	dc.PrintMember();

	return 0;
}