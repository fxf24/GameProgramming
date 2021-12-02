#include <iostream>
using namespace std;

struct Cat {
	string name;
	int age;

	void PrintCat() {
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
	}
};

int main() {
	// Cat 구조체 형식으로 객체를 선언합니다.
	Cat cat;

	// 인스턴스화 합니다.
	cat.name = "myCat";
	cat.age = 10;
	cat.PrintCat();

	Cat* pCat = new Cat;
	pCat->age = 5;
	// (*pCat).age = 5;
	// .  : 멤버 직접 접근 연산자
	// -> : 멤버 간접 접근 연산자
	pCat->name = "yourCat";
	pCat->PrintCat();

	delete pCat;
	pCat = nullptr;

	/*Cat* catarr[3];
	catarr[0] = new Cat;
	catarr[1] = new Cat;
	catarr[2] = new Cat;
	catarr[0]->age = 10;
	Cat* arrcat = new Cat[3];
	arrcat[0].age = 20;*/

	return 0;
}