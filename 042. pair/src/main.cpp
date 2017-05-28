/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::pair�� �ڷḦ �־�� ����غ��ϴ�.
 *
 */

#include <iostream>
#include <utility> // pair�� ����Ϸ��� �ʼ�!

int main()
{
	// int�� double�� �ϳ��� type���� ����!
	std::pair<int, double> pairData;

	pairData.first  = 10;    // int�� �ǹ�
	pairData.second = 20.0f; // double�� �ǹ�

	printf("first  : %d\n", pairData.first);
	printf("second : %.2f\n\n", pairData.second);

	// pair ���� ���� ����
	pairData = std::make_pair(20, 10.0f);

	printf("first  : %d\n", pairData.first);
	printf("second : %.2f\n", pairData.second);

	return 0;
}
