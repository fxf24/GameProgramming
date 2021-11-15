#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
	srand(GetTickCount64());

	for (int i = 0; i < 10; i++) {
		int random = rand() % 101;
		printf("%d ¹øÂ° »ÌÀº ¼ö : %d\n", i+1, random);
	}

	return 0;
}