#include <stdio.h>

int PrintHello(int a)
{
	printf("Hello! \n");

	return a;
}

// �Լ�������
// - �Լ��� �̸��� �Լ��� �����ϰ� �ִ� �޸��� �ּ��Դϴ�.
//   �Լ��� �����ϴ� �ּҸ� �����Ͽ� �Լ��� ����Ű�� �����ͺ����� �ǹ��մϴ�.

void Addten(int a)
{
	a += 10;
	printf("10 �� ���� ���� : %i �Դϴ�.\n", a);
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
	printf("PrintHello �� ����� �ּ� : %p \n", PrintHello);

	// �Լ� ������ ���� ���
	// ��ȯŸ��(*�Լ������͸�)(�Լ� �Ű� ���� Ÿ��) = �Լ���
	int(*PFunc)(int) = PrintHello;
	
	// () : �Լ� ȣ�� ������
	// �ش� �ּ��� �Լ��� ȣ�����ִ� �������Դϴ�.

	PFunc(10);

	void(*at)(int) = Addten;
	int(*sub)(int, int) = Sub;
	double(*div)(double, double) = Div;

	/*at(10);
	printf("%d\n", sub(20, 10));
	printf("%f\n", div(20, 10));*/
	return 0;
}