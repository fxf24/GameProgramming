#include <iostream>
using namespace std;

int main() {
	// int myArray[5];
	// C 배열 동적 할당
	int* arr = (int*)calloc(5, sizeof(int));

	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
		printf("arr[%i] = %i\n", i, arr[i]);
	}
	free(arr);
	arr = NULL;

	// C++
	int* newp = new int[5];
	for (int i = 0; i < 5; i++) {
		newp[i] = i + 1;
		printf("newp[%i] = %i\n", i, newp[i]);
	}
	// 해제시킬시 delete[]를 사용합니다.
	delete[] newp;
	newp = nullptr;
	return 0;
}