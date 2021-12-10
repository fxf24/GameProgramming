#include <iostream>
#include <map>
using namespace std;

#define NEWLINE cout << endl

// 연관 컨테이너 : 일정한 규칙에 따라 자료를 조직화하여 관리 하는 컨테이너
// - key 와 value 를 통해 관계있는 값을 묶어서 관리합니다.
// - 요소 탐색이 빠릅니다.
// - 삽입 / 제거가 느립니다.
 
// Map : key 와 value 가 쌍으로 저장되는 컨테이너
// - 요소의 형식으로는 key, value 를 갖는 pair 형식을 사용합니다.
// - key 의 중복을 허용하지 않습니다.
// - <map> 라이브러리가 필요합니다. 

void PrintMap(map<string, string>& mapInstance)
{
	for (auto iter = mapInstance.begin(); iter != mapInstance.end(); iter++)
	{
		cout << iter->first << " : " << iter->second << endl;
	}
	NEWLINE;
}

int main()
{
	// - map의 요소의 KeyType   (좌측)
	// - map의 요소의 ValueType (우측)
	map<string, string> fruits;
	
	// pair 객체 생성
	pair<string, string> apple;

	// first : key 값을 저장하는 공간입니다.
	apple.first = "사과";
	// second : value 값을 저장하는 공간입니다.
	apple.second = "Apple";

	// insert(pair) : pair 를 요소로 추가합니다.
	fruits.insert(apple);
	fruits.insert(pair<string, string>("바나나", "Banana"));
	// make_pair(key, value) : key 와 value 를 가진 pair 객체를 생성합니다.
	fruits.insert(make_pair("포도", "Grape"));

	PrintMap(fruits);
	
	// erase(key) : key 값을 가지고 있는 요소를 제거합니다.
	fruits.erase("바나나");
	PrintMap(fruits);

	// find(key) : key 값을 가지고 있는 요소를 탐색합니다.
	//			   요소가 존재한다면 해당 요소가 저장되어 있는 위치를 반환하고
	//			   존재하지 않는다면 end() 를 반환합니다.
	auto iter = fruits.find("포도");

	if (iter == fruits.end())
	{
		cout << "요소가 존재하지 않습니다 !" << endl;
	}
	else
	{
		cout << "요소를 찾았습니다 !" << endl;
		cout << iter->first << " : " << iter->second << endl;
	}
	NEWLINE;

	fruits["오렌지"] = "Orange";
	fruits["포도"] = "WhiteGrape";
	// mapInstance[Key] = value;
	// 만약 Key 값을 가지고 있는 요소가 존재하지 않는다면
	// Key라는 키를 가진 요소를 추가하고 값을 value 로 초기화합니다.
	// 존재한다면 해당 Key 값을 가진 요소의 값을 value로 초기화합니다.

	PrintMap(fruits);


	return 0;
}