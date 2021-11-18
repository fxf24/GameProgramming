#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

int main()
{
	char str1[256];
	char str2[256];

	for (int i = 0; i < 2; i++) {
		char str[256];
		printf("문자열을 입력하세요 : ");
		scanf("%[^\n]s", str);
		printf("입력받은 문자열 [ %s ] :: 길이 [%d]\n", str, strlen(str));
		getchar();
		if (i == 0) {
			strcpy(str1, str);
		}
		else {
			strcpy(str2, str);
		}
	}
	
	printf("두 문자열은 %s\n", strcmp(str1, str2) == 0 ? "같습니다." : "다릅니다.");

	return 0;
}