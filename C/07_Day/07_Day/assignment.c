#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int time;
	printf("ö���� ���� �ð��� �Է��ϼ��� : ");
	scanf("%d", &time);

	if (time > 24) {
		time = 24;
	}
	int salary;
	if (time > 8) {
		int ex = time - 8;
		salary = 8 * 8720 + ex * 8720 * 1.5;
	}
	else {
		salary = time * 8720;
	}

	printf("ö���� �ӱ� :%d\n", salary);

	return 0;
}