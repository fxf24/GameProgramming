#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main()
{
	int lower=0, upper=0;
	char str[256];
	printf("입력 : ");
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 65 && str[i] <= 91) {
			upper++;
		}
		if (str[i] >= 97 && str[i] <= 123) {
			lower++;
		}
	}
	printf("입력받은 문자열 소문자 변환!\n");
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 65 && str[i] <= 91) {
			str[i] += 32;
		}
	}
	printf("%s\n", str);
	printf("입력받은 문자열 대문자 변환!\n");
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 97 && str[i] <= 123) {
			str[i] -= 32;
		}
	}
	printf("%s\n", str);
	printf("소문자 개수 : %d\n", lower);
	printf("대문자 개수 : %d\n", upper);

	return 0;
}