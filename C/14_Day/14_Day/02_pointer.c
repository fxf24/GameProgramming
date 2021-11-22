#include <stdio.h>

int main()
{
	int		  myInt		 = 0;
	float	  myFloat	 = 0;
	long long myLongLong = 0;

	int* ip;
	float* fp;
	long long* llp;
	ip = &myInt;
	fp = &myFloat;
	llp = &myLongLong;
	*ip = 30;
	*fp = 3.14f;
	*llp = 12345678;

	printf("myInt = %d\n", myInt);
	printf("myFloat = %.2f\n", myFloat);
	printf("myLongLong = %lld\n", myLongLong);

	return 0;
}