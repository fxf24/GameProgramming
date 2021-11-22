#include <stdio.h>

int main()
{
	//변수 선언
	int value1 = 10;
	int value2 = 20;

	// 포인터 변수 선언
	int* pointer1 = &value1;
	int* pointer2 = &value2;
	
	// value1 == 10 == *pointer1
	// value2 == 20 == *pointer2

	// &value1 == pointer1
	// &value2 == pointer2

	*pointer1 += value2;
	// value1 += value2;
	// value1 += *pointer2;
	// *pointer1 += *pointer2;
	printf("value1 = %i \n\n", value1);

	//pointer1 = &value2;
	//printf("*pointer1 = %i \n", *pointer1);

	// 모든 값 출력
	printf("value1 = %i\n", value1);
	printf("*pointer1 = %i\n\n", *pointer1);

	printf("value2 = %i\n", value2);
	printf("*pointer2 = %i\n\n", *pointer2);

	printf("&value1 = %p\n", &value1);
	printf("*pointer1 = %p\n\n", pointer1);

	printf("&value2 = %p\n", &value2);
	printf("*pointer2 = %p\n\n", pointer2);

	printf("&pointer1 = %p\n", &pointer1);
	printf("&pointer2 = %p\n\n", &pointer2);

	return 0;
}