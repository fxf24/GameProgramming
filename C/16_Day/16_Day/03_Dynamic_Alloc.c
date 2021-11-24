#include <stdio.h>
#include <stdlib.h>

int main() {
	// int* arr = (int*)malloc(20);
	int* arr = (int*)calloc(5, 4);
	// void * calloc(count, size);
	// (count * size) byte 크기의 동적 메모리를 할당합니다.
	// 할당한 메모리의 시작 주소값을 반환합니다.
	// 동적 메모리 공간을 초기화하지 않는다면 모두 0으로 초기화합니다.

	for (int i = 0; i < 5; i++) {
		
		printf("초기화 전 :arr[%i] = %i \n", i, arr[i]);
		*(arr + i) = 10 * (i + 1);
		printf("초기화 후 :arr[%i] = %i \n", i, arr[i]);
	}


	free(arr);
	arr = NULL;
	return 0;
}