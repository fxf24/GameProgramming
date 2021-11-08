// 바라고자 하는 평균 값을 float 형 변수에 저장해주세요.
// 국어, 수학, 영어 점수를 저장할 int 형 변수 Kor, Mat, Eng 변수를 만들어
// scanf()를 통해 점수를 입력하여 평균을
// float형 변수에 저장하여 소수점 첫째자리까지 출력해주세요
// 바라고자하는 점수가 나왔다면 1을 아니라면 0을 출력해주세요 !

#include <stdio.h>
#pragma warning(disable : 4996)

int main()
{
	float Waverage, average;
	int Kor, Mat, Eng;
	printf("원하는 평균을 입력해주세요 : ");
	scanf("%f", &Waverage);
	printf("국어점수를 입력해주세요 : ");
	scanf("%d", &Kor);
	printf("수학점수를 입력해주세요 : ");
	scanf("%d", &Mat);
	printf("영어점수를 입력해주세요 : ");
	scanf("%d", &Eng);
	average = (float)(Kor + Mat + Eng) / 3;
	printf("평균 : %.1f\n", average);
	printf("%d", average >= Waverage);

	return 0;
}