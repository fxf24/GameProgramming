#include <stdio.h>

int main()
{
	int arr[5];
	// �迭�� �̸��� �ּҰ��� ��Ÿ���ϴ�.
	printf("arr �� �ּ� : %p\n", arr);
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < 5; i++) {
		printf("arr[%d] �� �ּ� : %p\n", i, &arr[i]);
		// �迭�� �� ������ ũ�Ⱑ 4byte �̹Ƿ�
		// �迭�� �ּ� ���� 4�� �þ��.
		// �ּ� ����
		// �ּ� + i = �ּ� + (i * size)
		printf("arr[%d] �� �� : %d\n", i, *(arr + i));
		// �迭�� �� ������ �ּҿ� �������� �ϹǷ�
		// �������� ���� ��ȯ�Ѵ�.
	}

	int* p = arr;

	for (int i = 0; i < 5; i++) {
		printf("parr[%d] �� �ּ� : %p\n", i, &arr[i]);
		printf("parr[%d] �� �� : %d\n", i, *(arr + i));
	}

	// [] : �ε��� ������
	// �� �ε��� �������� �ּҿ� ����մ� ���� ��ȯ�ϴ� �������Դϴ�.
	// [i] = *(arr+i);
	return 0;
}