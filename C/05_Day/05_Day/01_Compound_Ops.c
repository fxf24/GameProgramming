#include <stdio.h>

// 복합대입연산자
// 왼쪽 피연산자에 오른쪽 피연산자 데이터를 할당하는 연산자입니다.

// 종류
// [ +=, -=, *=, /=, %= ]

int main()
{
	int a = 10;
	int b = 20;

	a += b;
	// a = a + b;
	printf("a = %d \n", a);

	a *= b;
	// a = a * b;
	printf("a = %d \n", a);


	return 0;
}