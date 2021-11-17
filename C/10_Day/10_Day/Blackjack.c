#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#pragma warning (disable : 4996)

struct Card
{
	wchar_t shape;
	int num;
};
int main()
{
	setlocale(LC_ALL, "KOREAN");

	wchar_t shapelist[4] = { L'♡', L'♧', L'♤', L'◇' };
	struct Card deck[52];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[i * 13 + j].shape = shapelist[i];
			deck[i * 13 + j].num = j+1;
		}
	}

	printf("블랙잭\n");
	system("pause");
	srand(GetTickCount64());
	struct Card dealer[10];
	int dealer_hand = 0;
	struct Card player[10];
	int player_hand = 0;
	int turn = 0;
	while (1) {
		struct Card pick;
		int pick_one = rand() % 52;
		pick = deck[pick_one];

		if (turn) {
			turn = 0;
			dealer[dealer_hand] = pick;
			dealer_hand++;
		}
		else {
			turn = 1;
			player[player_hand] = pick;
			player_hand++;
		}
		if (dealer_hand == 2 && player_hand == 2) {
			break;
		}
	}

	while (1){
		system("cls");
		printf("Dealer\n");
		for (int i = 0; i < dealer_hand; i++) {
			printf("■■  ");
		}
		printf("\n\n");
		printf("Player\n");
		for (int i = 0; i < player_hand; i++) {
			wprintf(L"%c", player[i].shape);
			printf("%d  ", player[i].num);
		}
		
		int psum = 0;
		int dsum = 0;
		for (int i = 0; i < player_hand; i++) {
			psum += player[i].num;
		}

		for (int i = 0; i < dealer_hand; i++) {
			dsum += dealer[i].num;
		}

		if (psum > 21) {
			printf("당신은 패배 하였습니다.\n");
			break;
		}

		int choice;
		printf("\n\n");
		printf("1. 뽑기 2. 승부 : ");
		scanf("%d", &choice);

		if (choice == 1) {
			struct Card pick;
			int pick_one = rand() % 52;
			pick = deck[pick_one];
			
			player[player_hand] = pick;
			player_hand++;
		}
		else if (choice == 2) {
			while (dsum < psum) {
				struct Card pick;
				int pick_one = rand() % 52;
				pick = deck[pick_one];
				dealer[dealer_hand] = pick;
				dealer_hand++;
				dsum += pick.num;
			}
			
			system("cls");
			printf("Dealer\n");
			for (int i = 0; i < dealer_hand; i++) {
				wprintf(L"%c", dealer[i].shape);
				printf("%d  ", dealer[i].num);
			}
			printf("\n\n");
			printf("Player\n");
			for (int i = 0; i < player_hand; i++) {
				wprintf(L"%c", player[i].shape);
				printf("%d  ", player[i].num);
			}

			if (dsum > 21 || psum >= dsum) {
				printf("당신은 승리 하였습니다.\n");
				break;
			}
			else if (dsum > psum) {
				printf("당신은 패배 하였습니다.\n");
				break;
			}
		}
	}
	



	return 0;
}