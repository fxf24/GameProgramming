#include <stdio.h>
#pragma warning(disable : 4996)
// 4996 �̶�� �ڵ��� ������ �����ϵ��� �����մϴ�.

int main()
{
	int Num;
	
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &Num);
	// scanf(�Է¹��� ����, &�Է� ���� ���� ������ ����);

	printf("�Է� ���� ���� : %d \n", Num);

	return 0;
}