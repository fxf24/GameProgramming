#include <stdio.h>

int main()
{

	int i = 1;
	while (i <= 7) {
		int j = 1;
		while (j <= 9) {
			printf("%d X %d = %d\t", i, j, i * j);
			printf("%d X %d = %d\t", i+1, j, (i+1) * j); 
			printf("%d X %d = %d\n", i+2, j, (i+2) * j);
			j++;
		}
		printf("\n");
		i += 3;
	}
	return 0;
}