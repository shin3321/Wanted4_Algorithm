#include <iostream>
#include <Windows.h>

//삽입 정렬 함수
void InsertionSort(int* array, int length)
{
	//예외 처리
	if (length <= 1)
	{
		return;
	}

	// [8][5][6][2][4]
	// 8은 정렬이 되어 있다고 생각, 
	// 1: key: [5] [8] [6][2][4]
	// [5][8][6][2][4]	
	// 다음 6을 가져와서 정렬이 된 8, 5과 비교하여 정렬함 그 다음 2를 가져와서 8, 6, 5과 비교하여 정렬 ...

	//배열 순회
	for (int i = 1; i < length; ++i)
	{
		//현재 삽입할 값 => i가 1이라서 두 번째 값이 나옴
		int key = array[i];
		int j = i - 1;
		
		while (j >= 0 && array[j] > key) //두 번째 부호 바꾸면 내림차순 정렬 => 이것도 함수 포인터로 바꿀 수 있음
		{
			array[j + 1] = array[j];
			--j;
		}
		
		//적절한 위치에 key 삽입
		//키가 하나 빠져 있기 때문에 j + 1에 key를 삽입함
		array[j + 1] = key;
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
	std::cout << "\n";
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	//배열 사이즈 구하기
	//int length = ARRAYSIZE(array);
	int length = _countof(array);

	//출력
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	//정렬
	InsertionSort(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);
}