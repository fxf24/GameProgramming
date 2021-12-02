#include <iostream>
using namespace std;

// 참조자
// - 자신이 참조하는 객체를 대신할 수 있는 또 하나의 이름을 의미합니다.
// - 참조자는 포인터와 동일하게 다른 객체를 참조할 수 있지만
//   포인터와 다르게 nullptr 값을 가질 수 없으며, 선언시에 참조자가
//   참조할 객체를 지정해줘야 합니다.

int main() {
	int Num1 = 10;
	int Num2 = 20;

	// Num1 에 대한 참조자 ref1을 선언합니다.
	int& ref1 = Num1;
	// - 참조자를 선언할 때 데이터 형식 뒤에 '&' 를 작성합니다.
	// - 포인터와는 다르게 주소가 아닌 변수명(식별자)를 대입합니다.

	// 참조자는 객체에 대한 또 하나의 이름이기 때문에 값과 주소를 모두 참조합니다.
	printf("Num1 value   : %i \n", Num1);
	printf("ref1 value   : %i \n", ref1);
	printf("Num1 address : %p \n", &Num1);
	printf("ref1 address : %p \n", &ref1);
	cout << endl;

	// 참조자 선언 이후 다른 객체를 대입한다면, 해당 객체를 참조하는 것이 아닌,
	// 오른쪽 피 연산자의 값을 복사합니다.
	// 즉 중간에 다른 객체를 참조할 수 없습니다.
	ref1 = Num2; 
	printf("Num1 value   : %i \n", Num1);
	printf("ref1 value   : %i \n", ref1);
	cout << endl;

	// 참조자를 대상으로 하는 참조자를 선언할 수 있습니다.
	// 참조하고 있는 객체의 또 하나의 참조자를 선언하는 것과 같습니다.
	int& ref2 = ref1;
	printf("Num1 value   : %i \n", Num1);
	printf("ref1 value   : %i \n", ref1);
	printf("ref2 value   : %i \n", ref2);
	cout << endl;

	// 포인터 변수 또한 객체이므로 포인터 변수에 대한 참조자도 선언이 가능합니다.
	int* p = &Num2;
	int*& ref3 = p;

	*ref3 = 300; // == (*p = 300);

	printf("Num2  value   : %i \n", Num2);
	printf("*ref3 value   : %i \n", *ref3);
	printf("*p    value   : %i \n", *p);
	printf("Num2  address : %p \n", &Num2);
	printf("p     value   : %p \n", p);
	printf("ref3  value   : %p \n", ref3);
	printf("p     address : %p \n", &p);
	printf("ref3  address : %p \n", &ref3);
	cout << endl;

	// p를 통하여 Num2의 참조자를 선언해주세요.
	// 포인터 변수를 통하여 가리키는 객체 참조
	int& ref4 = *p;
	printf("ref4  value   : %i \n", ref4);
	printf("ref4  address : %p \n", &ref4);

	// const 가 붙은 참조자는 참조하는 변수의 값을 변경하실 수 없습니다.
	const int& ref5 = Num1;
	// ref5 = 30;

	// 상수 객체를 참조하기 위해서는 같은 상수 형식의 참조자로 선언하여야 합니다.
	const int Num3 = 10;
	const int& ref6 = Num3;

	return 0;
}