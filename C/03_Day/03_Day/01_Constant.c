#include <stdio.h>

// ��� : ������ �� ���� ��

// const : ��� ������ ���� �������� ���ϵ��� �ϴ� Ű���� �Դϴ�.

int main()
{
	int num = 10;
	printf("num = %d \n", num);
	num = 20;
	printf("num = %d \n", num);

	// �ڷ��� �տ� const�� ����մϴ�.
	// const Ű���带 ����Ѵٸ� ����� ���ÿ� �ʱ�ȭ�� ���ּž� �մϴ�.
	const int num2 = 20;
	// const Ű���带 ����� ������ ���� �������� ���մϴ�.
	// num2 = 30;
	return 0;
}