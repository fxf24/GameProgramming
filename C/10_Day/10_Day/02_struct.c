#include <stdio.h>
#pragma warning (disable:4996)

struct Human {
	int age;
	float height;
	float weight;
};

int main()
{
	struct Human human;

	printf("나이를 입력해주세요 : ");
	scanf("%d", &human.age);
	printf("키를 입력해주세요 : ");
	scanf("%f", &human.height);
	printf("몸무게를 입력해주세요 : ");
	scanf("%f", &human.weight);

	printf("이 사람의 나이는 %d 살\n", human.age);
	printf("이 사람의 키는 %.1f cm\n", human.height);
	printf("이 사람의 몸무게는 %.1f kg\n", human.weight);

	return 0;
}