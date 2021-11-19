# Game Programming

## Orientation

1. 암기
   * 필요없다, 계속 코딩하면 저절로 알게된다.
2. 수학, 영어
   * 콘텐츠, 서버, AI, 엔진
     * 서버, AI, 엔진 쪽은 수학이 매우 필요하다.
     * 콘텐츠 쪽도 수학은 필요하긴 하지만 그렇게 어렵지 않다.
     * 수학을 잘하면 연봉이 쎄진다.
3.  커리큘럼
   * 1개월 : C
   * 2개월 : C++
   * 3 ~ 5개월 : API 5일 (창을 어떻게 띄우는지, 그래픽이 너무 구리다) /  Direct X (그래픽을 좀더 수월하게 나타내기 위한 언어) 그 후 같이 게임을 만들어 볼 것 (ex. 어몽어스)
   * 6개월 : 포트폴리오용 게임 제작, 여기까지는 2D 제작. 많은 포트폴리오보다 퀄리티 좋은 포트폴리오가 좋다. 3-4월, 9-11월 채용 이때 취업을 할 수 도 있다. 그러나 선택의 폭이 좁다. 이력서 상위 30개의 회사가 원하는 것이 다 다르다. 펄 어비스는 Direct X 로 자체 엔진을 개발했기 때문에 6개월만에 취업한다면 최고의 회사.
   * 7개월 이후: 언리얼 엔진 등

## C

### 01_Day

* ctrl + shift + s : 전체 파일 저장 (개발자의 생명줄)
* [출력](./C/01_Day/01_Day/01_Output.c)

### 02_Day

* [제어문자](./C/02_Day/02_Day/01_Control.c)
  * 출력의 제어 용도로 사용하기 위한 문자
* [자료형1](./C/02_Day/02_Day/01_Data_type.c)
  * 변수, 자료형, 자료형의 종류
* [자료형2](./C/02_Day/02_Day/02_Data_type.c)
  * 형식 문자 이용 출력

### 03_Day

* [자료형3](./C/03_Day/03_Day/01_Data_type.c)
  * unsigned
* [자료형4](./C/03_Day/03_Day/02_Data_type.c)
  * 실수 자료형, 실수 형식 문자
* [입력](./C/03_Day/03_Day/01_Input.c)
* [입력 연습](./C/03_Day/03_Day/02_Input.c)
* [상수](./C/03_Day/03_Day/01_Constant.c)
  * 변경할 수 없는 값

### 04_Day

* [산술연산자](./C/04_Day/04_Day/01_Arithmatic_Ops.c)
  * +, -, *, /, %
  * [문제](./C/04_Day/04_Day/02_Arithmatic_Ops.c)
* [비교연산자](./C/04_Day/04_Day/01_Comparing_Ops.c)
  * ==, !=, >, <, >=, <=
* [관계연산자](./C/04_Day/04_Day/01_Relation_Ops.c)
  * &&, ||, !
* [과제](./C/04_Day/04_Day/Assignment.c)

### 05_Day

* 연산자
  * [형변환 연산자](./C/05_Day/05_Day/01_Casting_Op.c)
    * [과제 응용](./C/05_Day/05_Day/02_Casting_Op.c)
  * [삼항연산자](./C/05_Day/05_Day/01_Ternary_Op.c)
    * [문제](./C/05_Day/05_Day/02_Ternary_Op.c)
  * [복합대입연산자](./C/05_Day/05_Day/01_Compound_Ops.c)
  * [단항연산자](./C/05_Day/05_Day/01_Unary_Op.c)

### 06_Day

* [비트 연산자](./C/06_Day/06_Day/01_Bit_Ops.c)
  * << ? : 비트를 왼쪽으로 ? 만큼 이동
  * \>\> ? : 비트를 오른쪽으로 ? 만큼 이동
  * & : 비트의 각 자리에 and 연산
  * | : 비트의 각 자리에 or 연산
  * ^ : 비트의 각 자리에 xor 연산 (각 자리가 다를때 1 )
  * ~ : 각 자리의 비트를 반전 not 연산
* 분기문
  * if 

### 07_Day

* 분기문
  * [if ](./C/07_Day/07_Day/01_if.c)
    * [문제1](./C/07_Day/07_Day/02_if.c)
    * [문제2](./C/07_Day/07_Day/03_if.c)
  * [switch](./C/07_Day/07_Day/01_switch.c)
    * [문제1](./C/07_Day/07_Day/02_switch.c)
* [과제](./C/07_Day/07_Day/assignment.c)

### 08_Day

* 반복문
  * [while](./C/08_Day/08_Day/01_while.c)
    * [예시](./C/08_Day/08_Day/02_while.c)
    * [구구단](./C/08_Day/08_Day/03_while.c), 1~100합, 10!
  * [for](./C/08_Day/08_Day/01_for.c)
    * [별찍기](./C/08_Day/08_Day/02_for.c)
  * [과제1](./C/08_Day/08_Day/assignment1.c)
  * [과제2](./C/08_Day/08_Day/assignment2.c)

### 09_Day

* 과제 풀이 [1](./C/09_Day/09_Day/01_while.c), [2](./C/09_Day/09_Day/02_for.c)
* [콘솔 명령어](./C/09_Day/09_Day/01_Console_Command.c)
* 점프문
  * [break](./C/09_Day/09_Day/01_break.c)
  * [continue](./C/09_Day/09_Day/02_continue.c)
* 응용 문제
  * [숫자 입력](./C/09_Day/09_Day/03_Jump.c)

* 난수
  * [난수 구하는 법](./C/09_Day/09_Day/01_random.c)
  * [문제](./C/09_Day/09_Day/02_random.c)
* [업다운게임](./C/09_Day/09_Day/UpdownGame.c)

### 10_Day

* [블랙잭](./C/10_Day/10_Day/Blackjack.c)
  * 52장의 카드를 저장할 공간
  * 구조체를 이용한 모양 저장
* [구조체](./C/10_Day/10_Day/01_struct.c)
  * [응용 문제](./C/10_Day/10_Day/02_struct.c)
* [배열](./C/10_Day/10_Day/01_array.c)
  * [응용 문제](./C/10_Day/10_Day/02_array.c)
  * [트럼프 카드](./C/10_Day/10_Day/03_array.c)

### 11_Day

* 구조체 
  * [typedef](./C/11_Day/11_Day/01_struct.c)
* [문자열](./C/11_Day/11_Day/01_string.c)
* [과제](./C/11_Day/11_Day/assignment.c)

### 12_Day

* 문자열
  * [scanf 와 buffer](./C/12_Day/12_Day/01_string.c)
  * [getchar() 와 %[ ^\n]s](./C/12_Day/12_Day/02_string.c)
  * [공백이 포함된 문자열 입력받기](./C/12_Day/12_Day/03_string.c)
  * [아스키코드](./C/12_Day/12_Day/04_string.c)
  * [string.h](./C/12_Day/12_Day/05_string.c)
  * [응용 문제](./C/12_Day/12_Day/06_string.c)
* [과제](./C/12_Day/12_Day/assignment.c)

### 13_Day

* 
