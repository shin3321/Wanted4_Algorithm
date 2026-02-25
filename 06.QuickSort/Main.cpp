#include <iostream>
#include <Windows.h>

//파티션 함수
//기준점 - pivot 선택 및 분할 함수 
int Partition(int* array, int left, int right)
{
	//분할을 위한 변수
	//전달된 배열의 첫 항목을 피벗으로 선택
	int pivot = array[left];
	int low = left + 1;
	int high = right;

	//왼쪽에서 오른쪽으로, 오른쪽에서 왼쪽으로 이동하면서 분할 처리
	//만나거나 교차하면 끝남
	while (low <= right)
	{
		//왼쪽애서 오른쪽으로 이동 처리
		//기준값보다 큰 값 찾기(low 증가 처리_
		while (low <= right && array[low] <= pivot)
		{
			++low;
		}

		//오른쪽애서 왼쪽으로 이동 처리
		//기준값보다 작은 값 찾기(low 증가 처리_
		while (high > left && array[high] >= pivot)
		{
			--high;
		}

		//두 인덱스가 교체했는지 확인
		if (low > high)
		{
			break;
		}
		//low와 high를 교환
		std::swap<int>(array[low], array[high]);
	}
	//피벗 값과 왼쪽 데이터 집합의 마지막 요소(high)를 교환
	//array[left]: 현재 피벗
	std::swap<int>(array[left], array[high]);

	//피벗의 최종 위치 반환 왜 high인지 생각해 보기
	return high;
}

//퀵 정렬 재귀 함수
void QuickSort(int* array, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//배열 분할
	int pivot = Partition(array, left, right);

	// 피봇을 기준으로 작은 숫자들이 정렬된 왼쪽 배열 정렬 (재귀).
	QuickSort(array, left, pivot - 1);

	// 피봇을 기준으로 큰 숫자들이 정렬된 오른쪽 배열 정렬 (재귀).
	QuickSort(array, pivot + 1, right);
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
	int array[] =
	{
		1, 58, 10, 20, 56, 63, 73, 5, 28, 37,
		80, 61, 82, 45, 11, 66, 83, 59, 22, 64,
		52, 89, 94, 76, 44, 40, 75, 2, 23, 57,
		92, 8, 41, 96, 15, 84, 35, 69, 54, 47,
		90, 24, 43, 74, 34, 85, 72, 95, 18, 17,
		98, 9, 29, 53, 27, 79, 39, 51, 31, 16,
		6, 97, 26, 100, 21, 48, 33, 60, 91, 19,
		30, 13, 71, 78, 87, 25, 81, 4, 42, 93,
		49, 12, 14, 7, 62, 77, 38, 99, 88, 50,
		32, 46, 70, 3, 86, 68, 36, 67, 55, 65
	};

	//배열 사이즈 구하기
	//int length = ARRAYSIZE(array);
	int length = _countof(array);

	//출력
	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	//정렬
	QuickSort(array, 0, length - 1);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);
}