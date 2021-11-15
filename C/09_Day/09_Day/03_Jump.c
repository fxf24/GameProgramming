#include <stdio.h>
#include <windows.h>
#pragma warning(disable : 4996);

int main()
{
	while (1)
	{
		int num;
		printf("숫자를 입력하세요 : ");
		scanf("%d", &num);

		if (num <= 10) {
			printf("number 의 값이 10 이하입니다. \n");
			system("pause");
			system("cls");
		}
		else {
			printf("number 의 값이 11 이상입니다. \n");
			break;
		}
	}


	return 0;
}