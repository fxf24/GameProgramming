#include <stdio.h>

typedef struct test4 {
	int number[6];
}Test4;
typedef struct test3 {
	Test4 test4[2];
}Test3;
typedef struct test2 {
	Test3 test3[5];
}Test2;
typedef struct test5 {
	Test2 test2;
}Test5;
int main()
{
	Test5 test;

	test.test2.test3[4].test4[1].number[5] = 10;

	return 0;
}