#include <stdio.h>
#pragma warning(disable : 4996)

int main() {
	int num;
	scanf("%d", &num);

	switch (num) {
	case 0:
		printf("num �� 0 �Դϴ�.\n");
		break;
	default:
		if (num % 2 == 0) {
			printf("num �� ¦�� �Դϴ�.\n");
		}
		else if (num % 2 == 1 || num % 2 == -1) {
			printf("num �� Ȧ�� �Դϴ�.\n");
		}
		if (num < 0) {
			printf("num �� ���� �Դϴ�.\n");
		}
		break;
	}

	return 0;
}