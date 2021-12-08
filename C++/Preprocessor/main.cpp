#include "Preprocessor.h"
#include "MyClass.h"
// MyClass\MyClass.h : MyClass 폴더에 있는 MyClass.h를 포함시킵니다.

int main()
{
	printf("1 + 2 : %d \n", plus(1, 2));
	MyClass myClass = MyClass(10);
	myClass.PrintMember();

	return 0;
}