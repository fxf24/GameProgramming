#include <stdio.h>

int main() 
{
	// �� ������
	// �� �ǿ������� ���� �����ִ� �������Դϴ�.
	// ���̶�� 1�� �����̶�� 0�� ��ȯ�մϴ�.
	// ����
	// a == b : a�� b�� �������� �˻��մϴ�.
	// a != b : a�� b�� �ٸ����� �˻��մϴ�.
	// a > b, a < b : a�� b���� �ʰ�����, �̸����� �˻��մϴ�.
	// a >= b, a <= b : a�� b���� �̻�����, �������� �˻��մϴ�.

	int a = 10 + 10;
	int b = 2 * 10;
	int c = 15;

	int result = a == b;
	printf("[%d == %d] ����� : %d\n", a, b, result);
	result = a != b;
	printf("[%d != %d] ����� : %d\n", a, b, result);
	result = a != c;
	printf("[%d != %d] ����� : %d\n", a, c, result);
	result = a > c;
	printf("[%d > %d] ����� : %d\n", a, c, result);
	result = a >= b;
	printf("[%d >= %d] ����� : %d\n", a, b, result);
	result = a <= c;
	printf("[%d <= %d] ����� : %d\n", a, c, result);
	result = a < b;
	printf("[%d < %d] ����� : %d\n", a, b, result);

	// ��ǻ�ʹ� ���� 1�� ������ 0���� �Ǵ��մϴ�.

	return 0;
}