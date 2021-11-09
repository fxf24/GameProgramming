#include <stdio.h>

// 단항 연산자 혹은 증감 연산자
// - 피 연산자가 1개인 연산자
// - 증가 감소에 따라
//   증가, 감소 연산자
// - 위치에 따라
//   전위, 후위 연산자

int main()
{
	int count = 0;

	// 증감에 따라
	// 증가 연산자 : ++
	// 피연산자의 값을 1 증가시킵니다.
	++count;
	printf("count = %d \n", count);
	// 감소 연산자 : --
	// 피연산자의 값을 1 감소시킵니다.
	--count;
	printf("count = %d \n", count);

	// 위치에 따라
	// 전위 연산자
	// - 연산자를 변수 앞에 사용합니다.
	//   연산 후의 결과값을 나타냅니다.
	printf("count = %d \n", ++count);

	// 후위 연산자
	// - 연산자를 변수 뒤에 사용합니다.
	//   연산 전의 결과값을 나타냅니다.
	printf("count = %d \n", count++);
	printf("count = %d \n", count);
	return 0;
}