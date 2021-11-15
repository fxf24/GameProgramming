#include <stdio.h>
#include <windows.h>

// continue
// 현재 실행중인 반복문의 반복을 한번 건너 뛰고자 할 때 사용합니다.


int main()
{
	int count = 1;

	while (count < 10)
	{
		printf("count = %d \n", count);

		Sleep(500);

		// 만약 count 가 5라면
		if (count == 5)
		{
			// 현재 반복을 멈추고 조건식으로 돌아갑니다.
			continue;
		}

		count++;

	}


	return 0;
}