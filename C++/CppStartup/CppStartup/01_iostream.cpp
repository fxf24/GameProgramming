#include <iostream>
// C++ 에서부터 제공하는 입출력 라이브러리 파일입니다.
#include <Windows.h>

int main() {
	SetConsoleOutputCP(CP_UTF8);
	// C++ 에서의 출력은 cout을 사용합니다.
	
	std::cout << "Helloworld" << std::endl;
	// endl : '\n' (개행문자)의 역할을 합니다.

	int num = 0;
	std::cout << " 입력 : ";
	// C++에서의 입력은 cin을 사용합니다.
	std::cin >> num;
	std::cout << num;

	return 0;
}