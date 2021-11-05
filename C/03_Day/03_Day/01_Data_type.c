#include <stdio.h>

// unsigned : 자료형 앞에 사용하며 해당 자료형의 음수를 표현할 수 있는
//			  범위를 양수로 표현할 수 잇게 만듭니다.
//			  unsigned 붙이게 된다면 음수를 저장할 수 없습니다.

int main()
{
	// char 같은 경우 -128 ~ 127 까지 나타낼 수 있는 자료형 입니다.
	char number = 255;
	printf("number = %d \n", number);

	// unsigned 를 붙이게 된다면 -128 까지 나타낼 수 있는 음수의 범위를
	// 양수의 범위로 사용하게 되며 0 ~ 255까지 저장할 수 있게 됩니다.
	unsigned char uNumber = 255;
	printf("number = %d \n", uNumber);

	return 0;
}