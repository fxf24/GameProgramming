#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#pragma warning (disable : 4996)

struct Card
{
	int number;
	wchar_t shape;
};

int main()
{
	srand(GetTickCount64());
	setlocale(LC_ALL, "KOREAN");

	struct Card Trump[52];

	wchar_t shapelist[4] = {L'¢½', L'¢¿', L'¢»', L'¡Þ' };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			int index = j + (i * 13);
			Trump[index].number = j + 1;
			Trump[index].shape = shapelist[i];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			int index = j + (i * 13);
			wprintf(L"%c", Trump[index].shape);
			printf("%d", Trump[index].number);
		}
		printf("\n");
	}

	return 0;
}