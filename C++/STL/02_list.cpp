#include <iostream>
#include <list>
using namespace std;

#define NEWLINE cout << endl

// List : 이중 연결 리스트
// - 요소 삽입 / 제거가 빠릅니다.
// - <list> 라이브러리가 필요합니다.

template <typename T>
void PrintList(const list<T>& listInstance)
{
	for (auto iter = listInstance.begin(); iter != listInstance.end(); iter++)
	{
		cout << (*iter) << " ";
	}
	
	NEWLINE;
}
int main()
{
	list<int> myList;

	// assign(count, value) : count 만큼의 개수의 요소를 추가하고 value 로 초기화합니다.
	myList.assign(2, 10);
	PrintList(myList);

	NEWLINE;

	// push_front(value) : 맨 앞에 요소를 추가하고 value 로 초기화 합니다.
	myList.push_front(9);
	PrintList(myList);

	NEWLINE;

	// pop_front(value) : 맨 앞의 요소를 제거합니다.
	myList.pop_front();
	PrintList(myList);

	NEWLINE;

	for (int i = 11; i < 14; i++) 
	{
		myList.push_back(i);
	}

	// reverse() : 요소를 역순으로 정렬합니다.
	myList.reverse();
	PrintList(myList);

	NEWLINE;

	// sort() : 요소를 작은 값부터 큰 값의 순서로 정렬합니다.
	myList.sort();
	PrintList(myList);

	NEWLINE;

	// remove(value) : 요소들 중 value 값을 가지고 있는 요소를 제거합니다.
	myList.remove(10);
	PrintList(myList);

	NEWLINE;

	return 0;
}