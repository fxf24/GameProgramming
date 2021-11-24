#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

typedef unsigned int UINT;

void InitializeArray(int arr[], UINT length) {
	srand(GetTickCount64());

	// �迭�� ��Ҹ� 1 ~ 10 ���̷� �ʱ�ȭ�մϴ�.
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 10 + 1;
	}
}

void PrintArray(int arr[], UINT length) {
	system("cls");

	// �迭�� ��Ҹ� ����մϴ�.
	for (int i = 0; i < length; i++) {
		printf("%i  ", arr[i]);
	}
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], UINT length) {
	// �迭�� ���� ��ŭ �ݺ��մϴ�.
	for (int i = 0; i < length; i++) {
		// ���� ��ҵ��� �������� �ݺ��մϴ�.
		for (int j = 1; j < length - i; j++) {
			// ���� �˻� ��ҿ� ���� ����� ũ�⸦ ���Ͽ�
			// ũ�ٸ� ��ü �մϴ�.
			if (arr[j - 1] > arr[j]) {
				swap(&arr[j - 1], &arr[j]);
				PrintArray(arr, length);
				printf("\n");
				Sleep(100);
			}
		}
	}
}
int main()
{
	int arr[20];
	InitializeArray(arr, 20);
	PrintArray(arr, 20);
	printf("\n");
	printf("���������� �����մϴ�.\n");
	system("pause");

	bubble_sort(arr, 20);
	return 0;
}