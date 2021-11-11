#include <stdio.h>

// 분기문
// - 프로그램의 실행흐름을 조건에 따라 가르는 문장을 의미합니다.

// if (조건식)
// { 실행할 코드;}
// 조건식이 만약에 참(1)이라면 {} 안에 잇는 코드를 실행하고
// 거짓(0)이라면 {} 안에 있는 코드를 실행하지 않고 다음 구문을 실행합니다.

// 조건식 : 0 이나 1을 결과값을 나타내는 식을 말합니다.
// 컴퓨터는 0을 거짓으로 1을 참으로 해석합니다.

int main()
{
	if (1) {
		printf("if문 실행!\n");
	}

	printf("다음 라인 코드 : Line[%d] \n", __LINE__);

	int a = 10;
	int b = 20;

	if (a > b){
		printf("a는 b 보다 큽니다. \n");
	}



	return 0;
}