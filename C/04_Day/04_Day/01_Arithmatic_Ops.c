#include <stdio.h>

int main() 
{
	// int �� ���� a, b�� �����ϰ�
	// �� ������ 10�� 20�� �������ּ���.
	
	int a, b;
	a = 20;
	b = 10;

	// ��� ������
	// �� �����ڿ� ���� ��� ������ ���ִ� �������Դϴ�.
	// ��� ����: +, -, *, /, %
	// �ǿ����ڶ� ? : ������ ����� �Ǵ� �����͸� ���մϴ�.

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