#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996);

int main()
{
	while (1)
	{
		int num;
		printf("���ڸ� �Է��ϼ��� : ");
		scanf("%d", &num);

		if (num <= 10) {
			printf("number �� ���� 10 �����Դϴ�. \n");
			system("pause");
			system("cls");
		}
		else {
			printf("number �� ���� 11 �̻��Դϴ�. \n");
			break;
		}
	}


	return 0;
}