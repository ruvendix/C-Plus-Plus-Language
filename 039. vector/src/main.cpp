/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::vector�� �ڷḦ �־�� ����غ��ϴ�.
 *
 */

#include <iostream>
#include <vector> // vector�� ����Ϸ��� �ʼ�!

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
	std::vector<society::Human*> vecHuman(2); // Ŭ���� ������ ������ 2�� ����

	// �̸� ���̸� 4���� ���������Ƿ� vecHuman�� ���̴� 2
	printf("vecHuman�� ���� : %d\n\n", vecHuman.size());
	
	// vecHuman�� ��� 2�� ����
	// �� ���� ������ �ƴ϶� ������!
	// �ֳ�? �̸� �ڸ��� �����߱� ����!
	vecHuman[0] = new society::Police;
	vecHuman[1] = new society::Chief;

	for (int i = 0; i < vecHuman.size(); ++i)
	{
		// vecHuman[i]���� society::Human*�� ����
		// ������ �迭�� �̿��Ѵٰ� �����ϸ� ��
		vecHuman[i]->ShowInfo();
	}
	printf("-------------------------------------------\n");

	// ���ο� ��Ҹ� �ְԵǸ� �޸� ���Ҵ� �߻�!
	// ������ ���� ���̴� �۾��� �ƴϹǷ� �ν��ϱ�� �����!
	vecHuman.push_back(new society::Detective);
	printf("vecHuman�� ���� : %d\n\n", vecHuman.size());

	for (int i = 0; i < vecHuman.size(); ++i)
	{
		// vecHuman[i]���� society::Human*�� ����
		// ������ �迭�� �̿��Ѵٰ� �����ϸ� ��
		vecHuman[i]->ShowInfo();
	}
	printf("-------------------------------------------\n");

	// �����̳ʴ� �˾Ƽ� �޸𸮸� ����������
	// ����ڰ� ���� �Ҵ����� �޸𸮴� �������� ����!
	// ���� ���� �Ҵ����� �޸𸮴� �˾Ƽ� �����ؾ� ��!
	for (int i = 0; i < vecHuman.size(); ++i)
	{
		delete vecHuman[i];
	}

	// �츮 ������ ������ �ʴ� ���� �۾�
	vecHuman.clear();
	return 0;
}