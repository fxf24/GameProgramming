#include <stdio.h>
#pragma warning (disable:4996)

struct Human {
	int age;
	float height;
	float weight;
};

int main()
{
	struct Human human;

	printf("���̸� �Է����ּ��� : ");
	scanf("%d", &human.age);
	printf("Ű�� �Է����ּ��� : ");
	scanf("%f", &human.height);
	printf("�����Ը� �Է����ּ��� : ");
	scanf("%f", &human.weight);

	printf("�� ����� ���̴� %d ��\n", human.age);
	printf("�� ����� Ű�� %.1f cm\n", human.height);
	printf("�� ����� �����Դ� %.1f kg\n", human.weight);

	return 0;
}