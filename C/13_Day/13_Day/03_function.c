#include <stdio.h>
#pragma warning (disable: 4996)

// 매개 변수가 존재하는 함수
// 반환 형 : int
// 함수명 : PrintAge
// 매개변수 : int birthYear
int PrintAge(int birthYear) {
	// 현재 년도를 저장할 변수
	const int currentYear = 2021;

	// 자신의 나이를 구하여 저장합니다.
	int age = currentYear - birthYear + 1;
	
	printf("당신의 나이는 %d 세 입니다.\n", age);
	
	return age;
}

void PrintNumbers(int num1, float num2, int num3) {
	printf("num1 에 전달 받은 값 : %d\n", num1);
	printf("num2 에 전달 받은 값 : %.2f\n", num2);
	printf("num3 에 전달 받은 값 : %d\n", num3);
}

int main()
{
	int year;
	printf("당신이 태어난 년도를 입력하세요 : ");
	scanf("%d", &year);
	
	// PrintAge 를 호출합니다.
	// 호출할 함수명 : PrintAge
	// 매개변수에 전달할 인자 : year
	PrintAge(year);

	PrintNumbers(10, 3.14, 234);

	// 함수 사용시 주의할 점
	// 함수의 반환 형식과 반환값의 형식은 동일해야합니다.
	// 등록한 매개변수의 형식과 전달한 인자값의 형식은 동일하고
	// 인자값과 매개변수의 개수 또한 동일하여야합니다.

	return 0;
}