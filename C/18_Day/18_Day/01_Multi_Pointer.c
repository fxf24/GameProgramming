#include <stdio.h>

// 다중 포인터
// 포인터 변수의 주소값을 저장할 수 있는 포인터를 의미합니다.

int main() {
	// int 형 변수 num 을 선언합니다.
	int num = 10;

	int* p = &num;

	int** pp = &p;

	int* p2 = &p;

	printf("num = %d \n", num);
	printf("&num = %p \n", &num);
	printf("p = %p \n", p);
	printf("*p = %d \n", *p);
	printf("&p = %p \n", &p);
	printf("pp = %p \n", pp);
	printf("*pp = %p \n", *pp);
	printf("**pp = %d \n", **pp);

	printf("p2 = %p \n", p2);
	printf("*p2 = %p \n", *p2);
	printf("&p2 = %p \n", &p2);

	return 0;
}