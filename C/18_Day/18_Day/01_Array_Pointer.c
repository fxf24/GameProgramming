#include <stdio.h>

// 배열 포인터
// 배열의 주소를 담을 수 있는 포인터를 의미합니다.

int main() {
	// 2 차원 배열 선언 동시에 초기화
	int arr[2][3] = {
		{ 10, 20, 30 },
		{ 40, 50, 60 }
	};
	
	// 길이가 3인 1차원 배열의 주소값을 저장합니다.
	int(*pArr)[3] = arr;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%p ", &pArr[i][j]);
			printf("%d ", pArr[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}