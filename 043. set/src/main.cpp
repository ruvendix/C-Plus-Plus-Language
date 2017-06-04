/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::set�� �ڷḦ �־�� ����غ��ϴ�.
 *
 */

#include <iostream>
#include <set> // set�� ����Ϸ��� �ʼ�!
#include <vector>

int main()
{
	std::vector<int> vecNum = {1, 4, 8, 9, 6, 3};
	
	// set�� vector ����
	std::set<int> setNum(vecNum.begin(), vecNum.end());

	// set�� �߰��� ����
	setNum.insert(7);

	// set ����ϱ�
	for (std::set<int>::iterator i = setNum.begin();
		i != setNum.end(); ++i)
	{
		printf("%d ", *i);
	}
	printf("\n");

	// set���� ���� �˻��ϱ�
	std::set<int>::iterator result;
	result = setNum.find(8);

	if (result != setNum.end())
	{
		printf("8�� �ֽ��ϴ�.\n");
	}
	else
	{
		printf("8�� �����ϴ�.\n");
	}

	return 0;
}
