#include <iostream>
using namespace std;

// 일반화 프로그래밍
// - 데이터 형식을 일반화 프로그래밍 하는 방식을 의미합니다.
// - C++ 에서는 템플릿을 이용한 프로그래밍입니다.

// 템플릿
// - 변수의 타입을 정하지 않고 필요한 타입을 컴파일 타임에 정의하여 사용하는 개념

// 함수 템플릿
// - 함수의 기능은 결정되어 있지만, 형식은 결정되어 있지 않으며
//   함수에 사용되는 형식을 일반화시킨 함수를 의미합니다.

template <class T>
// -tmplate <typename T> 으로도 작성하실 수 있으며, 모두 동일한 방식입니다.
// typename(class) : 사용할 타입입니다.
// T : 템플릿 매개변수로 다른 단어여도 무관합니다.

T Addition(T num1, T num2)
{
	//cout << "T size : " << sizeof(T) << " byte " << endl;
	printf("T size : %d byte \n", sizeof(T));
	return num1 + num2;
}

// 템플릿 특수화
// 매개변수에 따라 다른기능할 수 있도록 지정할 수 있습니다.
// 템플릿 매개변수를 지우고, 템플릿 자료형 대신 특수화 시킬 자료형을 대입하여 작성합니다.
template<>
const char* Addition(const char* num1, const char* num2)
{
	return "문자열은 더하실 수 없습니다!";
}


int main()
{
	// 함수 템플릿 호출 방법!
	// 템플릿 함수명<사용할 타입>();

	cout << "Addition(1, 2) = " << Addition<int>(1, 2) << endl;
	cout << "Addition(3.5, 7.6) = " << Addition(3.5, 7.6) << endl;
	cout << "Addition(3.5, 7.6) = " << Addition<const char*>("a", "b") << endl;

	return 0;
}