#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	int myArray[100];
	srand(GetTickCount64());
	for (int i = 0; i < 100; i++) {
		myArray[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < 100; i++) {
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}

	return 0;
}