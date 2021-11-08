#include <stdio.h>
#pragma warning(disable: 4996)
// int 형 변수 a, b 를 선언하고
// scanf 로 값을 입력받아 a, b 를 초기화한 후
// a, b 의 + , -, *, /, % 의 결과를 출력하는
// 프로그램을 만들어 주세요.

int main()
{
	int a, b;
	
	printf("a 를 입력하세요 : ");
	scanf("%d", &a);
	printf("b 를 입력하세요 : ");
	scanf("%d", &b);

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