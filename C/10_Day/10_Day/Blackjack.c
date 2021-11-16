#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

struct Card
{
	int used;  // 0 : 사용되지 않음, 1 : 사용됨
	int shape; // 0 : 스페이드, 1 : 클로버, 2 : 다이아, 3 : 하트
	int num;
};
int count_deck(struct Card deck[]) {
	int count = 0;
	for (int i = 0; i < 52; i++) {
		if (!deck[i].used)
		{
			count += 1;
		}
	}
	return count;
}
void card_check(struct Card deck) {
	switch (deck.shape) {
	case 0:
		printf("스페이드 %d\t", deck.num);
		break;
	case 1:
		printf("클로버 %d\t", deck.num);
		break;
	case 2:
		printf("다이아 %d\t", deck.num);
		break;
	case 3:
		printf("하트 %d\t", deck.num);
		break;
	}
}
int main()
{
	struct Card deck[52];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[i * 13 + j].used = 0;
			deck[i * 13 + j].shape = i;
			deck[i * 13 + j].num = j+1;
		}
	}

	for (int i = 0; i < 52; i++) {
		switch (deck[i].shape) {
		case 0:
			printf("스페이드 %d\n", deck[i].num);
			break;
		case 1:
			printf("클로버 %d\n", deck[i].num);
			break;
		case 2:
			printf("다이아 %d\n", deck[i].num);
			break;
		case 3:
			printf("하트 %d\n", deck[i].num);
			break;
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
		while (1) {
			int pick_one = rand() % 52;
			pick = deck[pick_one];
			card_check(pick);
			if (pick.used == 1) {
				continue;
			}
			else {
				deck[pick_one].used = 1;
				break;
			}
		}

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
	}

	printf("딜러의 패\n");

	for (int i = 0; i < 2; i++) {
		card_check(dealer[i]);
	}

	printf("플레이어의 패\n");

	for (int i = 0; i < 2; i++) {
		card_check(player[i]);
	}

	return 0;
}