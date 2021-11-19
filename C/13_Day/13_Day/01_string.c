#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

int main()
{
	// 아스키 코드 참조 변수
	const char upper_start = 'A';
	const char upper_end = 'Z';
	const char lower_start = 'a';
	const char lower_end = 'z';

	// 문자열 입력
	char inputString[256];
	printf("입력 : ");
	scanf("%[^\n]s", inputString);
	
	// 개행 문자 제거
	getchar();

	// 대소문자 개수 출력
	// 대문자의 개수를 저장할 변수
	int upperCount = 0;
	// 소문자의 개수를 저장할 변수
	int lowerCount = 0;

	// 입력받은 문자열의 길이 만큼 반복
	for (int i = 0; i < strlen(inputString); i++) {
		// 대문자 인지 검사합니다.
		if (upper_start <= inputString[i] && inputString[i] <= upper_end) {
			upperCount++;
		}
		// 소문자 인지 검사합니다.
		else if (lower_start <= inputString[i] && inputString[i] <= lower_end) {
			lowerCount++;
		}
	}
	printf("대문자 개수 : %d \n", upperCount);
	printf("소문자 개수 : %d \n", lowerCount);

	// 대문자로 변환합니다.
	for (int i = 0; i < strlen(inputString); i++) {
		if (lower_start <= inputString[i] && inputString[i] <= lower_end) {
			inputString[i] -= 32;
		}
	}

	printf("대문자로 변환합니다.\n");
	printf("%s \n",inputString);

	// 소문자로 변환합니다.
	for (int i = 0; i < strlen(inputString); i++) {
		if (upper_start <= inputString[i] && inputString[i] <= upper_end) {
			inputString[i] += 32;
		}
	}

	printf("소문자로 변환합니다.\n");
	printf("%s \n", inputString);

	return 0;
}