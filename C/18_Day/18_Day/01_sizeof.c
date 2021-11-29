#include <stdio.h>

int main() {
	// sizeof 연산자
	// 특정 공간이나 자료형에 대해서 몇 바잍트인지를 반환해주는 연산자입니다.

	int num = 10;

	printf("num size = %d byte \n", sizeof(num));
	printf("int size = %d byte \n", sizeof(int));
	printf("float size = %d byte \n", sizeof(float));
	printf("double size = %d byte \n", sizeof(double));
	printf("int* size = %d byte \n", sizeof(int*));
	printf("double* size = %d byte \n", sizeof(double*));
	printf("float* size = %d byte \n", sizeof(float*));



	return 0;
}