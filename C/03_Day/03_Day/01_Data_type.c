#include <stdio.h>

// unsigned : �ڷ��� �տ� ����ϸ� �ش� �ڷ����� ������ ǥ���� �� �ִ�
//			  ������ ����� ǥ���� �� �հ� ����ϴ�.
//			  unsigned ���̰� �ȴٸ� ������ ������ �� �����ϴ�.

int main()
{
	// char ���� ��� -128 ~ 127 ���� ��Ÿ�� �� �ִ� �ڷ��� �Դϴ�.
	char number = 255;
	printf("number = %d \n", number);

	// unsigned �� ���̰� �ȴٸ� -128 ���� ��Ÿ�� �� �ִ� ������ ������
	// ����� ������ ����ϰ� �Ǹ� 0 ~ 255���� ������ �� �ְ� �˴ϴ�.
	unsigned char uNumber = 255;
	printf("number = %d \n", uNumber);

	return 0;
}