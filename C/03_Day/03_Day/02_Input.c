#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int year, month, date;
	printf("����̰� �¾ �⵵�� �Է��ϼ��� : ");
	scanf("%d", &year);
	printf("����̰� �¾ ���� �Է��ϼ��� : ");
	scanf("%d", &month);
	printf("����̰� �¾ ���� �Է��ϼ��� : ");
	scanf("%d", &date);
	printf("�� ����̴� %d �� %d �� %d �Ͽ� �¾���ϴ�. \n", year, month, date);

	return 0;
}