#include <stdio.h>

int main()
{
	int var1 = 10;
	int var2 = 20;

	// 포인터 변수의 const 는 위치에 따라 의미가 달라집니다.
	const int*		 p1 = &var1;
	p1 = &var2;		 // 가리키는 주소 변경 가능
	// *p1 = 100;    // 간접 참조를 통한 값 변경 불가능
	
	int* const		 p2 = &var1;
	// p2 = &var2;   // 가리키는 주소 변경 불가능
	*p2 = 100;		 // 간접 참조를 통한 값 변경 가능

	const int* const p3 = &var1;
	// p3 = &var2;	 // 가리키는 주소 변경 불가능
	// *p3 = 100;	 // 간접 참조를 통한 값 변경 불가능

	return 0;
}