// 028. Virtual.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CParent
{
public:
	CParent(void) { printf("부모 생성자\n"); }
	virtual ~CParent(void) { printf("부모 소멸자\n"); }
};

class CChild : public CParent
{
public:
	CChild(void) { printf("자식 생성자\n"); }
	virtual ~CChild(void) { printf("자식 소멸자\n"); }
};

void CheckDestructor(CParent *pRoot)
{
	delete pRoot;
}

int main(void)
{
	printf("CParent 생성과 소멸\n");
	CParent *pParent = new CParent;
	CheckDestructor(pParent);
	printf("\n");

	printf("CChild 생성과 소멸\n");
	pParent = new CChild;
	CheckDestructor(pParent);
	return 0;
}


























