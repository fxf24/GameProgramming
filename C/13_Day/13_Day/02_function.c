#include <stdio.h>
#pragma warning (disable:4996)

// 반환값이 존재하는 함수
// - 반환 값이 존재하는 함수란 반환 형식이 void 가 아닌 함수를
//   의미합니다. return 을 이용하여 어떠한 결과 값을 반환해야 합니다.

// return 
// - 점프문이며, 함수의 실행을 중단하며 프로그램의 흐름을 호출자에게 돌려놓습니다.
// - 반환 형식이 void 형식인 경우 return; 으로 함수 실행을 종료할 수 있습니다.

// 함수의 선언과 동시에 정의가 가능합니다.
// 반환 형식 : int
// 함수명    : InputNumber
// 매개변수  : 없습니다.
//
int InputNumber()
{
	// InputNumber 를 호출할 경우 실행할 코드를 작성합니다.
	int inputNumber;
	printf("숫자를 입력하세요 : ");
	scanf("%d", &inputNumber);

	// InputNumber 의 결과값을 우리가 입력한 값을 반환하도록 합니다.
	return inputNumber;
}

// main 또한 int 형을 반환하는 함수입니다.
int main()
{
	// InputNumber 를 호출하여 결과값을 num 에 저장합니다.
	int num = InputNumber();
	printf("num = %d \n", num);

	return 0;
}