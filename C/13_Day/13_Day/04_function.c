#include <stdio.h>
#pragma warning (disable: 4996)

void Add(int n1, int n2) {
	printf("더하기 : %d \n", n1 + n2);
}
void Sub(int n1, int n2) {
	printf("빼기 : %d \n", n1 - n2);
}
void Mul(int n1, int n2) {
	printf("곱하기 : %d \n", n1 * n2);
}
void Div(int n1, int n2) {
	printf("나누기 : %.2f \n", (float)n1 / n2);
}
void Rem(int n1, int n2) {
	printf("나머지 : %d \n", n1 % n2);
}

int main()
{
	int num1 = 0;
	int num2 = 0;

	printf("num1 을 입력하세요 : ");
	scanf("%d", &num1);
	printf("num2 을 입력하세요 : ");
	scanf("%d", &num2);
	
	// Add, Sub, Mul, Div, Rem 이라는 함수를 만들어
	// +, -, *, /, % 연산을 하여 결과를 출력하는 함수를 만들어주세요.
	Add(num1, num2);
	Sub(num1, num2);
	Mul(num1, num2);
	Div(num1, num2);
	Rem(num1, num2);

	return 0;
}