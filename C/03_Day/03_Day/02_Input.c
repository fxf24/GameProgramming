#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	int year, month, date;
	printf("고양이가 태어난 년도를 입력하세요 : ");
	scanf("%d", &year);
	printf("고양이가 태어난 달을 입력하세요 : ");
	scanf("%d", &month);
	printf("고양이가 태어난 일을 입력하세요 : ");
	scanf("%d", &date);
	printf("내 고양이는 %d 년 %d 월 %d 일에 태어났습니다. \n", year, month, date);

	return 0;
}