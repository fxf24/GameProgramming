#include <stdio.h>

int main()
{
	// 1부터 11까지 증가할 값을 가지고 있을 변수
	int count = 1;

	// count 의 값이 10 이하라면 반복하는 반복문입니다.
	while (count <= 5) {
		printf("해당 반복문이 %d번째 반복 수행중입니다. \n", count);
		printf("count == %d \n\n", count);
		++count;
	}


	return 0;
}