#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char str1[256];

	printf("���Ⱑ �ִ� ���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]s", str1);
	// %[^\n]s : \n (���๮��) �� �������� ���ۿ��� �����͸� ����� �����մϴ�.
	//str1[7] = getchar();
	//str1[6] = getchar();
	//str1[8] = getchar();
	//str1[5] = getchar();
	//str1[9] = getchar();
	//str1[10] = getchar();
	//str1[11] = '\0';

	printf("�Է¹��� ���ڿ� : %s\n", str1);
	// getchar() : ���ۿ� �����ִ� �����͸� �ϳ��� ��ȯ�մϴ�.
	getchar();

	char str2[256];
	printf("���Ⱑ �ִ� ���ڿ��� �Է��ϼ��� : ");
	scanf("%[^\n]s", str2);
	printf("�Է¹��� ���ڿ� : %s\n", str2);

	return 0;
}