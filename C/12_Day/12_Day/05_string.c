#include <stdio.h>
#pragma warning(disable: 4996)
#include <string.h>
// string.h : ���ڿ��� �ٷ� �� �ִ� �ڵ带 �����ϴ� �����Դϴ�.

int main()
{
	char myString1[] = "Hello World";

	// ���ڿ� ���� ���ϱ�
	int length = strlen(myString1);
	// strlen(str) = str �� ���̸� ��Ÿ���ϴ�.

	printf("myString1 �� ���� : %d \n", length);

	char myString2[] = "Apple";
	printf("myString1 = %s\n", myString1);
	printf("��ȯ \n");
	strcpy(myString1, myString2);
	// strcpy(str1, str2) : str1 �� ���ڿ��� str2 �� ������ �ִ� ���ڿ��� �ʱ�ȭ ��ŵ�ϴ�.
	printf("myString1 = %s\n", myString1);

	char myString3[] = "Melon";
	printf("(myString1 == myString2) = %s \n", (strcmp(myString1, myString2) == 0 ? "True" : "False"));
	printf("(myString1 == myString3) = %s \n", (strcmp(myString1, myString3) == 0 ? "True" : "False"));
	// strcmp(str1, str2) : str1 �� str2 �� ������ �ִ� ���ڿ��� ���մϴ�. ���ڿ��� ���ٸ� 0��, �ٸ��� -1 Ȥ�� 1�� ��ȯ�մϴ�.

	return 0;
}