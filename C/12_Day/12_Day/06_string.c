#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)

int main()
{
	char str1[256];
	char str2[256];

	for (int i = 0; i < 2; i++) {
		char str[256];
		printf("���ڿ��� �Է��ϼ��� : ");
		scanf("%[^\n]s", str);
		printf("�Է¹��� ���ڿ� [ %s ] :: ���� [%d]\n", str, strlen(str));
		getchar();
		if (i == 0) {
			strcpy(str1, str);
		}
		else {
			strcpy(str2, str);
		}
	}
	
	printf("�� ���ڿ��� %s\n", strcmp(str1, str2) == 0 ? "�����ϴ�." : "�ٸ��ϴ�.");

	return 0;
}