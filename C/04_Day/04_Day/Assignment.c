// �ٶ���� �ϴ� ��� ���� float �� ������ �������ּ���.
// ����, ����, ���� ������ ������ int �� ���� Kor, Mat, Eng ������ �����
// scanf()�� ���� ������ �Է��Ͽ� �����
// float�� ������ �����Ͽ� �Ҽ��� ù°�ڸ����� ������ּ���
// �ٶ�����ϴ� ������ ���Դٸ� 1�� �ƴ϶�� 0�� ������ּ��� !

#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	float Waverage, average;
	int Kor, Mat, Eng;
	printf("���ϴ� ����� �Է����ּ��� : ");
	scanf("%f", &Waverage);
	printf("���������� �Է����ּ��� : ");
	scanf("%d", &Kor);
	printf("���������� �Է����ּ��� : ");
	scanf("%d", &Mat);
	printf("���������� �Է����ּ��� : ");
	scanf("%d", &Eng);
	average = (float)(Kor + Mat + Eng) / 3;
	printf("��� : %.1f\n", average);
	printf("%d", average >= Waverage);

	return 0;
}