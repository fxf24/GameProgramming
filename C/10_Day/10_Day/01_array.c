#include <stdio.h>

// 배열
// - 동일한 타입의 변수를 모아놓은 집합을 의미합니다.
//

int main()
{
	// 배열의 선언 방법
	// "묶어놓을 자료형" "배열의 이름" [배열의 길이]
	int myArray[5];

	// - 각각의 공간들을 구분하기 위한 번호를 index 라고 합니다.
	// - 각각의 공간에 접근하기 위해서는 "배열이름[index]"로 접근이 가능합니다.
	// - 배열의 인덱스번호는 1이 아닌 0부터 시작합니다.
	myArray[0] = 0;
	myArray[1] = 1;
	myArray[2] = 2;
	myArray[3] = 3;
	myArray[4] = 4;

	for (int i = 0; i < 5; i++) {
		printf("myArray[%d] = %d\n", i, myArray[i]);
	}
	return 0;
}