// 023. Inheritance.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CData
{
protected:
	int IntNum;
public:
	CData(void) : IntNum(10) {}
	void PrintData(void) const {printf("IntNum : %d\n", IntNum);}
};

class CNewData : public CData
{
private:
	int IntNum;
public:
	CNewData(void) : IntNum(20) {}
	void PrintData(void) const
	{
		printf("IntNum           : %d\n", IntNum);
		printf("CNewData::IntNum : %d\n", CNewData::IntNum);
		printf("CData::IntNum    : %d\n", CData::IntNum);
	}
};

int main(void)
{
	CNewData NewData;
	NewData.PrintData();
	return 0;
}