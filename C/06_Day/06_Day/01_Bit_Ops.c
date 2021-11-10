#include <stdio.h>
#pragma warning(disable : 4996)

#include <string.h>

const char* convertB(int value) {
	static char b[9];
	b[0] = '\0';

	for (int z = 128; z > 0; z >>= 1)
		strcat(b, ((value & z) == z) ? "1" : "0");

	return b;
}

int main()
{
	int bit1 = 100;
	int bit2 = 120;

	printf("100(2) = %s \n", convertB(bit1));
	printf("<< 연산 \n");
	bit1 = bit1 << 2;

	printf("bit1 << 2 = %s \n", convertB(bit1));
	printf(">> 연산 \n");
	bit1 = bit1 >> 3;
	printf("bit1 >> 3 = %s \n", convertB(bit1));

	int result;

	printf("& 연산 \n");
	result = bit1 & bit2;
	printf(" 50(2) %s \n", convertB(bit1));
	printf("120(2) %s &\n", convertB(bit2));
	printf("       %s \n", convertB(result));

	printf("| 연산 \n");
	result = bit1 | bit2;
	printf(" 50(2) %s \n", convertB(bit1));
	printf("120(2) %s |\n", convertB(bit2));
	printf("       %s \n", convertB(result));

	printf("^ 연산 \n");
	result = bit1 ^ bit2;
	printf(" 50(2) %s \n", convertB(bit1));
	printf("120(2) %s ^\n", convertB(bit2));
	printf("       %s \n", convertB(result));

	printf("~ 연산 \n");
	result = ~bit1;
	printf(" 50(2) %s \n", convertB(bit1));
	printf("                ~\n");
	printf("       %s \n", convertB(result));

	return 0;
}