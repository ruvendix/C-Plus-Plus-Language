// 030. Template.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

template <typename T>
void PrintData(const T &rData)
{
	std::cout << rData << std::endl << std::endl;
}

class CObject
{
	friend void PrintData<CObject>(const CObject &rData);
private:
	int X, Y;
	int Code;
public:
	CObject(void) : X(0), Y(0), Code(0) {}
	CObject(int iX, int iY, int iCode) : X(iX), Y(iY), Code(iCode) {}
	virtual ~CObject(void) {}
};


template <> void PrintData<CObject>(const CObject &rData)
{
	std::cout << "좌표 : (" << rData.X << ", " << rData.Y << ")" << std::endl;
	std::cout << "번호 : " << rData.Code << std::endl << std::endl;
}

int main(void)
{
	CObject House(10, 20, 1);
	PrintData<CObject>(House);
	PrintData<char>('A');
	PrintData<int>(100);
	PrintData<double>(26.72);
	return 0;
}