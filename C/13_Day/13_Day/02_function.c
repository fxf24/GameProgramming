#include <stdio.h>
#pragma warning (disable:4996)

// ��ȯ���� �����ϴ� �Լ�
// - ��ȯ ���� �����ϴ� �Լ��� ��ȯ ������ void �� �ƴ� �Լ���
//   �ǹ��մϴ�. return �� �̿��Ͽ� ��� ��� ���� ��ȯ�ؾ� �մϴ�.

// return 
// - �������̸�, �Լ��� ������ �ߴ��ϸ� ���α׷��� �帧�� ȣ���ڿ��� ���������ϴ�.
// - ��ȯ ������ void ������ ��� return; ���� �Լ� ������ ������ �� �ֽ��ϴ�.

// �Լ��� ����� ���ÿ� ���ǰ� �����մϴ�.
// ��ȯ ���� : int
// �Լ���    : InputNumber
// �Ű�����  : �����ϴ�.
//
int InputNumber()
{
	// InputNumber �� ȣ���� ��� ������ �ڵ带 �ۼ��մϴ�.
	int inputNumber;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%d", &inputNumber);

	// InputNumber �� ������� �츮�� �Է��� ���� ��ȯ�ϵ��� �մϴ�.
	return inputNumber;
}

// main ���� int ���� ��ȯ�ϴ� �Լ��Դϴ�.
int main()
{
	// InputNumber �� ȣ���Ͽ� ������� num �� �����մϴ�.
	int num = InputNumber();
	printf("num = %d \n", num);

	return 0;
}