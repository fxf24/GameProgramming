#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int num;
	scanf("%d", &num);

	/*if (num == 1) {
		printf("num �� 1�Դϴ�.\n");
	}
	else if (num == 2) {
		printf("num �� 2�Դϴ�.\n");
	}
	else if (num == 3) {
		printf("num �� 3�Դϴ�.\n");
	}
	else {
		printf("num �� 1,2,3�� �ƴմϴ�.\n");
	}*/

	// switch (�˻��� ��)
	switch (num) {
		//num �� ���̽��� �����մϴ�.
		//num �� 1�̶��
	case 1:
		printf("num �� 1�Դϴ�.\n");
		break;
		//num �� 2���
	case 2:
		printf("num �� 2�Դϴ�.\n");
		break;
		//num �� 3�̶��
	case 3:
		printf("num �� 3�Դϴ�.\n");
		break;
		// default : ���� �´� ���̽��� ���ٸ� �����մϴ�.
	default : 
		printf("num �� 1, 2, 3 �� �ƴմϴ�. \n");
		break;
	}
	
	return 0;
}