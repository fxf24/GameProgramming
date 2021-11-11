// int 형 변수 num 을 선언하고
// num 의 값을 입력 받은 후
// num 이 음수인지, 양수인지, 0 인지를 검사하여
// 음수라면 num 은 음수입니다.
// 양수라면 num 은 양수입니다.
// 0 이라면 num 은 0 입니다.
// 를 출력해주세요 !

// 조건 : if, else if, else 를 모두 활용해주세요!
#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int num;
	scanf("%d", &num);

	if (num < 0) {
		printf("num은 음수입니다.\n");
	}
	else if (num > 0) {
		printf("num은 양수입니다.\n");
	}
	else {
		printf("num은 0입니다.\n");
	}
	return 0;
}