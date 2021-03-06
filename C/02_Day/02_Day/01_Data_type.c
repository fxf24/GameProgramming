#include <stdio.h>

// 변수
// - 값을 대입시켜 변화시킬 수 있는 요소를 뜻합니다.

// 자료형
// - 데이터의 형식을 의미합니다.

// 자료형의 종류
// [데이터 형식]		[크기(byte)]		[나타낼 수 있는 값의 범위]
// - char				1					-128 ~ 127
// - short				2					-32768 ~ 32767
// - int				4					약 -21억 ~ 약 21억
// - long				4					약 -21억 ~ 약 21억
// - long long			8					약 -922경 ~ 약 922경

int main() 
{
	// 변수 선언
	// "자료형" "변수 이름";
	
	// 주의 사항
	// 변수의 이름 사이에는 공백을 포함시킬 수 없습니다.
	// ex ) my Char
	// 변수의 이름으로 미리 정의된 키워드는 사용할 수 없습니다.
	// ex ) char char
	// 변수의 이름의 첫 시작에는 숫자를 사용할 수 없습니다.
	// ex ) char 1char
	
	// 소스 코드는 대소문자를 구분합니다.
	char myChar;
	
	// 변수에 값을 대입시키는 것을 초기화라 합니다.
	// 초기화 방법 : 변수 이름 = 값;
	myChar = 1;

	// 형식 문자
	// 데이터의 형식에 맞게 표현할 수 있도록 도와주는 문자를 의미합니다.
	// %d : 정수 형태를 받아 출력합니다.
	printf("myChar = %d\n", myChar);

	// 변수의 선언과 동시에 초기화 방법
	// "자료형" "변수이름" = "값";
	char A = 'a';
	// %c : 문자 형태로 출력합니다.
	printf("A = %c \n", A);

	// %s : 문자열을 받아 출력합니다.
	printf("%s \n", "안녕하세요");

	printf("myChar 는 %d 이고 A 는 %c 출력할 문자열은 %s 입니다. \n", myChar, A, "안녕하세요");
	return 0;
}