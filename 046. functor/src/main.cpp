/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::for_each�� �̿��ؼ� �Լ� ��ü�� ����غ��ϴ�.
 *
 */

#include <algorithm> // for_each()�� ����Ϸ��� �ʼ�!
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

	//// �Լ� ������ ���
	//std::for_each(vecNum.begin(), vecNum.end(), ShowNum);
	//printf("\n");

	//// �Լ� ��ü ���
	//std::for_each(vecNum.begin(), vecNum.end(), Data());
	//printf("\n");

	// �Լ� ��ü ����� ����ϱ�
	std::for_each(vecNum.begin(), vecNum.end(), Functor());

	return 0;
}
