#include <stdio.h>
#pragma warning(disable : 4996);
int main()
{
	// 배열의 선언과 동시에 초기화를 하실 수 있습니다.
	int arr[3] = { 1, 2, 3 };

	int arr2[] = { 1, 2, 3 };

	char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	// '\0' (널문자)
	// 컴퓨터가 문자열의 끝을 구분하기 위해서 사용합니다.

	printf("%s \n", str1);

	char str2[] = "Helloworld!";
	printf("%s \n", str2);

	char str3[256];
	printf("문자열을 입력하세요: ");
	scanf("%s", str3);
	// 문자열을 입력받을 때는 & 를 생략하셔도 됩니다.
	printf("입력받은 문자열 : %s \n", str3);
	return 0;
}