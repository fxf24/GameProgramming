#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

// �ƽ�Ű �ڵ� ���� ����
const char upper_start = 'A';
const char upper_end = 'Z';
const char lower_start = 'a';
const char lower_end = 'z';

void printUpperCount(char word[]) {
	int count = 0;

	for (int i = 0; i < strlen(word); i++) {
		// �빮�� ���� �˻��մϴ�.
		if (upper_start <= word[i] && word[i] <= upper_end) {
			count++;
		}
	}
	printf("�빮�� ���� : %d \n", count);
}
void printLowerCount(char word[]) {
	int count = 0;

	for (int i = 0; i < strlen(word); i++) {
		// �ҹ��� ���� �˻��մϴ�.
		if (lower_start <= word[i] && word[i] <= lower_end) {
			count++;
		}
	}
	printf("�ҹ��� ���� : %d \n", count);
}
void printUpperCase(char word[]) {
	char cpy[256];
	strcpy(cpy, word);

	for (int i = 0; i < strlen(cpy); i++) {
		if (lower_start <= cpy[i] && cpy[i] <= lower_end) {
			cpy[i] -= 32;
		}
	}
	printf("�빮�ڷ� ��ȯ�մϴ�.\n");
	printf("%s \n", cpy);
}
void printLowerCase(char word[]) {
	char cpy[256];
	strcpy(cpy, word);

	for (int i = 0; i < strlen(cpy); i++) {
		if (upper_start <= cpy[i] && cpy[i] <= upper_end) {
			cpy[i] += 32;
		}
	}
	printf("�ҹ��ڷ� ��ȯ�մϴ�.\n");
	printf("%s \n", cpy);
}

int main()
{
	// ���ڿ� �Է�
	char inputString[256];
	printf("�Է� : ");
	scanf("%[^\n]s", inputString);

	// ���� ���� ����
	getchar();

	printUpperCase(inputString);
	printLowerCase(inputString);
	printUpperCount(inputString);
	printLowerCount(inputString);

	return 0;
}