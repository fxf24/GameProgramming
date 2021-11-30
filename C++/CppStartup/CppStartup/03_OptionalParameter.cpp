#include <iostream>

// 선택적 매개변수
// - 기본값을 가지는 매개 변수를 말하며, 필요에 의해 할당을 생략할 수 있습니다.
// - 꼭 필수 매개 변수 뒤에 선언되어야 합니다.
// 필수 매개변수
// 함수 호출시 인자값을 받아야 하는 매개변수를 뜻합니다.

// 필수 매개 변수 : a, b
// 선택적 매개 변수 : print
void Add(int a, int b, bool print = true) {
	if (print) {
		printf("a : %i \n", a);
		printf("b : %i \n", b);
	}

	printf("a + b = %i \n", a + b);
}

int main() {

	Add(10, 20);
	Add(30, 40, false);

	return 0;
}