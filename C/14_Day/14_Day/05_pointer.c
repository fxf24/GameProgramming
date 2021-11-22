#include <stdio.h>

// ������ �Ű�����
// �Ű������� �ڷ������� �����͸� ��� �����մϴ�.

// Call by Value
void VAddTen(int a) {
	a += 10;
}

// ������ �Ű����� p �� ���� PAddTen�� �����մϴ�.
// Call by Address
void PAddTen(int* p) {
	*p += 10;
}

int main()
{
	int a = 10;
	printf("a = %i\n", a);

	printf("VAddTen ������ \n");
	VAddTen(a);				// �Ű����� (int a = a;)
	printf("a = %i\n", a);

	printf("PAddTen ������\n");
	PAddTen(&a);			// �Ű����� (int* p = &a;)
	// ������ �Ű������� ���� ������ �� �ּҰ��� �Ѱ��ݴϴ�.
	printf("a = %i\n", a);


	return 0;
}