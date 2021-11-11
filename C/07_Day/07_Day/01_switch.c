#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int num;
	scanf("%d", &num);

	/*if (num == 1) {
		printf("num 은 1입니다.\n");
	}
	else if (num == 2) {
		printf("num 은 2입니다.\n");
	}
	else if (num == 3) {
		printf("num 은 3입니다.\n");
	}
	else {
		printf("num 은 1,2,3이 아닙니다.\n");
	}*/

	// switch (검사할 값)
	switch (num) {
		//num 의 케이스를 지정합니다.
		//num 이 1이라면
	case 1:
		printf("num 은 1입니다.\n");
		break;
		//num 이 2라면
	case 2:
		printf("num 은 2입니다.\n");
		break;
		//num 이 3이라면
	case 3:
		printf("num 은 3입니다.\n");
		break;
		// default : 위와 맞는 케이스가 없다면 실행합니다.
	default : 
		printf("num 은 1, 2, 3 이 아닙니다. \n");
		break;
	}
	
	return 0;
}