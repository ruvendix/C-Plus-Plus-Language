/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::stack, std::queue, std::priority_queue�� �ڷḦ �־�� ����غ��ϴ�.
 *
 */

#include <iostream>
#include <queue> // queue�� priority_queue�� ����Ϸ��� �ʼ�!
#include <stack> // stack�� ����Ϸ��� �ʼ�!

int main()
{
	//// stack �����ϱ�
	//std::stack<int> stackNum;

	//// stack�� �ڷ� �ֱ�
	//stackNum.push(4);
	//stackNum.push(1);
	//stackNum.push(2);

	//// stack�� ũ�� �˾ƺ���
	//printf("���� stackNum�� ũ�� : %d\n\n", stackNum.size());

	//// �� ���� �ִ� �ڷ� ����ϱ�
	//printf("�� ���� �ִ� �� : %d\n\n", stackNum.top());

	//// stack ��ü ����ϱ�
	//// pop()�� empty()�� �̿�
	//while (stackNum.empty() == false)
	//{
	//	printf("%d ", stackNum.top());
	//	stackNum.pop();
	//}
	//printf("\n");


	//// queue �����ϱ�
	//std::queue<int> queueNum;

	//// queue�� �ڷ� �ֱ�
	//queueNum.push(4);
	//queueNum.push(1);
	//queueNum.push(2);

	//// queue�� ũ�� �˾ƺ���
	//printf("���� queueNum�� ũ�� : %d\n\n", queueNum.size());

	//// �� �տ� �ִ� �ڷ� ����ϱ�
	//printf("�� �տ� �ִ� �� : %d\n\n", queueNum.front());

	//// �� �ڿ� �ִ� �ڷ� ����ϱ�
	//printf("�� �ڿ� �ִ� �� : %d\n\n", queueNum.back());

	//// queue ��ü ����ϱ�
	//// pop()�� empty()�� �̿�
	//while (queueNum.empty() == false)
	//{
	//	printf("%d ", queueNum.front());
	//	queueNum.pop();
	//}
	//printf("\n");


	// priority_queue �����ϱ�
	std::priority_queue<int> priorityQueueNum;

	// priority_queue�� �ڷ� �ֱ�
	priorityQueueNum.push(6);
	priorityQueueNum.push(9);
	priorityQueueNum.push(3);

	// priority_queue�� ũ�� �˾ƺ���
	printf("���� priorityQueueNum�� ũ�� : %d\n\n", priorityQueueNum.size());

	// �� ���� �ִ� �ڷ� ����ϱ�
	printf("�� ���� �ִ� �� : %d\n\n", priorityQueueNum.top());

	// priority_queue ��ü ����ϱ�
	// pop()�� empty()�� �̿�
	while (priorityQueueNum.empty() == false)
	{
		printf("%d ", priorityQueueNum.top());
		priorityQueueNum.pop();
	}
	printf("\n");

	return 0;
}
