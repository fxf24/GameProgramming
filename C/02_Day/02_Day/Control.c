#include <stdio.h>

// 제어문자
// - 출력의 제어 용도로 사용하기 위한 문자들을 의미합니다.

// - \n : 개행 문자 - 줄을 바꿉니다.
// - \t : 탭 문자	- 출력 위치를 다음 탭 위치로 옮깁니다.
// - \r : 캐리지 리턴 문자	- 출력 커서 위치를 현재 라인의 시작 위치로 옮깁니다.
// - \a : 얼럿 문자			- 알림소리를 냅니다.

// - \" : 큰 따옴표 문자	- (") 를 출력합니다.
// - \' : 작은 따옴표 문자	- (') 를 출력합니다.
// - %% : 퍼센티지 문자		- (%) 를 출력합니다.
// - \\ : 역슬래쉬 문자		- (\) 를 출력합니다.

int main()
{
	// 콘솔창에 안녕하세요를 2번 출력해주세요.
	printf("안녕하세요 \n");
	printf("안녕하세요 \n");


	return 0;
}