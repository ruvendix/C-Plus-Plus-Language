/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::deque에 자료를 넣어보고 출력해봅니다.
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
			printf("내 직업은 경찰!\n");
		}
	};

	class Chief : public Human
	{
	public:
		virtual void ShowInfo()
		{
			printf("내 직업은 셰프!\n");
		}
	};

	class Detective : public Human
	{
	public:
		virtual void ShowInfo()
		{
			printf("내 이름은 코난! 탐정이죠!\n");
		}
	};
}

int main()
{
	std::list<society::Human*> listHuman(2); // 클래스 포인터 형식을 2개 저장

	// 미리 길이를 2개로 설정했으므로 listHuman의 길이는 2
	printf("listHuman에 자료 대입 전\n");
	printf("listHuman의 길이 : %d\n\n", listHuman.size());

	// listHuman에 요소 2개 대입
	// 이 경우는 삽입이 아니라 대입임!
	// 왜냐? 미리 자리를 마련했기 때문!
	// listHuman[0] 이건 불가능!
	// 아래처럼 쓰면 push_front()가 됨
	society::Police police;
	listHuman.insert(listHuman.begin(), &police);

	// 아래처럼 쓰면 push_back()이 됨
	society::Chief chief;
	listHuman.insert(listHuman.end(), &chief);

	// 미리 설정한 길이에 2개가 추가되었으므로 listHuman의 길이는 4
	printf("listHuman에 자료 대입 후\n");
	printf("listHuman의 길이 : %d\n\n", listHuman.size());

	// 우리 눈에는 보이지 않는 해제 작업
	listHuman.clear();
	return 0;
}
