#include <stdio.h>
#pragma warning(disable : 4996)
// for ��
// [�ʱ��, ���ǽ�, ������] ���� �̷���� �ݺ���
// �ʱ�� : �ݺ��� �����ϱ� ���� ���� ���� �ѹ��� ����Ǵ� ��
// ���ǽ� : �ݺ��� ��� ������ �������� �����ϴ� ��
// ������ : �ݺ��� ���� �� ���� ����Ǵ� ��

int main()
{
	//   �ʱ��    ���ǽ�  ������
	for (int i = 0; i < 5; ++i) {
		printf("%d �� �ݺ��߽��ϴ�. \n", i+1);
	}

	int count = 0;
	while (count < 5) {
		printf("%d �� �ݺ��߽��ϴ�. \n", count + 1);
		++count;
	}

	// while, for ��
	//        while				for
	// �ʱ�� int count = 0		int i = 0
	// ���ǽ� count < 5			i < 5
	// ������ ++count			++i

	int num;
	printf("����� ����ұ�� ? ");
	scanf("%d", &num);

	for (int i = 1; i <= 9; i++) {
		printf("%d X %d = %d\n", num, i, num * i);
	}
	return 0;
}