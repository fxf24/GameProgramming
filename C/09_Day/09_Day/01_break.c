#include <stdio.h>

// 점프문
// - 프로그램의 흐름을 끊고 프로그램의 실행의 위치를
//   원하는 곳으로 도약시킬 떄 사용하는 구문입니다.


int main()
{
	// break : 현재 실행중인 반복문이나, switch 문의 실행을 중단 하고자할 때 사용합니다.
	int count = 1;
	
	while (1)
	{
		printf("count = %d \n", count);

		// 카운트의 값이 5라면
		if (count == 5) { 
			// 해당 반복문을 중단시킵니다.
			break; 
		}

		++count;
	}

	return 0;
}