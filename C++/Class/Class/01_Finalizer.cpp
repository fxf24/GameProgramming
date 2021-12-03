#include <iostream>
using namespace std;

// 소멸자
// 객체가 소멸될 때 호출되는 함수입니다.
// ~생성자() 와 같이 선언합니다.
// 소멸자를 정의하지 않는다면 기본 소멸자를 제공합니다.
// 매개변수를 사용할 수 없기 떄문에 오버로딩 또한 불가능합니다.

class Finalizer
{
public : 
	~Finalizer()
	{
		cout << "Finalizer Call!" << endl;
	}
};

int main()
{
	Finalizer* myClass = new Finalizer();
	
	// __LINE__ : 코드의 라인을 반환합니다.
	cout << __LINE__ << endl;
	delete myClass;
	cout << __LINE__ << endl;
	myClass = nullptr;

	return 0;
}