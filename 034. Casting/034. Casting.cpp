// 034. Casting.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CParent
{
public:
	CParent(void) { printf("부모 생성자 호출!\n"); }
	virtual ~CParent(void) { printf("부모 소멸자 호출!\n"); }
	virtual void PrintInfo(void) { printf("나는 부모다!\n"); }
};

class CChild : public CParent
{
private:
	int PocketMoney;
public:
	CChild(void) : PocketMoney(10000) { printf("자식 생성자 호출!\n"); }
	virtual ~CChild(void) { printf("자식 소멸자 호출!\n"); }
	virtual void PrintInfo(void) { printf("나는 자식이다!\n"); }
	void PrintPocketMoney(void) { printf("현재 용돈 : %d원\n", PocketMoney); }
};

void Action(CParent *pParent)
{
	pParent->PrintInfo();
	CChild *pTemp = dynamic_cast<CChild *>(pParent);
	if (pTemp == nullptr)
	{
		printf("부모는 용돈이 없습니다...\n");
	}
	else
	{
		pTemp->PrintPocketMoney();
	}
}

int main(void)
{
	int iNum = 10;
	double* pNum = reinterpret_cast<double *>(&iNum); // int 포인터 넘기기
	printf("iNum  : %d\n", iNum);
	printf("*pNum : %d\n\n", *(int *)pNum);

	// 원본은 값 변경 가능
	iNum = 200;
	printf("iNum  : %d\n", iNum);
	printf("*pNum : %d\n\n", *(int *)pNum);

	// 원본을 가리키는 포인터는 값 변경 불가능
	//*pNum = 20;
	//printf("iNum  : %d\n", iNum);
	//printf("*pNum : %d\n", *(int *)pNum);

	// 이렇게 숫자와도 변환 가능
	int *pAddress = reinterpret_cast<int *>(0x12345678);
	return 0;
}