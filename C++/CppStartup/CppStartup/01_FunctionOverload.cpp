#include <iostream>

// �Լ� ȣ��� ȣ�� ����� ã�� ����
// C   : �Լ���
// C++ : �Լ���, �Ķ���� Ÿ��

// �̸� �̿��Ͽ� ���� �̸��� �Լ��� �ߺ������ϴ� ���� "�Լ� �����ε�" �̶� �մϴ�.

void Print(int num) {
	printf("num(int) : %i \n", num);
}

void Print(double num) {
	printf("num(double) : %.2lf \n", num);
}

int main() {
	Print(10);
	Print(3.14);
	return 0;
}