/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::stack, std::queue, std::priority_queue에 자료를 넣어보고 출력해봅니다.
 *
 */

#include <iostream>
#include <queue> // queue와 priority_queue를 사용하려면 필수!
#include <stack> // stack을 사용하려면 필수!

int main()
{
	//// stack 생성하기
	//std::stack<int> stackNum;

	//// stack에 자료 넣기
	//stackNum.push(4);
	//stackNum.push(1);
	//stackNum.push(2);

	//// stack의 크기 알아보기
	//printf("현재 stackNum의 크기 : %d\n\n", stackNum.size());

	//// 맨 위에 있는 자료 출력하기
	//printf("맨 위에 있는 값 : %d\n\n", stackNum.top());

	//// stack 전체 출력하기
	//// pop()과 empty()를 이용
	//while (stackNum.empty() == false)
	//{
	//	printf("%d ", stackNum.top());
	//	stackNum.pop();
	//}
	//printf("\n");


	//// queue 생성하기
	//std::queue<int> queueNum;

	//// queue에 자료 넣기
	//queueNum.push(4);
	//queueNum.push(1);
	//queueNum.push(2);

	//// queue의 크기 알아보기
	//printf("현재 queueNum의 크기 : %d\n\n", queueNum.size());

	//// 맨 앞에 있는 자료 출력하기
	//printf("맨 앞에 있는 값 : %d\n\n", queueNum.front());

	//// 맨 뒤에 있는 자료 출력하기
	//printf("맨 뒤에 있는 값 : %d\n\n", queueNum.back());

	//// queue 전체 출력하기
	//// pop()과 empty()를 이용
	//while (queueNum.empty() == false)
	//{
	//	printf("%d ", queueNum.front());
	//	queueNum.pop();
	//}
	//printf("\n");


	// priority_queue 생성하기
	std::priority_queue<int> priorityQueueNum;

	// priority_queue에 자료 넣기
	priorityQueueNum.push(6);
	priorityQueueNum.push(9);
	priorityQueueNum.push(3);

	// priority_queue의 크기 알아보기
	printf("현재 priorityQueueNum의 크기 : %d\n\n", priorityQueueNum.size());

	// 맨 위에 있는 자료 출력하기
	printf("맨 위에 있는 값 : %d\n\n", priorityQueueNum.top());

	// priority_queue 전체 출력하기
	// pop()과 empty()를 이용
	while (priorityQueueNum.empty() == false)
	{
		printf("%d ", priorityQueueNum.top());
		priorityQueueNum.pop();
	}
	printf("\n");

	return 0;
}
