#include <stdio.h>

int main()
{
	// ū ������ ������ �� ����� ����
	int bigLine = 1;

	while (bigLine < 4) {
		int smallLine = 1;

		while (smallLine < 10) {
			int start = (bigLine * 3) - 2;
			int end = start + 3;
			
			// ������ ����ϴ� �ݺ����Դϴ�.
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