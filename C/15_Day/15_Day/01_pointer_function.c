#include <stdio.h>

int PrintHello(int a)
{
	printf("Hello! \n");

	return a;
}

// 함수포인터
// - 함수의 이름은 함수가 존재하고 있는 메모리의 주소입니다.
//   함수가 존재하는 주소를 저장하여 함수를 가리키는 포인터변수를 의미합니다.

void Addten(int a)
{
	a += 10;
	printf("10 을 더한 값은 : %i 입니다.\n", a);
}

int Sub(int a, int b)
{
	return a - b;
}

double Div(double a, double b)
{
	return a / b;
}
int main()
{
	printf("PrintHello 가 저장된 주소 : %p \n", PrintHello);

	// 함수 포인터 선언 방법
	// 반환타입(*함수포인터명)(함수 매개 변수 타입) = 함수명
	int(*PFunc)(int) = PrintHello;
	
	// () : 함수 호출 연산자
	// 해당 주소의 함수를 호출해주는 연산자입니다.

	PFunc(10);

	void(*at)(int) = Addten;
	int(*sub)(int, int) = Sub;
	double(*div)(double, double) = Div;

	/*at(10);
	printf("%d\n", sub(20, 10));
	printf("%f\n", div(20, 10));*/
	return 0;
}