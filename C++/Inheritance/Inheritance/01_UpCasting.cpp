#include <iostream>
using namespace std;

class BaseClass
{
protected :
	int BaseMem;

public :
	BaseClass() { BaseMem = 10; }

public :
	void Print() const { cout << "BaseMem : " << BaseMem << endl; }
};

class DerivedClass : public BaseClass
{
protected :
	int DerivedMem;

public :
	DerivedClass() { DerivedMem = 20; }

public :
	void Print() const
	{
		cout << "BaseMem    : " << BaseMem    << endl;
		cout << "DerivedMem : " << DerivedMem << endl;
	}
};