#include <stdio.h>
#pragma warning (disable : 4996)

int main() {
	int time;
	printf("철수가 일한 시간을 입력하세요 : ");
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

	printf("철수의 임금 :%d\n", salary);

	return 0;
}