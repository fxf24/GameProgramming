#include <iostream>

// 함수 호출시 호출 대상을 찾는 기준
// C   : 함수명
// C++ : 함수명, 파라미터 타입

// 이를 이용하여 같은 이름의 함수를 중복정의하는 것을 "함수 오버로딩" 이라 합니다.

void Print(int num) {
	printf("num(int) : %i \n", num);
}

void Print(double num) {
	printf("num(double) : %.2lf \n", num);
}

int main() {
	Print(10);
	Print(3.14);
	return 0;
}