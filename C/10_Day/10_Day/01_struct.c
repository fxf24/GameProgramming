#include <stdio.h>

// ����ü
// ����ڰ� �����ϴ� ������ �����Դϴ�.
// - �پ��� �ڷ����� �ϳ��� ���� �� �ִ� ���� ������ ������ ������ �ֽ��ϴ�.

// ���� ������ ������?
// �⺻ ������ ������ �����Ͽ� ���� ������ ���մϴ�.

// ����ü�� ����
// struct ����ü��
// {
//		���
// };
//

struct tag_cat
{
	int age;
	float height;
};

int main()
{
	// �츮�� ���� tag_cat ������ ������ �����մϴ�.
	struct tag_cat Cat;

	// ����ü�� Ư�� ������ ������ ��
	// ������� ������ . �� ����մϴ�.
	Cat.age = 5;
	Cat.height = 60.7f;

	printf("����� ���� : %d \n", Cat.age);
	printf("������� ũ�� : %.1f cm\n", Cat.height);

	struct tag_cat myCat;

	myCat.age = 3;
	myCat.height = 30.1f;

	printf("����� ���� : %d \n", myCat.age);
	printf("������� ũ�� : %.1f cm\n", myCat.height);

	return 0;
}