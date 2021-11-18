#include <stdio.h>
#pragma warning (disable: 4996)

int main()
{
	char str[256];

	for (int i = 0; i < 3; i++) {
		printf("입력 : ");
		scanf("%[^\n]s", str);
		printf("입력받은 문자열 : %s\n", str);
		getchar();
	}


	return 0;
}