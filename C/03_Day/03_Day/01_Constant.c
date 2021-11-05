#include <stdio.h>

// 상수 : 변경할 수 없는 값

// const : 어떠한 공간의 값을 변경하지 못하도록 하는 키워드 입니다.

int main()
{
	int num = 10;
	printf("num = %d \n", num);
	num = 20;
	printf("num = %d \n", num);

	// 자료형 앞에 const를 사용합니다.
	// const 키워드를 사용한다면 선언과 동시에 초기화를 해주셔야 합니다.
	const int num2 = 20;
	// const 키워드를 사용한 공간의 값은 변경하지 못합니다.
	// num2 = 30;
	return 0;
}