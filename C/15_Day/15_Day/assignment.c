#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int arr[20];
	srand(GetTickCount64());

	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 10 + 1;
	}

	for (int i = 0; i < 20; i++) {
		printf("%d  ", arr[i]);
	}
	printf("\n");
	printf("버블정렬을 시작합니다.\n");
	system("pause");

	for (int i = 0; i < 20; i++) {
		for (int j = 1; j < 20-i; j++) {
			if (arr[j - 1] > arr[j]) {
				swap(&arr[j - 1], &arr[j]);
				system("cls");
				for (int i = 0; i < 20; i++) {
					printf("%d  ", arr[i]);
				}
				printf("\n");
				Sleep(100);
			}
		}
	}
	return 0;
}