#include <stdio.h>

int main()
{
	int A = 1;

	while (A <= 3) {
		printf("���ǽ��� A <= 3 �� �ݺ����� %d ��° �ݺ��մϴ�. \n\n", A);
		++A;

		int B = 1;
		while (B <= 3) {
			printf("���ǽ��� B <= 3 �� �ݺ����� %d��° �ݺ��մϴ�. \n", B);
			++B;
		}
		printf("\n");
	}


	return 0;
}