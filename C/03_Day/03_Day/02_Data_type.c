#include <stdio.h>

// 실수 자료형
// [자료형]			[Byte]		[나타낼 수 있는 수의 범위]
// float			4byte		-3.4 * 10^-37 ~ 3.4 * 10^-38
// double			8byte		-1.7 * 10^-307 ~ 1.7 * 10^-308

int main()
{
	// float 같은 경우 값을 저장할 때 값 뒤에 f를 붙여주셔야 합니다.
	float	myFloat = 3.14f;
	double	myDouble = 1.234;

	// %f : float 형태의 변수를 출력할 때 사용합니다.
	printf("myFloat	 = %.2f		\n", myFloat);
	// %lf : double 형태의 변수를 출력할 떄 사용합니다.
	printf("myDouble = %.3lf	\n", myDouble);

	// 원하는 소수점 자리까지 출력하는 방법
	// % 뒤에 ".나타낼 소수점 자리" 를 작성하시면 됩니다.

	return 0;
}