#include "MyClass.h"
#include <iostream>
using namespace std;

MyClass::MyClass(int Mem) : Memvar(Mem)
{
	Memvar = Mem;
}

void MyClass::PrintMember() const
{
	cout << "Memvar : " << Memvar << endl;
}
