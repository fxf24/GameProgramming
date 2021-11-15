#include <stdio.h>

int main()
{
	// 큰 한줄을 구분할 때 사용할 변수
	int bigLine = 1;

	while (bigLine < 4) {
		int smallLine = 1;

		while (smallLine < 10) {
			int start = (bigLine * 3) - 2;
			int end = start + 3;
			
			// 한줄을 출력하는 반복문입니다.
			while (start < end) {
				int result = start * smallLine;
				printf("%d X %d = %d %s    ", start, smallLine, result, ((result < 10) ? " ": "" ));
				++start;
			}

			++smallLine;
			printf("\n");
		}

		++bigLine;
		printf("\n");
	}

	return 0;
}