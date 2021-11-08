#include <stdio.h>

int main() 
{
	// 비교 연산자
	// 두 피연산자의 값을 비교해주는 연산자입니다.
	// 참이라면 1을 거짓이라면 0을 반환합니다.
	// 종류
	// a == b : a가 b와 같은지를 검사합니다.
	// a != b : a가 b와 다른지를 검사합니다.
	// a > b, a < b : a가 b보다 초과인지, 미만인지 검사합니다.
	// a >= b, a <= b : a가 b보다 이상인지, 이하인지 검사합니다.

	int a = 10 + 10;
	int b = 2 * 10;
	int c = 15;

	int result = a == b;
	printf("[%d == %d] 결과값 : %d\n", a, b, result);
	result = a != b;
	printf("[%d != %d] 결과값 : %d\n", a, b, result);
	result = a != c;
	printf("[%d != %d] 결과값 : %d\n", a, c, result);
	result = a > c;
	printf("[%d > %d] 결과값 : %d\n", a, c, result);
	result = a >= b;
	printf("[%d >= %d] 결과값 : %d\n", a, b, result);
	result = a <= c;
	printf("[%d <= %d] 결과값 : %d\n", a, c, result);
	result = a < b;
	printf("[%d < %d] 결과값 : %d\n", a, b, result);

	// 컴퓨터는 참을 1로 거짓을 0으로 판단합니다.

	return 0;
}