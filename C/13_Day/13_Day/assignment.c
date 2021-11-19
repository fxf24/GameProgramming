#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

// �ƽ�Ű �ڵ� ���� ����
const char upper_start = 'A';
const char upper_end = 'Z';
const char lower_start = 'a';
const char lower_end = 'z';

int printUpperCount(char word[]) {
	int count = 0;
	for (int i = 0; i < strlen(word); i++) {
		// �빮�� ���� �˻��մϴ�.
		if (upper_start <= word[i] && word[i] <= upper_end) {
			count++;
		}
	}
	printf("�빮�� ���� : %d \n", count);
	
	return count;
}
int printLowerCount(char word[]) {
	int count = 0;
	for (int i = 0; i < strlen(word); i++) {
		// �ҹ��� ���� �˻��մϴ�.
		if (lower_start <= word[i] && word[i] <= lower_end) {
			count++;
		}
	}
	printf("�ҹ��� ���� : %d \n", count);
	return count;
}
void printUpperCase(char word[]) {
	for (int i = 0; i < strlen(word); i++) {
		if (lower_start <= word[i] && word[i] <= lower_end) {
			word[i] -= 32;
		}
	}
	printf("�빮�ڷ� ��ȯ�մϴ�.\n");
	printf("%s \n", word);
}
void printLowerCase(char word[]) {
	for (int i = 0; i < strlen(word); i++) {
		if (upper_start <= word[i] && word[i] <= upper_end) {
			word[i] += 32;
		}
	}
	printf("�ҹ��ڷ� ��ȯ�մϴ�.\n");
	printf("%s \n", word);
}

int main()
{
	// ���ڿ� �Է�
	char inputString[256];
	printf("�Է� : ");
	scanf("%[^\n]s", inputString);

	// ���� ���� ����
	getchar();

	printUpperCount(inputString);
	printLowerCount(inputString);
	printUpperCase(inputString);
	printLowerCase(inputString);
	

	return 0;
}