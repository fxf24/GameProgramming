#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

struct Card
{
	int used;  // 0 : ������ ����, 1 : ����
	int shape; // 0 : �����̵�, 1 : Ŭ�ι�, 2 : ���̾�, 3 : ��Ʈ
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
		printf("�����̵� %d\t", deck.num);
		break;
	case 1:
		printf("Ŭ�ι� %d\t", deck.num);
		break;
	case 2:
		printf("���̾� %d\t", deck.num);
		break;
	case 3:
		printf("��Ʈ %d\t", deck.num);
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
			printf("�����̵� %d\n", deck[i].num);
			break;
		case 1:
			printf("Ŭ�ι� %d\n", deck[i].num);
			break;
		case 2:
			printf("���̾� %d\n", deck[i].num);
			break;
		case 3:
			printf("��Ʈ %d\n", deck[i].num);
			break;
		}
	}

	printf("����\n");
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

	printf("������ ��\n");

	for (int i = 0; i < 2; i++) {
		card_check(dealer[i]);
	}

	printf("�÷��̾��� ��\n");

	for (int i = 0; i < 2; i++) {
		card_check(player[i]);
	}

	return 0;
}