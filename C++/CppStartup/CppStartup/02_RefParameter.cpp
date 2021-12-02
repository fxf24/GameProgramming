#include <iostream>
using namespace std;

// 값에 의한 호출 전달 방식
void CallByValue(int value) {
	printf("Parameter Value   : %i \n",  value);
	printf("Parameter Address : %p \n", &value);
	cout << endl;
}

// 주소에 의한 호출 전달 방식
void CallByAddress(int* address) {
	printf("Parameter Value   : %p \n", address);
	printf("Parameter Address : %p \n", &address);
	cout << endl;
}

// 참조에 의한 호출 전달 방식
void CallByReference(int& reference) {
	printf("Parameter Value   : %i \n", reference);
	printf("Parameter Address : %p \n", &reference);
	cout << endl;
}

int main() {
	int Argument = 10;
	printf("Argument Value    : %i \n", Argument);
	printf("Argument Address  : %p \n", &Argument);
	cout << endl;

	// 값을 복사하여 전달합니다.
	CallByValue(Argument);
	// 주소를 복사하여 전달합니다.
	CallByAddress(&Argument);
	// 객체를 참조하여 전달합니다.
	CallByReference(Argument);
	return 0;
}