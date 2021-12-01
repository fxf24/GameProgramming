#include <iostream>
using namespace std;

int main() {
	int** arr = new int* [4];
	
	int count = 15; 
	for (int i = 0; i < 4; i++) {
		arr[i] = new int[5];
		for (int j = 0; j < 5; j++) {
			count++;
			arr[i][j] = count;
			printf("%s%d ", arr[i][j] < 10 ? " " : "",arr[i][j]);
		}
		count -= 10;
		printf("\n");
	}

	for (int i = 0; i < 4; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
	return 0;
}