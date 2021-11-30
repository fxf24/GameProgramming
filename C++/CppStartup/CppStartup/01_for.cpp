#include <iostream>
using namespace std;

int main() {
	int myArray[5] = { 1,2,3,4,5 };

	// 배열 기반 for 문
	// 배열이 가지고 있는 요소의 개수만큼 배열을 반복하고
	// 요소를 저장하는 변수를 사용합니다.
	for (auto elem : myArray) {
		printf("%i ", elem);
	}


	return 0;
}