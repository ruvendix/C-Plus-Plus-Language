// 5. Reference.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

typedef struct DATA
{
	double dNum;
	int NumList[20];
}DATA;

typedef void(*pFunc)(DATA &);

void CallByReference1(DATA &rData)
{
	rData.dNum = 20.36;
}

void CallByReference2(DATA &rData)
{
	rData.dNum = 40.36;
}

int main()
{
	DATA Data;
	pFunc pSelect = CallByReference1;
	pSelect(Data);
	pSelect = CallByReference2; // 함수 포인터는 변경 가능
	pSelect(Data);
	printf("Data.dNum : %.2f\n", Data.dNum);
	return 0;
}