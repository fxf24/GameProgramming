#include <stdio.h>

int main()
{
	// 1���� 11���� ������ ���� ������ ���� ����
	int count = 1;

	// count �� ���� 10 ���϶�� �ݺ��ϴ� �ݺ����Դϴ�.
	while (count <= 5) {
		printf("�ش� �ݺ����� %d��° �ݺ� �������Դϴ�. \n", count);
		printf("count == %d \n\n", count);
		++count;
	}


	return 0;
}