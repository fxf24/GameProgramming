#include <iostream>

// C++ 에서는 bool 형식을 지원합니다.
// - 참(true) 와 거짓(false) 를 값으로 가질 수 있는 형식을 의미합니다.
// - 1byte 를 차지합니다.

// C++ 에서는 true, false 키워드로 참과 거짓을 설정합니다.

int main() {
	bool myBoolean1 = true;
	printf("myBoolean1 : %s \n", (myBoolean1 ? "True" : "False"));

	bool myBoolean2 = false;
	printf("myBoolean2 : %s \n", (myBoolean2 ? "True" : "False"));

	printf("true = %d \n", true);
	printf("false = %d \n", false);


	return 0;
}