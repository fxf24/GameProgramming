#pragma once

// 클래스 .h 파일에서는 멤버변수의 선언과 멤버함수의 선언을 작성합니다.
// .cpp 파일에서는 멤버함수의 정의를 작성합니다.

// #include 로 해당 파일 포함시킨다면 컴파일러가 해당 클래스의 cpp 파일 또한 같이 읽어드립니다.

class MyClass
{
public :
	int Memvar;

public :
	MyClass() = default;
	MyClass(int Mem);
	~MyClass() = default;

public :
	void PrintMember() const;
};

