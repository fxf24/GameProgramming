#include <stdio.h>

// 형식 변환 (캐스팅) 연산자 
// - 피 연산자의 데이터 형식을 원하는 형식으로
//   변환하는 연산자를 의미합니다.

// 사용 방법
// (변환할 타입) 피 연산자

int main() 
{
	int myInt;
	float myFloat = 3.14f;

	(float)myInt = myFloat;
	
	printf("myInt = %.2f\n", (float)myInt);

	int myA = 65;
	printf("myA = %c \n", (char)myA);

	return 0;
}