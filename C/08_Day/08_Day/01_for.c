#include <stdio.h>
#pragma warning(disable : 4996)
// for 문
// [초기식, 조건식, 증감식] 으로 이루어진 반복문
// 초기식 : 반복을 실행하기 전에 가장 먼저 한번만 실행되는 식
// 조건식 : 반복을 계속 수행할 것인지를 결정하는 식
// 증감식 : 반복이 끝날 때 마다 실행되는 식

int main()
{
	//   초기식    조건식  증감식
	for (int i = 0; i < 5; ++i) {
		printf("%d 번 반복했습니다. \n", i+1);
	}

	int count = 0;
	while (count < 5) {
		printf("%d 번 반복했습니다. \n", count + 1);
		++count;
	}

	// while, for 비교
	//        while				for
	// 초기식 int count = 0		int i = 0
	// 조건식 count < 5			i < 5
	// 증감식 ++count			++i

	int num;
	printf("몇단을 출력할까요 ? ");
	scanf("%d", &num);

	for (int i = 1; i <= 9; i++) {
		printf("%d X %d = %d\n", num, i, num * i);
	}
	return 0;
}