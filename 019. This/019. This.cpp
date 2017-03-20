// 019. This.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CData
{
private:
	int Num;
public:
	explicit CData(int iNum)
	{
		Num = iNum;
	}

	CData operator+(CData rData)
	{
		rData.Num += 10;
		return rData;
	}

	CData(const CData &rData)
	{
		printf("복사 생성자 호출\n");
	}

	CData(const CData &&rrData)
	{
		Num = rrData.Num;
		printf("이동 생성자 호출\n");
	}

	void PrintNum(void)
	{
		printf("Num : %d\n", Num);
	}
};

int main(void)
{
	CData Data(10);
	CData Data2(10);
	//Data.PlusTen(Data).PrintNum();
	(Data.operator+(Data2)).PrintNum();
	Data.PrintNum();
	Data2.PrintNum();
    return 0;
}