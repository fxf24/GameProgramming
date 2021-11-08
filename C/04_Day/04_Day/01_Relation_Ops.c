#include <stdio.h>

// 관계연산자
// 두 피연산자의 관계를 연산하는 연산자입니다.

// 종류
// && (AND) : 두 피연산자의 값이 둘 다 1 이라면 1을
//			  하나라도 0 이라면 0을 결과값으로 나타냅니다.
// || (OR) :  두 피연산자의 값이 둘 다 0 이라면 0을
//			  하나라도 1 이라면 1을 결과값으로 나타냅니다.
// ! (NOT) :  피 연산자의 값이 0이라면 1로 1이라면 0으로
//			  변환한 값을 결과값으로 나타냅니다.

int main()
{
	int result = 1 && 1;
	result = 0 && 1;
	result = 0 || 1;
	result = 0 || 0;
	result = !0;

	int a = 10;
	int b = 20;

	result = 1 && (a > b);
	printf("결과값 : %d\n", result);
	result = (a != b) && (a < b);
	printf("결과값 : %d\n", result);
	result = (a == 10) || (a != b);
	printf("결과값 : %d\n", result);
	result = (20 != 10) && !0;
	printf("결과값 : %d\n", result);
	result = (a >= b) || (a != b);
	printf("결과값 : %d\n", result);
	result = ((a == 10) || (a > b)) || a == b;
	printf("결과값 : %d\n", result);
	result = (!(a == 10) || (a > b)) || a == b;
	printf("결과값 : %d\n", result);
	result = (!(a == 10) || !(a > b)) || !(a == b);
	printf("결과값 : %d\n", result);

	return 0;
}