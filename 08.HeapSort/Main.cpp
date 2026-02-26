#include <iostream>

// 배열을 힙으로 만드는 함수
// array: 정렬 중인 배열
// length: 배열에 항복 수
// index: 현재 처리 중인 인덱스
void Heapify(int* array, int length, int index)
{
	// 힙 구정을 완료할 때까지 반봅
	while (true)
	{
		// 최대힙
		int largest = index;

		// 자손 인덱스 구하기
		// 왼쪽 자손: 2n+1
		int leftChild = 2 * index + 1;
		// 오른쪽 자손: 2n+2
		int rightChild = 2 * index + 2;

		// 더 큰 값 찾기 (+ 자손 인덱스 존재 여부 확인
		if (leftChild < length && array[leftChild] > array[largest])
		{
			largest = leftChild;
		}
		// 더 큰 값 찾기 (+ 자손 인덱스 존재 여부 확인
		if (rightChild < length && array[rightChild] > array[largest])
		{
			largest = rightChild;
		}

		// 현재 노드가 가장 크면 종료
		// 힙 구조가 유지된 것이기 때문
		if (largest == index)
		{
			break;
		}

		// 현재 노드와 자손 노드(가장 큰 값을 가지는) 교환
		std::swap<int>(array[index], array[largest]);

		//largest를 index로 업데이으,
		index = largest;
	}
}


// 힙 정렬 함수
void HeapSort(int* array, int length)
{
	// 힙 구조로 변환
	for (int i = length / 2 - 1; i >= 0; --i)
	{
		Heapify(array, length, i);
	}

	// 힙 정렬
	for (int i = length - 1; i > 0; --i)
	{
		// 0이 루트노드이기 때문에 for문 안 돌아도 됨
		// 루트 노드와 마지막 노드(현재 노드)를 교환
		std::swap<int>(array[0], array[i]);

		// 힙 구조를 유지하기 위해 루트 노드부터 다시 힙으로 만들기
		Heapify(array, ix, 0);
	}
}

int main()
{
	// 자료 집합.
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

}