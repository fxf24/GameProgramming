#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)

int main()
{
	// �ƽ�Ű �ڵ� ���� ����
	const char upper_start = 'A';
	const char upper_end = 'Z';
	const char lower_start = 'a';
	const char lower_end = 'z';

	// ���ڿ� �Է�
	char inputString[256];
	printf("�Է� : ");
	scanf("%[^\n]s", inputString);
	
	// ���� ���� ����
	getchar();

	// ��ҹ��� ���� ���
	// �빮���� ������ ������ ����
	int upperCount = 0;
	// �ҹ����� ������ ������ ����
	int lowerCount = 0;

	// �Է¹��� ���ڿ��� ���� ��ŭ �ݺ�
	for (int i = 0; i < strlen(inputString); i++) {
		// �빮�� ���� �˻��մϴ�.
		if (upper_start <= inputString[i] && inputString[i] <= upper_end) {
			upperCount++;
		}
		// �ҹ��� ���� �˻��մϴ�.
		else if (lower_start <= inputString[i] && inputString[i] <= lower_end) {
			lowerCount++;
		}
	}
	printf("�빮�� ���� : %d \n", upperCount);
	printf("�ҹ��� ���� : %d \n", lowerCount);

	// �빮�ڷ� ��ȯ�մϴ�.
	for (int i = 0; i < strlen(inputString); i++) {
		if (lower_start <= inputString[i] && inputString[i] <= lower_end) {
			inputString[i] -= 32;
		}
	}

	printf("�빮�ڷ� ��ȯ�մϴ�.\n");
	printf("%s \n",inputString);

	// �ҹ��ڷ� ��ȯ�մϴ�.
	for (int i = 0; i < strlen(inputString); i++) {
		if (upper_start <= inputString[i] && inputString[i] <= upper_end) {
			inputString[i] += 32;
		}
	}

	printf("�ҹ��ڷ� ��ȯ�մϴ�.\n");
	printf("%s \n", inputString);

	return 0;
}