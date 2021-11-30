#include <iostream>

// namespace
// - 특정한 영역에 이름을 붙여주기 위한 문법적 요소이며
//   어떠한 이름이 소속된 공간을 의미합니다.
//   ::(스코프 연산자) 를 통하여 해당 공간의 요소에 접근할 수 있습니다.

// :: (스코프 연산자)
// - 범위지정 연산자라고 하며 어떤 특정 범위에 속해있는 요소에 접근할 때 
//   사용하는 연산자입니다.

namespace Mynamespace {
	int num;

	int Add(int a, int b) {
		return a + b;
	}
}

namespace Usingspace {
	int num;
	int Sub(int a, int b) {
		return a - b;
	}
}

// 특정 namespace 의 사용을 명시적으로 선언할 때 using을 사용합니다.
using namespace Usingspace;
// using 구문을 사용한다면 해당 namespace의 요소를 사용할 때
// namespace 명을 명시하지 않아도 됩니다.

int main() {
	int num;
	Mynamespace::num = 10;
	printf("%d\n", Mynamespace::num);
	Mynamespace::num += 10;
	printf("%d\n", Mynamespace::num);
	Mynamespace::Add(10, 20);
	num = 20;
	Sub(100, 50);
	
	return 0;
}