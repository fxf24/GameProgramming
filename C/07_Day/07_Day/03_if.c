// int �� ���� num �� �����ϰ�
// num �� ���� �Է� ���� ��
// num �� ��������, �������, 0 ������ �˻��Ͽ�
// ������� num �� �����Դϴ�.
// ������ num �� ����Դϴ�.
// 0 �̶�� num �� 0 �Դϴ�.
// �� ������ּ��� !

// ���� : if, else if, else �� ��� Ȱ�����ּ���!
#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int num;
	scanf("%d", &num);

	if (num < 0) {
		printf("num�� �����Դϴ�.\n");
	}
	else if (num > 0) {
		printf("num�� ����Դϴ�.\n");
	}
	else {
		printf("num�� 0�Դϴ�.\n");
	}
	return 0;
}