#include <stdio.h>
#include <windows.h>

// 콘솔 명령어
// 콘솔창을 실행할 때 특정한 기능을 사용할 수 있는 명령어
// windows.h 를 추가시켜야 사용이 가능합니다.

int main()
{
	int count = 1;

	while (1)
	{
		printf("%d   ", count);
		++count;
		// Sleep(500);
		// Sleep() : 특정 시간동안 명령을 대기합니다.
		system("pause");
		// system("pause") : 다음 키를 입력 받을 때까지 명령을 대기합니다.
		system("cls");
		// system("cls") : 콘솔창을 모두 지웁니다.
	}

	return 0;
}