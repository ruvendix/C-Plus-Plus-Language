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
	std::deque<society::Human*> deqHuman;

	deqHuman.resize(2); // ���̸� 2���� �޸� ���Ҵ�

	// �̸� ���̸� 2���� ���������Ƿ� vecHuman�� ���̴� 2
	printf("deqHuman�� ���� : %d\n\n", deqHuman.size());

	// deqHuman�� ��� 2�� ����
	// �� ���� ������ �ƴ϶� ������!
	// �ֳ�? �̸� �ڸ��� �����߱� ����!
	deqHuman[0] = new society::Police;
	deqHuman[1] = new society::Chief;

	for (int i = 0; i < deqHuman.size(); ++i)
	{
		// deqHuman[i]���� society::Human*�� ����
		// ������ �迭�� �̿��Ѵٰ� �����ϸ� ��
		deqHuman[i]->ShowInfo();
	}
	printf("-------------------------------------------\n");

	// ���ο� ��Ҹ� �ְԵǸ� �޸� ���Ҵ� �߻�!
	// ������ ���� ���̴� �۾��� �ƴϹǷ� �ν��ϱ�� �����!
	deqHuman.push_front(new society::Detective);
	printf("deqHuman�� ���� : %d\n\n", deqHuman.size());

	for (int i = 0; i < deqHuman.size(); ++i)
	{
		// deqHuman[i]���� society::Human*�� ����
		// ������ �迭�� �̿��Ѵٰ� �����ϸ� ��
		deqHuman[i]->ShowInfo();
	}
	printf("-------------------------------------------\n");

	// �����̳ʴ� �˾Ƽ� �޸𸮸� ����������
	// ����ڰ� ���� �Ҵ����� �޸𸮴� �������� ����!
	// ���� ���� �Ҵ����� �޸𸮴� �˾Ƽ� �����ؾ� ��!
	for (int i = 0; i < deqHuman.size(); ++i)
	{
		delete deqHuman[i];
	}

	// �츮 ������ ������ �ʴ� ���� �۾�
	deqHuman.clear();
	return 0;
}
