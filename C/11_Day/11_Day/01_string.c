#include <stdio.h>
#pragma warning(disable : 4996);
int main()
{
	// �迭�� ����� ���ÿ� �ʱ�ȭ�� �Ͻ� �� �ֽ��ϴ�.
	int arr[3] = { 1, 2, 3 };

	int arr2[] = { 1, 2, 3 };

	char str1[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	// '\0' (�ι���)
	// ��ǻ�Ͱ� ���ڿ��� ���� �����ϱ� ���ؼ� ����մϴ�.

	printf("%s \n", str1);

	char str2[] = "Helloworld!";
	printf("%s \n", str2);

	char str3[256];
	printf("���ڿ��� �Է��ϼ���: ");
	scanf("%s", str3);
	// ���ڿ��� �Է¹��� ���� & �� �����ϼŵ� �˴ϴ�.
	printf("�Է¹��� ���ڿ� : %s \n", str3);
	return 0;
}