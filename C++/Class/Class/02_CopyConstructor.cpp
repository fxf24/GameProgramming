#include <iostream>
using namespace std;

// 복사 생성자
// 다른 객체의 멤버의 값을 복사하여 멤버를 초기화하는 생성자를 의미합니다.

class Copy
{
private :
	int MyInt;
	float MyFloat;

public :
	Copy() = default;
	// == Copy() {};
	Copy(int myInt, float myFloat)
	{
		MyInt = myInt;
		MyFloat = myFloat;
	}
	
	// C++에서는 복사생성자를 정의하지 않는다면 
	// 아래 형태와 같은 기본 복사 생성자를 제공합니다.
	// 복사 생성자 형태
	//Copy(const Copy& copy)
	//{
	//	// 인자값으로 받은 객체의 멤버를 복사합니다.
	//	MyInt   = copy.MyInt;
	//	MyFloat = copy.MyFloat;
	//}

public :
	__forceinline void PrintMember() const
	{
		printf("MyInt   : %i   \n", MyInt);
		printf("MyFloat : %.2f \n", MyFloat);
	}
};

int main()
{
	Copy copy1 = Copy(10, 3.14f);

	// 복사 생성자를 이용하여 copy2 의 멤버의 값을 copy1 과 같게 만듭니다.
	// Copy copy2 = Copy(copy1);
	Copy copy2 = copy1; // 이과 같이 생략이 가능합니다.
	copy2.PrintMember();

	return 0;
}