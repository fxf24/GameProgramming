#include <stdio.h>

int main()
{
	int A = 1;

	while (A <= 3) {
		printf("조건식이 A <= 3 인 반복문이 %d 번째 반복합니다. \n\n", A);
		++A;

		int B = 1;
		while (B <= 3) {
			printf("조건식이 B <= 3 인 반복문이 %d번째 반복합니다. \n", B);
			++B;
		}
		printf("\n");
	}


	return 0;
}