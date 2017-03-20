// 035. MemberPointer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CParent
{
protected:
	int Child;
public:
	CParent(void) : Child(1) {}
	virtual ~CParent(void) {}
	virtual void PrintInfo(void) { printf("나는 부모다!\n"); }
	int GetChild(void) { return Child; } // 어차피 상속됨
};

class CChild : public CParent
{
private:
	int PocketMoney;
public:
	using CParent::Child;
	CChild(void) : PocketMoney(10000) {}
	virtual ~CChild(void) {}
	virtual void PrintInfo(void) { printf("나는 자식이다!\n"); }
	int GetPocketMoney(void) { return PocketMoney; } // 자식 클래스 전용 함수!
};

int main(void)
{
	CParent Parent;
	CChild Child;
	printf("%d\n", Child.Child); // 신기
	return 0;
}