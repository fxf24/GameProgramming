#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int a, b;
	printf("a �� ���� �Է��ϼ��� : ");
	scanf("%d", &a);
	printf("b �� ���� �Է��ϼ��� : ");
	scanf("%d", &b);
	printf("�� ū ���� (%s)%d �Դϴ�.", a > b ? "a": "b", a > b ? a : b);
	return 0;
}