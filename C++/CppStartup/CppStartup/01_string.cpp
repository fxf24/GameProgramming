#include <iostream>
using namespace std;
// C++ 에서는 string 을 이용하여 문자열을 간편하게 다룰 수 있습니다.
// 

int main() {
	string myString = "Hello!";

	cout << "myString : " << myString << endl;

	myString = "World";
	cout << "myString : " << myString << endl;

	string myString2 = "Hello ";
	myString2 += myString;
	cout << "myString2 : " << myString2 << endl;

	// length() : 문자열의 길이를 반환합니다.
	printf("myString Length : %d \n", myString2.length());
	return 0;
}