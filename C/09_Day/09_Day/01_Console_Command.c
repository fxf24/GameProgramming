#include <stdio.h>
#include <windows.h>

// �ܼ� ��ɾ�
// �ܼ�â�� ������ �� Ư���� ����� ����� �� �ִ� ��ɾ�
// windows.h �� �߰����Ѿ� ����� �����մϴ�.

int main()
{
	int count = 1;

	while (1)
	{
		printf("%d   ", count);
		++count;
		// Sleep(500);
		// Sleep() : Ư�� �ð����� ����� ����մϴ�.
		system("pause");
		// system("pause") : ���� Ű�� �Է� ���� ������ ����� ����մϴ�.
		system("cls");
		// system("cls") : �ܼ�â�� ��� ����ϴ�.
	}

	return 0;
}