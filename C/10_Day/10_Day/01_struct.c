#include <stdio.h>

// 구조체
// 사용자가 정의하는 데이터 형식입니다.
// - 다양한 자료형을 하나로 묶을 수 있는 복합 데이터 구조를 가지고 있습니다.

// 복합 데이터 구조란?
// 기본 데이터 형식을 조합하여 만들어낸 구조를 뜻합니다.

// 구조체의 선언
// struct 구조체명
// {
//		멤버
// };
//

struct tag_cat
{
	int age;
	float height;
};

int main()
{
	// 우리가 만든 tag_cat 형식의 변수를 선언합니다.
	struct tag_cat Cat;

	// 구조체의 특정 공간에 접근할 때
	// 멤버접근 연산자 . 을 사용합니다.
	Cat.age = 5;
	Cat.height = 60.7f;

	printf("고양이 나이 : %d \n", Cat.age);
	printf("고양이의 크기 : %.1f cm\n", Cat.height);

	struct tag_cat myCat;

	myCat.age = 3;
	myCat.height = 30.1f;

	printf("고양이 나이 : %d \n", myCat.age);
	printf("고양이의 크기 : %.1f cm\n", myCat.height);

	return 0;
}