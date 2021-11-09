#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int a, b;
	printf("a 의 값을 입력하세요 : ");
	scanf("%d", &a);
	printf("b 의 값을 입력하세요 : ");
	scanf("%d", &b);
	printf("더 큰 값은 (%s)%d 입니다.", a > b ? "a": "b", a > b ? a : b);
	return 0;
}