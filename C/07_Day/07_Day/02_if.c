// int 형 변수 a 와 b를 선언하고 각각의 값을 입력받아 
// a > b 보다 크다면 a 는 b 보다 큽니다.
// 작다면 a 는 b 보다 작습니다. 를 출력하는 프로그램을 만들어주세요!
#include <stdio.h>
#pragma warning(disable : 4996)

int main() {

	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b) {
		printf("a 는 b 보다 큽니다.\n");
	}

	if (a < b) {
		printf("a 는 b 보다 작습니다.\n");
	}
	return 0;
}