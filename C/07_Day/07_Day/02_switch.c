#include <stdio.h>
#pragma warning(disable : 4996)

int main() {
	int num;
	scanf("%d", &num);

	switch (num) {
	case 0:
		printf("num 은 0 입니다.\n");
		break;
	default:
		if (num % 2 == 0) {
			printf("num 은 짝수 입니다.\n");
		}
		else if (num % 2 == 1 || num % 2 == -1) {
			printf("num 은 홀수 입니다.\n");
		}
		if (num < 0) {
			printf("num 은 음수 입니다.\n");
		}
		break;
	}

	return 0;
}