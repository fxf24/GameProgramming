#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

typedef unsigned int UINT;

void InitializeArray(int arr[], UINT length) {
	srand(GetTickCount64());

	// 배열의 요소를 1 ~ 10 사이로 초기화합니다.
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 10 + 1;
	}
}

void PrintArray(int arr[], UINT length) {
	system("cls");

	// 배열의 요소를 출력합니다.
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
	// 배열의 길이 만큼 반복합니다.
	for (int i = 0; i < length; i++) {
		// 남은 요소들을 기준으로 반복합니다.
		for (int j = 1; j < length - i; j++) {
			// 현재 검사 요소와 다음 요소의 크기를 비교하여
			// 크다면 교체 합니다.
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
	printf("버블정렬을 시작합니다.\n");
	system("pause");

	bubble_sort(arr, 20);
	return 0;
}