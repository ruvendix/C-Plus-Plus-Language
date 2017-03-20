// 016. MoveConstructors.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

class CData
{
private:
	int *NumList;
	int Size;
public:
	explicit CData(int iSize)
	{
		Size = iSize;
		NumList = new int[Size];
		printf("변환 생성자 호출\n");
	}

	CData(const CData& rData)
	{
		NumList = new int[rData.Size];
		printf("복사 생성자 호출\n");
	}

	// 이동 생성자 => 매개변수가 임시 객체
	CData(CData&& rData)
	{
		NumList = rData.NumList;
		rData.NumList = nullptr;
		printf("이동 생성자 호출\n");
	}

	~CData(void)
	{
		SAFEDELETEARRAY(NumList);
		printf("소멸자 호출\n");
	}

	//int V()
	//{
	//	return NumList[4] = 200;
	//}

	//CData &operator=(const CData &B)
	//{
	//	printf("예삐\n");
	//	NumList = new int[B.Size];
	//	Size = B.Size;
	//	return *this;
	//}
};

CData CreateData(int iSize)
{
	CData NewData(iSize);
	if (iSize > 10)
	{
		return NewData;
	}
	return NewData;
}

int main(void)
{
	CData Data1(100);
	CData Data2 = (CData &&)Data1;
	return 0;
}