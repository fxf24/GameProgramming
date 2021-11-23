#include <stdio.h>
#pragma warning(disable : 4996)

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a;
	int b;

	printf("a 의 값을 입력하세요 : ");
	scanf("%d", &a);
	printf("b 의 값을 입력하세요 : ");
	scanf("%d", &b);
	
	// swap 함수 실행 !
	swap(&a, &b);

	printf("a 입력값 : %i\n", a);
	printf("b 입력값 : %i\n", b);

	return 0;
}