#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

// 아스키 코드 참조 변수
const char upper_start = 'A';
const char upper_end = 'Z';
const char lower_start = 'a';
const char lower_end = 'z';

int printUpperCount(char word[]) {
	int count = 0;
	for (int i = 0; i < strlen(word); i++) {
		// 대문자 인지 검사합니다.
		if (upper_start <= word[i] && word[i] <= upper_end) {
			count++;
		}
	}
	printf("대문자 개수 : %d \n", count);
	
	return count;
}
int printLowerCount(char word[]) {
	int count = 0;
	for (int i = 0; i < strlen(word); i++) {
		// 소문자 인지 검사합니다.
		if (lower_start <= word[i] && word[i] <= lower_end) {
			count++;
		}
	}
	printf("소문자 개수 : %d \n", count);
	return count;
}
void printUpperCase(char word[]) {
	for (int i = 0; i < strlen(word); i++) {
		if (lower_start <= word[i] && word[i] <= lower_end) {
			word[i] -= 32;
		}
	}
	printf("대문자로 변환합니다.\n");
	printf("%s \n", word);
}
void printLowerCase(char word[]) {
	for (int i = 0; i < strlen(word); i++) {
		if (upper_start <= word[i] && word[i] <= upper_end) {
			word[i] += 32;
		}
	}
	printf("소문자로 변환합니다.\n");
	printf("%s \n", word);
}

int main()
{
	// 문자열 입력
	char inputString[256];
	printf("입력 : ");
	scanf("%[^\n]s", inputString);

	// 개행 문자 제거
	getchar();

	printUpperCount(inputString);
	printLowerCount(inputString);
	printUpperCase(inputString);
	printLowerCase(inputString);
	

	return 0;
}