/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::pair에 자료를 넣어보고 출력해봅니다.
 *
 */

#include <iostream>
#include <utility> // pair를 사용하려면 필수!

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
	std::deque<society::Human*> deqHuman;

	deqHuman.resize(2); // 길이를 2개로 메모리 재할당

	// 미리 길이를 2개로 설정했으므로 vecHuman의 길이는 2
	printf("deqHuman의 길이 : %d\n\n", deqHuman.size());

	// deqHuman에 요소 2개 대입
	// 이 경우는 삽입이 아니라 대입임!
	// 왜냐? 미리 자리를 마련했기 때문!
	deqHuman[0] = new society::Police;
	deqHuman[1] = new society::Chief;

	for (int i = 0; i < deqHuman.size(); ++i)
	{
		// deqHuman[i]에는 society::Human*가 있음
		// 포인터 배열을 이용한다고 생각하면 됨
		deqHuman[i]->ShowInfo();
	}
	printf("-------------------------------------------\n");

	// 새로운 요소를 넣게되면 메모리 재할당 발생!
	// 하지만 눈에 보이는 작업이 아니므로 인식하기는 어려움!
	deqHuman.push_front(new society::Detective);
	printf("deqHuman의 길이 : %d\n\n", deqHuman.size());

	for (int i = 0; i < deqHuman.size(); ++i)
	{
		// deqHuman[i]에는 society::Human*가 있음
		// 포인터 배열을 이용한다고 생각하면 됨
		deqHuman[i]->ShowInfo();
	}
	printf("-------------------------------------------\n");

	// 컨테이너는 알아서 메모리를 해제하지만
	// 사용자가 직접 할당해준 메모리는 해제하지 못함!
	// 따라서 직접 할당해준 메모리는 알아서 해제해야 함!
	for (int i = 0; i < deqHuman.size(); ++i)
	{
		delete deqHuman[i];
	}

	// 우리 눈에는 보이지 않는 해제 작업
	deqHuman.clear();
	return 0;
}
