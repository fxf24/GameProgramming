#include <stdio.h>
#pragma warning (disable: 4996)

void Add(int n1, int n2) {
	printf("���ϱ� : %d \n", n1 + n2);
}
void Sub(int n1, int n2) {
	printf("���� : %d \n", n1 - n2);
}
void Mul(int n1, int n2) {
	printf("���ϱ� : %d \n", n1 * n2);
}
void Div(int n1, int n2) {
	printf("������ : %.2f \n", (float)n1 / n2);
}
void Rem(int n1, int n2) {
	printf("������ : %d \n", n1 % n2);
}

// �Ű������� �迭�� �޽��ϴ�.
void PrintArray(int arr[]) {
	for (int i = 0; i < 5; i++) {
		printf("Array[%d] = %d \n", i, arr[i]);
	}
}
int main()
{
	int Array[5] = { 1, 2, 3, 4, 5 };
	PrintArray(Array);


	int num1 = 0;
	int num2 = 0;

	printf("num1 �� �Է��ϼ��� : ");
	scanf("%d", &num1);
	printf("num2 �� �Է��ϼ��� : ");
	scanf("%d", &num2);
	
	// Add, Sub, Mul, Div, Rem �̶�� �Լ��� �����
	// +, -, *, /, % ������ �Ͽ� ����� ����ϴ� �Լ��� ������ּ���.
	Add(num1, num2);
	Sub(num1, num2);
	Mul(num1, num2);
	Div(num1, num2);
	Rem(num1, num2);

	return 0;
}