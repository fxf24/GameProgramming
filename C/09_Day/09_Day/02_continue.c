#include <stdio.h>
#include <windows.h>

// continue
// ���� �������� �ݺ����� �ݺ��� �ѹ� �ǳ� �ٰ��� �� �� ����մϴ�.


int main()
{
	int count = 1;

	while (count < 10)
	{
		printf("count = %d \n", count);

		Sleep(500);

		// ���� count �� 5���
		if (count == 5)
		{
			// ���� �ݺ��� ���߰� ���ǽ����� ���ư��ϴ�.
			continue;
		}

		count++;

	}


	return 0;
}