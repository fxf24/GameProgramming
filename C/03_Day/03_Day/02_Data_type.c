#include <stdio.h>

// �Ǽ� �ڷ���
// [�ڷ���]			[Byte]		[��Ÿ�� �� �ִ� ���� ����]
// float			4byte		-3.4 * 10^-37 ~ 3.4 * 10^-38
// double			8byte		-1.7 * 10^-307 ~ 1.7 * 10^-308

int main()
{
	// float ���� ��� ���� ������ �� �� �ڿ� f�� �ٿ��ּž� �մϴ�.
	float	myFloat = 3.14f;
	double	myDouble = 1.234;

	// %f : float ������ ������ ����� �� ����մϴ�.
	printf("myFloat	 = %.2f		\n", myFloat);
	// %lf : double ������ ������ ����� �� ����մϴ�.
	printf("myDouble = %.3lf	\n", myDouble);

	// ���ϴ� �Ҽ��� �ڸ����� ����ϴ� ���
	// % �ڿ� ".��Ÿ�� �Ҽ��� �ڸ�" �� �ۼ��Ͻø� �˴ϴ�.

	return 0;
}