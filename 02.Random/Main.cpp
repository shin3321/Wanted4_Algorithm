#include <iostream>
#include <time.h>

//나눗셈을 활용한 랜덤
int RandomRange(int min, int max)
{
	//범위의 차이
	int diff = (max - min) + 1;

	//나눗셈을 이용해서 원하는 범위의 랜덤 반환
	//이렇게 하면 0 아니면 1만 나옴
	//return rand() / (RAND_MAX + 1);
	return ((diff * rand()) / (RAND_MAX + 1)) + min/*최솟값 보정*/;
	//이러면 0부터 차이만큼 범위로 좁혀짐
}

//나눗셈을 이용한 랜덤 (부동소수형 - float)
float RandomPercent()
{
	//0-1사이의 부동소수형 값을 반환하는 랜덤 함수
	//한쪽만 casting 해 줘도 자동으로 양쪽 다 바꿔 줌

	return rand() / static_cast<float>(RAND_MAX);
}

//범위를 지정해 사용하는 랜덤 함수(부동소수형)
float RandomRange(float min, float max)
{
	//min- max 사이의 차 구하기
	int diff = max - min;
	return RandomPercent() * diff + min;
}

int main()
{
	//종자값(seed)설정
	//srand(100);
	srand(unsigned int(time(nullptr)));
	std::cout << "Random: " << RandomRange(1.0f, 10.0f) << "\n";
	std::cout << "Random: " << RandomRange(1.0f, 10.0f) << "\n";
	std::cout << "Random: " << RandomRange(1.0f, 10.0f) << "\n";
}