#include <stdio.h>

// ���迬����
// �� �ǿ������� ���踦 �����ϴ� �������Դϴ�.

// ����
// && (AND) : �� �ǿ������� ���� �� �� 1 �̶�� 1��
//			  �ϳ��� 0 �̶�� 0�� ��������� ��Ÿ���ϴ�.
// || (OR) :  �� �ǿ������� ���� �� �� 0 �̶�� 0��
//			  �ϳ��� 1 �̶�� 1�� ��������� ��Ÿ���ϴ�.
// ! (NOT) :  �� �������� ���� 0�̶�� 1�� 1�̶�� 0����
//			  ��ȯ�� ���� ��������� ��Ÿ���ϴ�.

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
	printf("����� : %d\n", result);
	result = (a != b) && (a < b);
	printf("����� : %d\n", result);
	result = (a == 10) || (a != b);
	printf("����� : %d\n", result);
	result = (20 != 10) && !0;
	printf("����� : %d\n", result);
	result = (a >= b) || (a != b);
	printf("����� : %d\n", result);
	result = ((a == 10) || (a > b)) || a == b;
	printf("����� : %d\n", result);
	result = (!(a == 10) || (a > b)) || a == b;
	printf("����� : %d\n", result);
	result = (!(a == 10) || !(a > b)) || !(a == b);
	printf("����� : %d\n", result);

	return 0;
}