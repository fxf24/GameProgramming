#include <iostream>
using namespace std;

// 클래스
// - 사용자 지정 자료형을 만들 수 있는 또 하나의 키워드입니다.
//   구조체랑 비슷한 형식을 가지고 있으며, 구조체는 보다 간단한 형식을
//   클래스는 보다 복잡한 형식을 설계할 때 사용합니다.

// 선언
// class 키워드를 이용하여 선언합니다.
class MyClass {
	string Name;
	int	   MemVar;
};

struct MyStruct {
	string Name;
	int    MemVar;
};

int main() {
	// MyStruct 형식의 객체를 선언합니다.
	MyStruct myStruct;
	// MyStruct 의 멤버의 접근합니다.
	myStruct.Name   = "myStruct";
	myStruct.MemVar = 10;

	// MyClass 형식의 객체를 선언합니다.
	MyClass myClass;
	// myClass 의 멤버에 접근합니다.
	myClass.Name   = "myClass";
	myClass.MemVar = 10;

	return 0;
}


// 객체 지향 4대 속성 중 캡슐화
// - 사용자가 정보 보호를 위하여 객체의 멤버를 공개하거나 감추는 것을 말합니다.
// - 접근제한자를 이용하여 사용하실 수 있습니다.

// 접근제한자
// private
// - 내부에서만 접근이 가능하도록 하며 외부에서는 접근이 불가능 하도록 설정합니다. 
//   class 의 기본 접근 제한자 입니다.
// public 
// - 내부, 외부에서 모두 접근이 가능하도록 설정합니다.
//   struct 의 기본 접근 제한자 입니다.
// protected