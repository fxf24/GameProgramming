// 1. FIFO, LIFO 가 존재하는 이유와 활용하는 예시에 대해서 조사하고 작성해주세요.

// 2. 상점 프로그램을 만들어주세요.
#include <iostream>
#include <map>
#include <Windows.h>
using namespace std;

#define NEWLINE cout << endl

void market() {
	map<string, int> item;
	int hand = 10000;

	while (true) {
		system("cls");
		int choice = 0;
		cout << "선택해주세요" << endl;
		cout << "1_판매할 물건을 추가합니다." << endl;
		cout << "2_판매할 물건을 모두 추가했다." << endl;
		cout << "입력 : ";
		cin >> choice;
		if (choice == 1)
		{
			system("cls");
			string name;
			int price;
			cout << "어떤 물건을 파시겠습니까?" << endl;
			cout << "입력 : ";
			cin >> name;
			cout << name << "의 가격을 지정해주세요." << endl;
			cin >> price;
			item[name] = price;
		}
		else if (choice == 2)
		{
			while (true) {
				system("cls");
				int min = 1000000;
				for (auto iter = item.begin(); iter != item.end(); iter++)
				{
					cout << iter->first << " : " << iter->second << endl;
					if (iter->second <= min)
					{
						min = iter->second;
					}
				}

				if (item.empty() || min > hand) {
					system("cls");
					cout << "프로그램이 종료됩니다..." << endl;
					break;
				}

				NEWLINE;

				string i;
				cout << "소지금 : " << hand << endl;
				cout << "어떤 것을 구매 하시겠습니까? (구매 종료 : 종료)" << endl;
				cout << "입력 : ";
				cin >> i;

				auto iter = item.find(i);


				if (iter != item.end())
				{
					if (item[i] <= hand) {
						cout << i << "을/를 구매했습니다!" << endl;
						hand -= item[i];
						item.erase(i);
					}
					else {
						cout << i << "을/를 구매할 수 없습니다!" << endl;
					}
					Sleep(500);
				}
				else if (i == "종료") {
					system("cls");
					cout << "프로그램이 종료됩니다..." << endl;
					break;
				}
				else
				{
					cout << i << "는 판매하지 않습니다." << endl;
					Sleep(500);
				}


			}
		}
		if (choice == 2) {
			break;
		}
	}

}

int main()
{
	market();

	return 0;
}
