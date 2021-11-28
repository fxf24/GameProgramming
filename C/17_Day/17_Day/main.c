#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning (disable:4819)

// 지역 변수, 전역 변수, 정적 지역 변수, 정적 전역 변수의 특징

int Global = 20;
// Global : 전역 변수
// 할당되는 메모리 : Data
// 라이프 사이클 : 프로그램 시작 시 생성되며 프로그램 종료시 소멸한다.

static int s_Global = 10;
// s_Global : 정적 전역 변수
// 할당되는 메모리 : Data
// 라이프 사이클 : 프로그램 시작 시 생성되며 프로그램 종료시 소멸한다.

// extern : 외부 파일의 전역 변수를 사용합니다.
extern int Test_G;
// extern static int Test_S;

// void PrintNum(int num)
// 할당되는 메모리 : Code
// num : 지역 변수
// 할당되는 메모리 : Stack
// 라이프 사이클 : PrintNum 함수 실행 시 생성되며 함수 종료시 소멸한다.
void PrintNum(int num) {
	int local = 10;
	// local : 지역 변수
	// 할당되는 메모리 : Stack
	// 라이프 사이클 : PrintNum 함수 실행 시 생성되며 함수 종료시 소멸한다.
	local += 10;

	// static : 정적의
	// 해당 공간을 정적으로 선언하여 프로그램이 끝날 때 까지 존재하도록 합니다.
	static int s_local = 10;
	// s_local : 정적 지역 변수
	// 할당되는 메모리 : Data
	// 라이프 사이클 : PrintNum 함수 실행 시 생성되며 프로그램 종료 시 소멸한다.
	s_local += 10;

	Global += 10;

	printf("num     = %i \n", num);
	printf("local   = %i \n", local);
	printf("s_local = %i \n", s_local);
	printf("Global  = %i \n", Global);

}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	int main_Num = 10;
	// main_Num : 지역 변수
	// 할당되는 메모리 : Stack
	// 라이프 사이클 : 프로그램 시작 시 생성되며 프로그램이 종료되면 소멸한다.
	static int s_main_Num = 20;
	// s_main_Num : 정적 지역 변수
	// 할당되는 메모리 : Data
	// 라이프 사이클 : 프로그램 시작 시 생성되며 프로그램이 종료되면 소멸한다.

	int* p = (int*)malloc(4);
	// (int*)malloc(4) : 동적 메모리
	// 할당되는 메모리 : Heap
	// 라이프 사이클 : 사용자가 선언할 때 생성되며 해제할 때 소멸한다.
	// p : 지역 변수
	// 할당되는 메모리 : Stack
	// 라이프 사이클 : 프로그램 시작 시 생성되며 프로그램이 종료되면 소멸한다.

	
	printf("PrintNum 첫번째 실행 \n");
	PrintNum(main_Num);

	printf("\nPrintNum 두번째 실행 \n");
	PrintNum(main_Num);

	printf("Test_G = %i \n", Test_G);

	free(p);
	p = NULL;
	
	return 0;
}