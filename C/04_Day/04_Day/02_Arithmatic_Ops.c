#include <stdio.h>
#pragma warning(disable: 4996)
// int �� ���� a, b �� �����ϰ�
// scanf �� ���� �Է¹޾� a, b �� �ʱ�ȭ�� ��
// a, b �� + , -, *, /, % �� ����� ����ϴ�
// ���α׷��� ����� �ּ���.

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

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