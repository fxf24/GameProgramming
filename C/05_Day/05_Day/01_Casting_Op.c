#include <stdio.h>

// ���� ��ȯ (ĳ����) ������ 
// - �� �������� ������ ������ ���ϴ� ��������
//   ��ȯ�ϴ� �����ڸ� �ǹ��մϴ�.

// ��� ���
// (��ȯ�� Ÿ��) �� ������

int main() 
{
	int myInt;
	float myFloat = 3.14f;

	(float)myInt = myFloat;
	
	printf("myInt = %.2f\n", (float)myInt);

	int myA = 65;
	printf("myA = %c \n", (char)myA);

	return 0;
}