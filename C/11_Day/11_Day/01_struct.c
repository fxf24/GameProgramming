#include <stdio.h>
#include <Windows.h>
#pragma warning (disable : 4996)


typedef unsigned int UINT;
// typedef : �ڷ������� ��Ī�� �ٿ��ִ� Ű�����Դϴ�.
// typedef "�ڷ���" "��Ī"
//


typedef struct tag_Student {
	// �л��� ��ȣ�� ������ ����
	UINT studentId;
	// �л��� �̸��� ������ �迭
	char name[20];
} Student;

typedef struct tag_Classroom {
	// �� �������� ������ ����
	int number;
	// �л����� ������ ������ �迭
	Student students[5];
}Classroom;

int main()
{
	UINT number = 0;
	
	Classroom class_1;

	class_1.number = 3;
	for (int i = 0; i < 5; i++) {
		class_1.students[i].studentId = i+1;
		printf("%d �� �л� �̸� : ", i + 1);
		scanf("%s", class_1.students[i].name);
	}

	system("cls");
	printf("%d ��\n\n", class_1.number);
	for (int i = 0; i < 5; i++) {
		printf("�л� ��ȣ : %d \n", class_1.students[i].studentId);
		printf("�̸� : %s\n", class_1.students[i].name);
	}

	return 0;
}