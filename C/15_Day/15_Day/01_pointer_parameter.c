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

	printf("a �� ���� �Է��ϼ��� : ");
	scanf("%d", &a);
	printf("b �� ���� �Է��ϼ��� : ");
	scanf("%d", &b);
	
	// swap �Լ� ���� !
	swap(&a, &b);

	printf("a �Է°� : %i\n", a);
	printf("b �Է°� : %i\n", b);

	return 0;
}