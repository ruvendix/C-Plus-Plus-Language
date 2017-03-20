// 6. NewDelete.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = NULL
#define SAFEDELETE(PTR) delete(PTR); PTR = NULL

#pragma pack(push, 1)
typedef struct CUSTOMERINFO
{
	char Name[10]; // 고객 이름
	int  Age;      // 고객 나이
	int  PhoneNum; // 고객 핸드폰 번호
}CUSTOMERINFO, *PCUSTOMERINFO, **PPCUSTOMERINFO;
#pragma pack(pop)

struct B
{
	int n;
	double j;
	B(int a, double b)
	{
		n = a;
		j = b;
	}
};

int main()
{
	// 5행
	PPCUSTOMERINFO ppCustomerList = new PCUSTOMERINFO[5];

	// 8열
	for (int i = 0; i < 5; ++i)
	{
		ppCustomerList[i] = new CUSTOMERINFO[8];
	}

	printf("할당된 크기 : %d바이트\n", _msize(ppCustomerList[0]) * 5);
	ppCustomerList[4][7].Age = 30;
	printf("ppCustomerList[4][7].Age : %d\n", ppCustomerList[4][7].Age);

	for (int i = 0; i < 5; ++i)
	{
		SAFEDELETE(ppCustomerList[i]);
	}
	SAFEDELETE(ppCustomerList);
	return 0;
}