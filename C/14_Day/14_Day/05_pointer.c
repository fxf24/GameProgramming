#include <stdio.h>

// 포인터 매개변수
// 매개변수의 자료형으로 포인터를 사용 가능합니다.

// Call by Value
void VAddTen(int a) {
	a += 10;
}

// 포인터 매개변수 p 를 갖는 PAddTen을 정의합니다.
// Call by Address
void PAddTen(int* p) {
	*p += 10;
}

int main()
{
	int a = 10;
	printf("a = %i\n", a);

	printf("VAddTen 실행후 \n");
	VAddTen(a);				// 매개변수 (int a = a;)
	printf("a = %i\n", a);

	printf("PAddTen 실행후\n");
	PAddTen(&a);			// 매개변수 (int* p = &a;)
	// 포인터 매개변수에 값을 전달할 땐 주소값을 넘겨줍니다.
	printf("a = %i\n", a);


	return 0;
}