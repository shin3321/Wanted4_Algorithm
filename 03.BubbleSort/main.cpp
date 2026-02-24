#include <iostream>
#include <algorithm>

//함수 포인터 타입 지정
using Comparer = bool(*)(int, int);

//함수 포인터 활용
bool IsGreater(int left, int right)
{
	return left > right;
}

bool Isless(int left, int right)
{
	return left < right;
}

//함수 / 메소드: 둘 다 함수
//c++ 일반 함수 - Function
//객체의 멤버 함수 - Method

//java.c#에서는 구분 ㄴ, 애초에 함수가 없고 메소드만 있음.


//버블 정렬 함수
//비교 조건 확인 로직을 Comparer에게 맡김 -> 위임
//Delegate(델리게이트)
void BubbleSort(int* array, int length, Comparer comparer)
{
	//두 개씩 비교할 거라서 1개 뺌
	for (int i = 0; i < length - 1; ++i)
	{
		//한 번 돌면 한 개씩 정렬이 됨 => 정렬된 인덱스 뺌
		for (int j = 0; j < length - 1 - i; ++j)
		{
			// 비교, 큰 걸 오른쪽으로 밀음, 부호 반대면 작은 걸 오른쪽으로
			//if (array[j] > array[j + 1])
			if(comparer(array[j], array[j + 1]))
			{
				//교체
				std::swap<int>(array[j], array[j + 1]);
			}
		}
	}
}

//배열 출력 함수
void PrintArray(int* array, int length)
{
	for (int i = 0; i < length; ++i)
	{
		std::cout << array[i];
		if (i < length - 1)
		{
			std::cout << ", ";
		}
	}
}

int main()
{
	// 자료 집합.
	int array[] = { 11, 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	//배열 길이
	int length = sizeof(array) / sizeof(array[0]);

	//출력
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	//정렬
	BubbleSort(array, length, IsGreater);

	std::cout << "\n정렬 후 배열: ";
	PrintArray(array, length);
}