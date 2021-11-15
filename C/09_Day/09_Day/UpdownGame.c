#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

int main()
{
	srand(GetTickCount64());

	printf("UpDownGame!\n");
	printf("난수 생성범위 : 1 ~ 20\n");
	system("pause");
	system("cls");
	int answer = rand() % 20 + 1;
	int chance = 5;

	while (1) {
		printf("남은 기회 = %d\n", chance);
		int input;
		printf("정답을 입력하세요 : ");
		scanf("%d", &input);
		if (input >= 1 && input <= 20) {
			if (input < answer) {
				printf("UP!\n");
				chance--;
			}
			else if (input > answer) {
				printf("DOWN!\n");
				chance--;
			}
			else {
				system("cls");
				printf("정답입니다!\n");
				break;
			}	
		}
		if (chance == 0) {
			system("cls");
			printf("기회를 모두 소진하셨습니다!\n");
			printf("정답은 %d 였습니다!\n", answer);
			break;
		}
		Sleep(500);
		system("cls");
	}

	return 0;
}