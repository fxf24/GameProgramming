#include <iostream>
#include <Windows.h>
using namespace std;

class ShallowCopy
{
private :
	int* Pointer;

public :
	ShallowCopy() {	Pointer = new int(); }
	~ShallowCopy() { delete Pointer; }
	
public :
	__forceinline int GetPointer() const
	{ return *Pointer; }

	void SetPointer(int integer)
	{ *Pointer = integer; }

};

class DeepCopy
{
private :
	int* Pointer;
		
public :
	DeepCopy() { Pointer = new int(); }
	DeepCopy(const DeepCopy& copy)
	{
		Pointer = new int();
		*Pointer = *copy.Pointer;
	}
	~DeepCopy() { delete Pointer; }

public :
	__forceinline int GetPointer() const
	{
		return *Pointer;
	}

	void SetPointer(int integer)
	{
		*Pointer = integer;
	}
};

int main()
{
	// 얕은 복사
	/*ShallowCopy copy1 = ShallowCopy();
	copy1.SetPointer(10);
	cout << "copy1 :: " << copy1.GetPointer() << endl;
	ShallowCopy copy2 = copy1;
	cout << "copy2 :: " << copy2.GetPointer() << endl;
	copy2.SetPointer(20);
	cout << "copy2 :: " << copy2.GetPointer() << endl;
	cout << "copy1 :: " << copy1.GetPointer() << endl;*/
	// 기본 복사 생성자는 얕은 복사입니다.
	system("pause");

	// 깊은 복사
	DeepCopy copy1 = DeepCopy();
	copy1.SetPointer(10);
	cout << "copy1 :: " << copy1.GetPointer() << endl;
	DeepCopy copy2 = copy1;
	cout << "copy2 :: " << copy2.GetPointer() << endl;
	copy2.SetPointer(20);
	cout << "copy2 :: " << copy2.GetPointer() << endl;
	cout << "copy1 :: " << copy1.GetPointer() << endl;


	return 0;
}