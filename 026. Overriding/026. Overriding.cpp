// 026. Overriding.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CParent
{
public:
	void Talk(void) { printf("내가 부모다!\n"); }
};

class CChild : public CParent
{
public:
	// 오버라이딩
	void Talk(void) { printf("내가 자식이다!\n"); }

	// 오버로딩
	void Talk(int iNum) { printf("내가 %d번째 자식이다!\n", iNum); }
};

int main(void)
{
	CParent Parent;
	printf("CParent의 메서드 호출!\n");
	Parent.Talk();
	Parent.CParent::Talk();
	printf("\n");

	printf("CChild의 메서드 호출!\n");
	CChild Child;
	Child.Talk();
	Child.Talk(1);
	Child.CParent::Talk();
	Child.CChild::Talk();
	Child.CChild::Talk(1);
	return 0;
}