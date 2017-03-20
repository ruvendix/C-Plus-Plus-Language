// 027. Binding.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CParent
{
public:
	void Talk(void) { printf("내가 부모다!\n"); }
};

class CChild : public CParent
{
private:
	int PocketMoney; // 용돈
public:
	CChild(void) : PocketMoney(10000) {}
	void Talk(void) { printf("내가 자식이다!\n"); }
	void Talk(int iNum) { printf("내가 %d번째 자식이다!\n", iNum); }
	void ShowPocketMoney(void) { printf("용돈 : %d원\n", PocketMoney); }
};

void WhoIsTalkingNow(CParent *pRoot, int iSelect)
{
	(iSelect == 1) ? (pRoot->Talk()) : (((CChild *)pRoot)->Talk());
	printf("\n");
}

int main(void)
{
	CParent Parent;
	CChild Child;
	WhoIsTalkingNow(&Parent, 1);
	WhoIsTalkingNow(&Child, 2);
	return 0;
}