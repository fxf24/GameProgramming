#include <iostream>
using namespace std;

class BaseClass
{
private:
	int MyPrivate;

	// protected 접근 제한자
	// 상속 받은 파생 클래스에서만 접근이 가능하도록 허용해주는 제한자 입니다.
	// 해당 형식의 파생 클래스에서는 접근이 가능하지만 외부로 부터 접근하는 것은 제한합니다.
protected:
	int MyProtected;

public:
	int MyPublic;

public:
	BaseClass() { MyPrivate = 10; }

public:
	void PrintMember() const
	{
		cout << "MyPrivate   : " << MyPrivate << endl;
		cout << "MyProtected : " << MyProtected << endl;
		cout << "MyPublic    : " << MyPublic << endl;
	}
};

class DerivedClass : public BaseClass
{
public:
	DerivedClass()
	{
		// MyPrivate = 10;
		// protected 접근제한자이므로 파생 클래스에서는 접근이 가능합니다.
		MyProtected = 20;
		MyPublic = 30;
	}
};

int main()
{
	DerivedClass dc = DerivedClass();
	// private 이므로 선언되어 있는 클래스 영역이 아니라면 접근 불가능
	//dc.MyPrivate   = 10; - Error -
	// 	   
	// protected 이므로 선언되어 있는 클래스 혹은 파생 클래스의 영역이 아니라면 접근 불가능
	//dc.MyProtected = 20; - Error -

	// public 이므로 외부로 부터 모든 접근 가능
	dc.MyPublic = 40;

	dc.PrintMember();

	return 0;
}