#include <stdio.h>
#pragma warning (disable: 4996)

// �Ű� ������ �����ϴ� �Լ�
// ��ȯ �� : int
// �Լ��� : PrintAge
// �Ű����� : int birthYear
int PrintAge(int birthYear) {
	// ���� �⵵�� ������ ����
	const int currentYear = 2021;

	// �ڽ��� ���̸� ���Ͽ� �����մϴ�.
	int age = currentYear - birthYear + 1;
	
	printf("����� ���̴� %d �� �Դϴ�.\n", age);
	
	return age;
}

void PrintNumbers(int num1, float num2, int num3) {
	printf("num1 �� ���� ���� �� : %d\n", num1);
	printf("num2 �� ���� ���� �� : %.2f\n", num2);
	printf("num3 �� ���� ���� �� : %d\n", num3);
}

int main()
{
	int year;
	printf("����� �¾ �⵵�� �Է��ϼ��� : ");
	scanf("%d", &year);
	
	// PrintAge �� ȣ���մϴ�.
	// ȣ���� �Լ��� : PrintAge
	// �Ű������� ������ ���� : year
	PrintAge(year);

	PrintNumbers(10, 3.14, 234);

	// �Լ� ���� ������ ��
	// �Լ��� ��ȯ ���İ� ��ȯ���� ������ �����ؾ��մϴ�.
	// ����� �Ű������� ���İ� ������ ���ڰ��� ������ �����ϰ�
	// ���ڰ��� �Ű������� ���� ���� �����Ͽ����մϴ�.

	return 0;
}