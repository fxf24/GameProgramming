// int �� ���� a �� b�� �����ϰ� ������ ���� �Է¹޾� 
// a > b ���� ũ�ٸ� a �� b ���� Ů�ϴ�.
// �۴ٸ� a �� b ���� �۽��ϴ�. �� ����ϴ� ���α׷��� ������ּ���!
#include <stdio.h>
#pragma warning(disable : 4996)

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b) {
		printf("a �� b ���� Ů�ϴ�.\n");
	}
	else if (a == b) { // ���� ���ǽ��� �����̶�� �����մϴ�.
		printf("a �� b �� �����ϴ�.\n");
	}
	else { // ��� ���ǽ��� �����̶�� �����մϴ�.
		printf("a �� b ���� �۽��ϴ�.\n");
	}

	return 0;
}