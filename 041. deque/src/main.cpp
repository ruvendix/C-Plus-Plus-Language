/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::deque�� �ڷḦ �־�� ����غ��ϴ�.
 *
 */

#include <iostream>
#include <list>
#include <vector>

#define PURE = 0

namespace society
{
	class Human
	{
	public:
		virtual void ShowInfo() PURE;
	};

	class Police : public Human
	{
	public:
		virtual void ShowInfo()
		{
			printf("�� ������ ����!\n");
		}
	};

	class Chief : public Human
	{
	public:
		virtual void ShowInfo()
		{
			printf("�� ������ ����!\n");
		}
	};

	class Detective : public Human
	{
	public:
		virtual void ShowInfo()
		{
			printf("�� �̸��� �ڳ�! Ž������!\n");
		}
	};
}

int main()
{
	std::list<society::Human*> listHuman(2); // Ŭ���� ������ ������ 2�� ����

	// �̸� ���̸� 2���� ���������Ƿ� listHuman�� ���̴� 2
	printf("listHuman�� �ڷ� ���� ��\n");
	printf("listHuman�� ���� : %d\n\n", listHuman.size());

	// listHuman�� ��� 2�� ����
	// �� ���� ������ �ƴ϶� ������!
	// �ֳ�? �̸� �ڸ��� �����߱� ����!
	// listHuman[0] �̰� �Ұ���!
	// �Ʒ�ó�� ���� push_front()�� ��
	society::Police police;
	listHuman.insert(listHuman.begin(), &police);

	// �Ʒ�ó�� ���� push_back()�� ��
	society::Chief chief;
	listHuman.insert(listHuman.end(), &chief);

	// �̸� ������ ���̿� 2���� �߰��Ǿ����Ƿ� listHuman�� ���̴� 4
	printf("listHuman�� �ڷ� ���� ��\n");
	printf("listHuman�� ���� : %d\n\n", listHuman.size());

	// �츮 ������ ������ �ʴ� ���� �۾�
	listHuman.clear();
	return 0;
}
