#include <stdio.h>
#pragma warning(disable: 4996)
#include <string.h>
// string.h : 문자열을 다룰 수 있는 코드를 제공하는 파일입니다.

int main()
{
	char myString1[] = "Hello World";

	// 문자열 길이 구하기
	int length = strlen(myString1);
	// strlen(str) = str 의 길이를 나타냅니다.

	printf("myString1 의 길이 : %d \n", length);

	char myString2[] = "Apple";
	printf("myString1 = %s\n", myString1);
	printf("변환 \n");
	strcpy(myString1, myString2);
	// strcpy(str1, str2) : str1 의 문자열을 str2 가 가지고 있는 문자열로 초기화 시킵니다.
	printf("myString1 = %s\n", myString1);

	char myString3[] = "Melon";
	printf("(myString1 == myString2) = %s \n", (strcmp(myString1, myString2) == 0 ? "True" : "False"));
	printf("(myString1 == myString3) = %s \n", (strcmp(myString1, myString3) == 0 ? "True" : "False"));
	// strcmp(str1, str2) : str1 과 str2 가 가지고 있는 문자열을 비교합니다. 문자열이 같다면 0을, 다르면 -1 혹은 1을 반환합니다.

	return 0;
}