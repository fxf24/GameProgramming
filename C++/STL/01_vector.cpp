#include <iostream>
#include <Windows.h>
using namespace std;

#define NEWLINE cout << endl

// STL
// - 프로그램에 필요한 자료구조와 알고리즘을 Template 형태로 제공하는 라이브러리입니다.

// STL 의 구성
// Container, Container Adapter, Iterator, Algorithm, Functor, Allocator

// Container : 자료구조를 나타내며, 객체들을 저장하는 객체를 의미합니다.
// - 시퀀스 컨테이너 : 자료를 선형구조로 관리하는 컨테이너입니다.
// - 선형적인 데이터 집합이므로, 데이터를 넣는 순서대로 요소가 할당됩니다.
// - 특별한 제약이나, 관리 규칙 없이 데이터가 관리됩니다.
// - 종류 : vector, list, deque

// vector : 배열 기반 컨테이너 입니다.
// - <vector> 라이브러리를 포함시켜야 합니다.
// - 요소를 삽입 / 제거할 때 자동으로 자신의 크기를 조정합니다.
// - 요소의 탐색속도와 삽입 / 제거 속도가 느립니다.
// - 삽입 / 제거시 반복자 무효화 현상이 일어날 수 있습니다.
// 반복자 무효화 현상 : iterator 가 해당 요소의 위치를 찾지 못하는 현상을 의미합니다.

#include <vector>

int main()
{
	//SetConsoleOutputCP(CP_UTF8);
	vector<int> vec;
	
	// Algorithm : 데이터를 다루기 위한 함수를 의미합니다.
	// push_back(value) : vector 의 맨 뒤에 요소를 추가합니다.
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	// Iterator : 컨테이너에 있는 요소를 순회하거나, 접근할 수 있게 해주는 객체입니다.
	// - 컴테이너와 알고리즘이 하나로 동작하게 만들어주는 인터페이스 역할을 합니다.
	// - 다음 요소로 이동할 경우 +, -, ++, -- 연산자를 사용합니다.
	// - 컨테이너의 내부 객체에 접근할 때 * 연산자를 사용합니다.

	// vec에 접근하기 위해 iterator를 선언합니다.
	vector<int>::iterator iter = vec.begin();
	// begin() : 컨테이너의 첫 번째 요소의 위치를 반환합니다.

	cout << "iter 의 첫 번째 요소 : " << *iter << endl;
	// Functor : 연산자를 오버로딩한 클래스의 객체를 의미합니다.
	cout << "iter 의 두 번째 요소 : " << vec[1] << endl;

	NEWLINE;

	// end() : 컨테이너의 마지막 요소의 위치를 반환합니다.
	for (; iter != vec.end(); iter++)
	{
		cout << *iter << " ";
	}
	NEWLINE;

	// front() : 컨테이너의 첫 번째 요소를 반환합니다.
	cout << "vec.front() : " << vec.front() << endl;

	// pop_bakc() : 마지막으로 추가한 요소를 제거합니다.
	vec.pop_back();

	// back() : 컨테이너의 마지막 요소를 반환합니다.
	cout << "vec.back() : " << vec.back() << endl;

	// size() : 컨테이너의 요소 개수를 반환합니다.
	cout << "vec.size() : " << vec.size() << endl;

	NEWLINE;
	// insert(where, value) : where 의 위치에 value 값을 가진 요소를 추가시킵니다.
	vec.insert(vec.end(), 20);

	// erase(where) : wehre 위치에 저장되어있는 요소를 제거합니다.
	vec.erase(vec.begin());

	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		cout << *iter << " ";
	}

	NEWLINE;

	// claer() : 컨테이너의 요소를 모두 제거합니다.
	vec.clear();
	NEWLINE;

	// empty() : 컨테이너에 요소가 존재한다면 false 존재하지 않는다면 true 를 반환합니다.
	cout << "vec is empty ? " << (vec.empty() ? "TRUE" : "FALSE") << endl;

	// Container Adapter : 구성 요소의 인터페이스를 변경하여 새로운 인터페이스를
	// 					   갖는 구성 요소로 하는 것을 의미합니다.
	// - 시퀀스 컨테이너를 변형하여 특정한 방식에 따라 관리하는 컨테이너 입니다.
	// - queue : FIFO 방식으로 요소를 관리합니다.
	// - priority queue : 연산자를 설정함에 따라 요소 처리의 우선순위 결정됩니다.
	// - stack : LIFO 방식으로 요소를 관리합니다.

	// FIFO(First In First Out) : 처음 추가된 요소가 처음으로 나오는 방식
	// LIFO(Last In First Out)  : 마지막으로 추가된 요소가 처음으로 나오는 방식

	return 0;
}