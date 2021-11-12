#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int num;
	printf("구구단 몇 단을 출력할까요 ?");
	scanf("%d", &num);

	int i = 1;
	while (i < 10) {
		printf("%d X %d = %d\n", num, i, num * i);
		i++;
	}

	int sum = 0;
	i = 1;
	while (i <= 100) {
		sum += i;
		i++;
	}
	printf("%d\n", sum);

	sum = 1;
	i = 2;
	while (i <= 10) {
		sum *= i;
		i++;
	}
	printf("%d\n", sum);

	return 0;
}