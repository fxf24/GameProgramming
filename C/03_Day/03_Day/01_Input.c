#include <stdio.h>
#pragma warning(disable : 4996)
// 4996 이라는 코드의 오류를 무시하도록 설정합니다.

int main()
{
	int Num;
	
	printf("숫자를 입력하세요 : ");
	scanf("%d", &Num);
	// scanf(입력받을 형식, &입력 받은 값을 저장할 변수);

	printf("입력 받은 숫자 : %d \n", Num);

	return 0;
}