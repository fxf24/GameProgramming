#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int num;
	printf("������ �� ���� ����ұ�� ?");
	scanf("%d", &num);

	int i = 1;
	while (i < 10) {
		printf("%d X %d = %d\n", num, i, num * i);
		i++;
	}

	return 0;
}