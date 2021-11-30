#include <stdio.h>
#include <stdlib.h>

int main() {
	// 2차원 배열을 동적할당 시켜주세요.
	// malloc, calloc 자유자재로 이용하셔도 무관합니다.
	// 2차원 배열의 길이는 Height = 4, width = 5 로 설정해주세요.
	// 각 요소의 값은 원하시는 값으로 초기화 시켜주세요.
	//
	int* arr1 = (int*)calloc(20, sizeof(int));

	int(*arr)[1] = &arr1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = (i * 5) + j + 1;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr1);
	arr1 = NULL;
	return 0;
}