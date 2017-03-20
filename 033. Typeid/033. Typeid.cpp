// 033. Typeid.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <typeinfo>
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

	// 동적 바인딩 조사
	printf("클래스의 이름 : %s\n", typeid(*pParent).name());

	if (typeid(*pParent) == typeid(CParent))
	{
		printf("부모는 용돈이 없습니다...\n");
	}
	else
	{
		((CChild *)pParent)->PrintPocketMoney();
	}
}

int main(void)
{
	CParent Parent;
	printf("부모 클래스의 이름 : %s\n", typeid(Parent).name());
	printf("부모 클래스의 기호 : %s\n\n", typeid(Parent).raw_name());
	
	CChild Child;
	printf("자식 클래스의 이름 : %s\n", typeid(Child).name());
	printf("자식 클래스의 기호 : %s\n\n", typeid(Child).raw_name());

	try
	{
		Action(&Parent);
		printf("\n");
		Action(&Child);
		printf("\n");
	}
	catch (std::bad_typeid &rError)
	{
		printf("오류 내용 : %s\n\n", rError.what());
	}
    return 0;
}