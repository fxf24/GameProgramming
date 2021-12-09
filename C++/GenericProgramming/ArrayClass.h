#pragma once
#include <iostream>
using namespace std;

#define INDEX_NONE -1
#define FORCEINLINE __forceinline

typedef unsigned int UINT;

// Add(Parameter value) : Parameter Value 의 요소를 추가해주는 함수
// GetLength()			: 현재 ArrayClass 에 추가한 요소의 개수를 반환하는 함수
// Get(index)			: index 번호의 요소의 값을 출력해주는 함수
template<typename T>
class ArrayClass final
{
private :
	int length;
	T* arr;

public :
	ArrayClass()
	{
		arr = nullptr;
		length = 0;
	}
	virtual ~ArrayClass()
	{
		if (arr) {
			delete[] arr;
			arr = nullptr;
		}
	}

public :
	void Add(T value)
	{
		length++;
		if (length == 1) {
			arr = new T[length];
			arr[length - 1] = value;
		}
		else {
			T* temp = arr;

			arr = new T[length];
			for (int i = 0; i < length-1; i++) {
				arr[i] = temp[i];
			}
			arr[length - 1] = value;

			delete[] temp;
			temp = nullptr;
		}
	}

	FORCEINLINE int GetLength() const
	{
		return length;
	}

	T Get(int index) const
	{
		if (index >= length) {
			cout << "범위를 초과했습니다 !" << endl;
			return INDEX_NONE;
		}
		else if (index < 0)
		{
			cout << "Index 번호는 음수값을 가질 수 없습니다!" << endl;
			return INDEX_NONE;
		}
		return arr[index];
	}
};

