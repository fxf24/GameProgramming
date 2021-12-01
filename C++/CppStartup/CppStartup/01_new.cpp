#include <iostream>
using namespace std;

int main() {
	// C 동적할당
	int* mlcp = (int*)malloc(sizeof(int));
	*mlcp = 10;
	cout << "*mlcp = " << *mlcp << endl;
	free(mlcp);
	mlcp = NULL;

	// C++ 에서 new 연산자를 사용하여 동적할당을 하실 수 있습니다.
	int* newp = new int;
	*newp = 10;
	cout << "*newp = " << *newp << endl;
	// free(newp);
	// newp = NULL;
	// delete 연산자를 이용하여 동적할당 공간을 해제하실 수 있습니다.
	delete newp;
	// nullptr 를 이용하여 포인터가 주소값을 가르키지 않도록 할 수 있습니다.
	newp = nullptr;

	return 0;
}