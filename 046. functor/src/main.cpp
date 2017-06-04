/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::for_each를 이용해서 함수 객체를 사용해봅니다.
 *
 */

#include <algorithm> // for_each()를 사용하려면 필수!
#include <iostream>
#include <vector>

void ShowNum(int num)
{
	printf("%d ", num);
}

class Data
{
public:
	void operator() (int num)
	{
		printf("%d ", num);
	}
};

class Functor
{
public:
	Functor() : m_sum(0)
	{ 

	}

	Functor(const Functor& rhs)
	{

	}

	void ShowNum() const
	{
		printf("m_sum : %d\n", m_sum);
	}

	void operator() (int num)
	{
		m_sum += num;
		ShowNum();
	}

private:
	int m_sum;
};

int main()
{
	std::vector<int> vecNum;
	const int vecSize = 10;
	vecNum.reserve(vecSize);
	for (int i = 0; i < vecSize; ++i)
	{
		vecNum.push_back(i);
	}

	//// 함수 포인터 사용
	//std::for_each(vecNum.begin(), vecNum.end(), ShowNum);
	//printf("\n");

	//// 함수 객체 사용
	//std::for_each(vecNum.begin(), vecNum.end(), Data());
	//printf("\n");

	// 함수 객체 제대로 사용하기
	std::for_each(vecNum.begin(), vecNum.end(), Functor());

	return 0;
}
