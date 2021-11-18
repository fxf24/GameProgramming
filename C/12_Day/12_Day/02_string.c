#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char str1[256];

	printf("띄어쓰기가 있는 문자열을 입력하세요 : ");
	scanf("%[^\n]s", str1);
	// %[^\n]s : \n (개행문자) 를 기준으로 버퍼에서 데이터를 끌어와 저장합니다.
	//str1[7] = getchar();
	//str1[6] = getchar();
	//str1[8] = getchar();
	//str1[5] = getchar();
	//str1[9] = getchar();
	//str1[10] = getchar();
	//str1[11] = '\0';

	printf("입력받은 문자열 : %s\n", str1);
	// getchar() : 버퍼에 남아있는 데이터를 하나씩 반환합니다.
	getchar();

	char str2[256];
	printf("띄어쓰기가 있는 문자열을 입력하세요 : ");
	scanf("%[^\n]s", str2);
	printf("입력받은 문자열 : %s\n", str2);

	return 0;
}