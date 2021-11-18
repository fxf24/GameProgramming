#include <stdio.h>
#pragma warning (disable:4996)

int main()
{
	char str[256];
	printf("입력 : ");
	scanf("%s", str);
	printf("입력받은 문자열 : %s\n", str);
	char str1[256];
	printf("입력 : ");
	scanf("%s", str1);
	printf("입력받은 문자열 : %s\n", str1);
	// scanf() 는 버퍼에 남아있는 데이터가 없다면 입력을 대기합니다.
	// 만약 남아있는 데이터가 존재한다면 공백 문자를 기준으로
	// 데이터를 끌어와 해당 변수에 저장을 하게 됩니다.
	// 
	// scanf 의 입력의 종료는 '\n' 를 입력 받게 된다면 종료됩니다.
	// 
	// Buffer : 입력을 처리할 떄 사용하는 컴퓨터의 데이터 공간입니다.
	//			공백 문자를 기준으로 버퍼에 있는 데이터를 끌어와 저장합니다.
	// 


	return 0;
}