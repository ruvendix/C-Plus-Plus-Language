// 017. DirectInitialization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CPosition
{
private:
	int X, Y;
public:
	CPosition(int iX, int iY)
	{
		X = iX;
		Y = iY;
	}

	int GetPosX(void)
	{
		return X;
	}

	int GetPosY(void)
	{
		return Y;
	}

	void PrintPos(void)
	{
		printf("좌표 : (%3d, %3d)\n", X, Y);
	}
};

class CRectangle
{
private:
	CPosition LeftTop = {0, 0};
	CPosition RightBottom = {0, 0};
public:
	CRectangle(void)
	{

	}

	CRectangle(int iLeft, int iTop, int iRight, int iBottom)
		: LeftTop(iLeft, iTop), RightBottom(iRight, iBottom)
	{

	}

	void PrintPos(void)
	{
		printf("왼쪽 위   : (%3d, %3d)\n", LeftTop.GetPosX(), LeftTop.GetPosY());
		printf("오른쪽 위 : (%3d, %3d)\n", RightBottom.GetPosX(), RightBottom.GetPosY());
	}
};

int main(void)
{
	CRectangle Rectangle1;
	Rectangle1.PrintPos();
	printf("-----------------------\n");

	CRectangle Rectangle2(100, 150, 250, 30);
	Rectangle2.PrintPos();
    return 0;
}