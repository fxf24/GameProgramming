#include <stdio.h>

int main()
{
	int arr[5];
	// 배열의 이름은 주소값을 나타냅니다.
	printf("arr 의 주소 : %p\n", arr);
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < 5; i++) {
		printf("arr[%d] 의 주소 : %p\n", i, &arr[i]);
		// 배열의 각 공간의 크기가 4byte 이므로
		// 배열의 주소 또한 4씩 늘어난다.
		// 주소 연산
		// 주소 + i = 주소 + (i * size)
		printf("arr[%d] 의 값 : %d\n", i, *(arr + i));
		// 배열의 각 공간의 주소에 간접참조 하므로
		// 공간안의 값을 반환한다.
	}

	int* p = arr;

	for (int i = 0; i < 5; i++) {
		printf("parr[%d] 의 주소 : %p\n", i, &arr[i]);
		printf("parr[%d] 의 값 : %d\n", i, *(arr + i));
	}

	// [] : 인덱스 연산자
	// 각 인덱스 ㅑ공간의 주소에 들어잇는 값을 반환하는 연산자입니다.
	// [i] = *(arr+i);
	return 0;
}