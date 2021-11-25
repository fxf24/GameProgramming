#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef unsigned int UINT;

void printArr(int* arr, UINT length) {
	for (int i = 0; i < length; i++) {
		printf("arr[%i] : %i\n", i, arr[i]);
	}
}
int main()
{
	UINT elemcount = 10;
	SetConsoleOutputCP(CP_UTF8);
	int* arr = (int*)calloc(elemcount, 4);

	for (int i = 0; i < elemcount; i++) {
		arr[i] = i + 1;
	}
	printArr(arr, elemcount);
	
	elemcount = 15;

	// 동적 메모리를 재할당 합니다.
	arr = (int*)realloc(arr, elemcount * 4);
	// void * realloc(p, size)
	// p 가 가리키는 동적 메모리의 크기를 size byte의 크기로 재할당 합니다.
	// 재할당을 통해 byte의 크기가 커질 때 
	// - 재할당 전 입력된 값은 유지되며 새로 추가된 메모리에는 쓰레기 값이 저장됩니다.
	// 작아질 때
	// - 재할당 전 입력된 값은 유지되며 작아진 만큼의 크기의 요소가 삭제 됩니다.
	// - realloc 을 사용하게 되면 재할당 과정에서 메모리의 위치가 바뀔 수 있으므로,
	// 	 항상 주소값을 다시 포인터 변수로 받는 것이 좋습니다.
	//

	printf("\n 재할당 후 \n");
	printArr(arr, elemcount);
	
	// 동적 메모리 해제
	free(arr);
	arr = NULL;

	return 0;
}