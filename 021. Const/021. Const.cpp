// 021. Const.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CData
{
public:
	int IntNum;
	mutable int TempIntNum;
public:
	CData(int iNum) : IntNum(iNum), TempIntNum(0) {}

	void SetIntNum(int iNum)
	{
		IntNum = iNum;
	}

	void PrintIntNum(void) const
	{
		printf("IntNum     : %d\n", IntNum);
		printf("TempIntNum : %d\n", TempIntNum);
		TempIntNum = IntNum; // 변경 가능
	}
};

int main(void)
{
	// 일반 객체
	CData Data1(100);
	Data1.SetIntNum(200);
	Data1.PrintIntNum();
	Data1.PrintIntNum();
	printf("-------------------\n");

	// const 객체
	const CData Data2(100);
	Data2.PrintIntNum();
	Data2.PrintIntNum();
    return 0;
}