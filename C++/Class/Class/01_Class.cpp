#include <iostream>
using namespace std;

// 클래스
// - 사용자 지정 자료형을 만들 수 있는 또 하나의 키워드입니다.
//   구조체랑 비슷한 형식을 가지고 있으며, 구조체는 보다 간단한 형식을
//   클래스는 보다 복잡한 형식을 설계할 때 사용합니다.

// 선언
// class 키워드를 이용하여 선언합니다.
class MyClass {

public :
	string Name;

private :
	int	   MemVar;

public :
	// 설정자
	// private 인 멤버 하나의 값을 설정하는 함수를 설정자라 합니다.
	// Set 접두사를 사용합니다.
	void SetMemVar(int integer) {
		MemVar = integer;
	}

	// 접근자
	// private 인 멤버 하나의 값을 접근하는 함수를 설정자라 합니다.
	// Get 접두사를 사용합니다.
	__forceinline int GetMemVar() const{
		return MemVar;
	}
	// 멤버 함수 뒤의 const
	// 해당 함수 정의에서 멤버의 값을 변경하지 못하도록 합니다.
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
	// 접근제한자가 public 이므로 외부에서 접근이 가능합니다.
	myClass.Name   = "myClass";
	// 접근제한자가 private 이므로 외부에서 접근이 불가능합니다.
	//myClass.MemVar = 10;
	myClass.SetMemVar(10);

	cout << "Class Name   : " << myClass.Name << endl;
	cout << "Class Memvar : " << myClass.GetMemVar() << endl;

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