#include <stdio.h>

int main() 
{
	// int 형 변수 a, b를 선언하고
	// 각 공간에 10과 20을 저장해주세요.
	
	int a, b;
	a = 20;
	b = 10;

	// 산술 연산자
	// 피 연산자에 대한 산술 연산을 해주는 연산자입니다.
	// 산술 연산: +, -, *, /, %
	// 피연산자란 ? : 연산의 대상이 되는 데이터를 말합니다.

	int result = a + b;
	printf("%d + %d = %d\n", a, b, result);
	result = a - b;
	printf("%d - %d = %d\n", a, b, result);
	result = a * b;
	printf("%d * %d = %d\n", a, b, result);
	result = a / b;
	printf("%d / %d = %d\n", a, b, result);
	result = a % b;
	printf("%d %% %d = %d\n", a, b, result);


	return 0;
}