#include <stdio.h>
#include <stdlib.h>

int main() {
	// malloc 을 사용하여 int 자료형 5개를 저장할 수 있는 배열을 만들고
	// 각 요소의 값을 10, 20, 30, 40, 50 으로 초기화 해주세요.

	int* arr = (int*)malloc(20);

	for (int i = 0; i < 5; i++) {
		*(arr + i) = 10 * (i + 1);
	}

	for (int i = 0; i < 5; i++) {
		printf("%i \n", arr[i]);
	}

	free(arr);
	arr = NULL;

	return 0;
}