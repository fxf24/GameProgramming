#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning (disable : 4996)

int main()
{
	srand(GetTickCount64());

	printf("UpDownGame!\n");
	printf("���� �������� : 1 ~ 20\n");
	system("pause");
	system("cls");
	int answer = rand() % 20 + 1;
	int chance = 5;

	while (1) {
		printf("���� ��ȸ = %d\n", chance);
		int input;
		printf("������ �Է��ϼ��� : ");
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
				printf("�����Դϴ�!\n");
				break;
			}	
		}
		if (chance == 0) {
			system("cls");
			printf("��ȸ�� ��� �����ϼ̽��ϴ�!\n");
			printf("������ %d �����ϴ�!\n", answer);
			break;
		}
		Sleep(500);
		system("cls");
	}

	return 0;
}