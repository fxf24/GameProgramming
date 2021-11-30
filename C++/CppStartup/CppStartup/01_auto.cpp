#include <iostream>

// auto : 타입 추론
// - 초기값의 형식에 맞춰 선언하는 변수의 형식을 자동으로 결정하는 타입입니다.
// - 런타임 중이 아닌, 컴파일 시점에서 자료형식이 결정됩니다.
// - 선언시 꼭 초기화를 진행하여야 합니다.
// - 함수의 반환형에는 사용이 가능하지만, 파라미터 형식으로는 사용하실 수 없습니다.

int main() {
	// auto 형 변수 선언
	auto myInt    = 10;
	auto myChar   = 'A';
	auto myFloat  = 3.14f;
	auto myDouble = 1.234;

	printf("myInt    Size = %zd byte \n", sizeof(myInt));
	printf("myChar   Size = %zd byte \n", sizeof(myChar));
	printf("myFloat  Size = %zd byte \n", sizeof(myFloat));
	printf("myDouble Size = %zd byte \n", sizeof(myDouble));




	return 0;
}