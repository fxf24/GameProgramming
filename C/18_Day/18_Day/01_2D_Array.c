#include <stdio.h>

// 다차원 배열
// - 배열을 요소로 갖는 배열을 의미합니다.
// - 1차원 배열을 요소로 갖는 2차원 배열
// - 2차원 배열을 요소로 갖는 3차원 배열

int main()
{
	// 2 차원 배열 선언
	// int myArray[Height][Width]
	int myArray[5][5];

	myArray[2][2] = 15;
	
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			count++;
			myArray[i][j] = count;
			printf("[ %d ] ", myArray[i][j]);
		}
		printf("\n");
	}

	return 0;
}