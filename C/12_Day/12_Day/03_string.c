#include <stdio.h>
#pragma warning (disable: 4996)

int main()
{
	char str[256];

	for (int i = 0; i < 3; i++) {
		printf("�Է� : ");
		scanf("%[^\n]s", str);
		printf("�Է¹��� ���ڿ� : %s\n", str);
		getchar();
	}


	return 0;
}