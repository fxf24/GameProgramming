#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	// 목표 평균을 저장할 변수를 선언합니다.
	float Waverage;

	// Want 에 입력값을 저장합니다.
	printf("원하는 평균을 입력해주세요 : ");
	scanf("%f", &Waverage);

	// 각 과목의 점수를 저장할 변수를 선언합니다.
	int Kor, Mat, Eng;
	printf("국어점수를 입력해주세요 : ");
	scanf("%d", &Kor);
	printf("수학점수를 입력해주세요 : ");
	scanf("%d", &Mat);
	printf("영어점수를 입력해주세요 : ");
	scanf("%d", &Eng);

	// 연산한 결과값을 정수 형태가 아닌
	// float 형태로 결과값을 나타냅니다.
	float average;
	average = (float)(Kor + Mat + Eng) / 3;

	// 목표 평균에 도달 하였는지를 검사합니다.
	char reach = average >= Waverage;

	printf("평균 : %.2f\n", average);
	printf("목표 달성 : %d\n", reach);

	return 0;
}