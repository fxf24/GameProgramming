#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

// 아스키 코드 참조 변수
const char upper_start = 'A';
const char upper_end = 'Z';
const char lower_start = 'a';
const char lower_end = 'z';

void printUpperCount(char word[]) {
	int count = 0;

	for (int i = 0; i < strlen(word); i++) {
		// 대문자 인지 검사합니다.
		if (upper_start <= word[i] && word[i] <= upper_end) {
			count++;
		}
	}
	printf("대문자 개수 : %d \n", count);
}
void printLowerCount(char word[]) {
	int count = 0;

	for (int i = 0; i < strlen(word); i++) {
		// 소문자 인지 검사합니다.
		if (lower_start <= word[i] && word[i] <= lower_end) {
			count++;
		}
	}
	printf("소문자 개수 : %d \n", count);
}
void printUpperCase(char word[]) {
	char cpy[256];
	strcpy(cpy, word);

	for (int i = 0; i < strlen(cpy); i++) {
		if (lower_start <= cpy[i] && cpy[i] <= lower_end) {
			cpy[i] -= 32;
		}
	}
	printf("대문자로 변환합니다.\n");
	printf("%s \n", cpy);
}
void printLowerCase(char word[]) {
	char cpy[256];
	strcpy(cpy, word);

	for (int i = 0; i < strlen(cpy); i++) {
		if (upper_start <= cpy[i] && cpy[i] <= upper_end) {
			cpy[i] += 32;
		}
	}
	printf("소문자로 변환합니다.\n");
	printf("%s \n", cpy);
}

int main()
{
	// 문자열 입력
	char inputString[256];
	printf("입력 : ");
	scanf("%[^\n]s", inputString);

	// 개행 문자 제거
	getchar();

	printUpperCase(inputString);
	printLowerCase(inputString);
	printUpperCount(inputString);
	printLowerCount(inputString);

	return 0;
}