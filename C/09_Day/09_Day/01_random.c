#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// ����
// ������ ���� �ǹ��մϴ�.
// stdlib.h �� ���Խ��Ѿ� ����� �����մϴ�.

int main()
{
	// ���� �õ带 �����մϴ�.
	srand(GetTickCount64());
	// srand() : ��ǻ�Ϳ��� Ư���� ��Ģ���� �������� ������� ����ϴ� �����Դϴ�.
	// GetTickCount64() : ��ǻ�Ͱ� ������ ������ �����ð��� �и��� ������ ��ȯ�մϴ�.

	// 10 ���� �������� �̴� �ݺ���
	for (int i = 0; i < 10; ++i)
	{
		int randomvalue = rand() % 5;
		// ������ �̴� ���
		// rand() �� ����մϴ�.
		// rand() % n : 0 ~ (n - 1) ������ �� �� �ϳ��� ���ڸ� �̽��ϴ�.
		printf("���� ���� : %d \n", randomvalue);
	}

	return 0;
}