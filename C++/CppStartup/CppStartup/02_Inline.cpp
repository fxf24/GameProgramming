#include <iostream>

// 인라인 함수
// - 짧은 코드로 구성된 함수에 대해 "함수 호출 오버헤드" 로 인한
//   프로그램의 실행 속도 저하를 줄이기 위해 도입된 기능입니다.

// 인라인 한수 선언 방법
// 반환형 앞에 inline, __forceinline 키워드를 붙여주시면 됩니다.

inline int Add(int a, int b) {
	return a + b;
}

__forceinline int Sub(int a, int b) {
	return a - b;
}

int main() {
	printf("10 + 5 = %i \n", Add(10, 5));
	printf("10 - 5 = %i \n", Sub(10, 5));


	return 0;
}