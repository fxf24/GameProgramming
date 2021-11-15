#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// 난수
// 랜덤한 값을 의미합니다.
// stdlib.h 을 포함시켜야 사용이 가능합니다.

int main()
{
	// 난수 시드를 설정합니다.
	srand(GetTickCount64());
	// srand() : 컴퓨터에게 특정한 규칙으로 랜덤값을 뽑으라고 명령하는 구문입니다.
	// GetTickCount64() : 컴퓨터가 부팅할 때부터 지난시간을 밀리초 단위로 반환합니다.

	// 10 개의 랜덤값을 뽑는 반복문
	for (int i = 0; i < 10; ++i)
	{
		int randomvalue = rand() % 5;
		// 난수를 뽑는 방법
		// rand() 를 사용합니다.
		// rand() % n : 0 ~ (n - 1) 사이의 값 중 하나의 숫자를 뽑습니다.
		printf("뽑은 숫자 : %d \n", randomvalue);
	}

	return 0;
}