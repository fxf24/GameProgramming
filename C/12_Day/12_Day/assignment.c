#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int main()
{
	int lower=0, upper=0;
	char str[256];
	printf("�Է� : ");
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 65 && str[i] <= 91) {
			upper++;
		}
		if (str[i] >= 97 && str[i] <= 123) {
			lower++;
		}
	}
	printf("�Է¹��� ���ڿ� �ҹ��� ��ȯ!\n");
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 65 && str[i] <= 91) {
			str[i] += 32;
		}
	}
	printf("%s\n", str);
	printf("�Է¹��� ���ڿ� �빮�� ��ȯ!\n");
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 97 && str[i] <= 123) {
			str[i] -= 32;
		}
	}
	printf("%s\n", str);
	printf("�ҹ��� ���� : %d\n", lower);
	printf("�빮�� ���� : %d\n", upper);

	return 0;
}