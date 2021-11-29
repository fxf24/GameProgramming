#include <stdio.h>

int main()
{
	int arr[4][5];

	int count = 20;
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j >= 0; j--) {
			arr[i][j] = count;
			count--;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] >= 10) {
				printf(" %d", arr[i][j]);
			}
			else {
				printf("  %d", arr[i][j]);
			}
		}
		printf("\n");
	}

	return 0;
}