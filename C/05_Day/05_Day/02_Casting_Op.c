#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	// ��ǥ ����� ������ ������ �����մϴ�.
	float Waverage;

	// Want �� �Է°��� �����մϴ�.
	printf("���ϴ� ����� �Է����ּ��� : ");
	scanf("%f", &Waverage);

	// �� ������ ������ ������ ������ �����մϴ�.
	int Kor, Mat, Eng;
	printf("���������� �Է����ּ��� : ");
	scanf("%d", &Kor);
	printf("���������� �Է����ּ��� : ");
	scanf("%d", &Mat);
	printf("���������� �Է����ּ��� : ");
	scanf("%d", &Eng);

	// ������ ������� ���� ���°� �ƴ�
	// float ���·� ������� ��Ÿ���ϴ�.
	float average;
	average = (float)(Kor + Mat + Eng) / 3;

	// ��ǥ ��տ� ���� �Ͽ������� �˻��մϴ�.
	char reach = average >= Waverage;

	printf("��� : %.2f\n", average);
	printf("��ǥ �޼� : %d\n", reach);

	return 0;
}