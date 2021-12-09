#include "ArrayClass.h"

int main()
{
	ArrayClass<int> MyArray = ArrayClass<int>();
	for (int i = 0; i < 3; i++) {
		MyArray.Add(i+1);
	}
	cout << MyArray.GetLength() << endl;

	for (int i = 0; i < MyArray.GetLength(); i++) {
		cout << MyArray.Get(i) << endl;
	}

	return 0;
}