#include <stdio.h>
#include <Windows.h>
#pragma warning (disable : 4996)


typedef unsigned int UINT;
// typedef : 자료형에게 별칭을 붙여주는 키워드입니다.
// typedef "자료형" "별칭"
//


typedef struct tag_Student {
	// 학생의 번호를 저장할 변수
	UINT studentId;
	// 학생의 이름을 저장할 배열
	char name[20];
} Student;

typedef struct tag_Classroom {
	// 몇 반인지를 저장할 변수
	int number;
	// 학생들의 정보를 저장할 배열
	Student students[5];
}Classroom;

int main()
{
	UINT number = 0;
	
	Classroom class_1;

	class_1.number = 3;
	for (int i = 0; i < 5; i++) {
		class_1.students[i].studentId = i+1;
		printf("%d 번 학생 이름 : ", i + 1);
		scanf("%s", class_1.students[i].name);
	}

	system("cls");
	printf("%d 반\n\n", class_1.number);
	for (int i = 0; i < 5; i++) {
		printf("학생 번호 : %d \n", class_1.students[i].studentId);
		printf("이름 : %s\n", class_1.students[i].name);
	}

	return 0;
}