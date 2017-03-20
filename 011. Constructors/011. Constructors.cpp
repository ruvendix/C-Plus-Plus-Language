// 011. Constructors.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct POSITON
{
	int x, y;
};

class CRectangle
{
private:
	int Left, Top, Right, Bottom;
public:
	// 기본 생성자
	CRectangle(void)
	{
		printf("기본 생성자 호출!\n");
	}

	// 좌표 4개
	CRectangle(int iLeft, int iTop, int iRight, int iBottom)
	{
		Left   = iLeft;
		Top    = iTop;
		Right  = iRight;
		Bottom = iBottom;
	}

	// 좌표 구조체 2개
	CRectangle(POSITON LeftTop, POSITON RightBottom)
	{
		Left = LeftTop.x;
		Top = LeftTop.y;
		Right = RightBottom.x;
		Bottom = RightBottom.y;
	}

	void PrintPos(void)
	{
		printf("  왼쪽   위 좌표(%2d, %2d)\n", Left, Top);
		printf("오른쪽 아래 좌표(%2d, %2d)\n", Right, Bottom);
	}
};

int main(void)
{
	CRectangle Rectangle1(10, 5, 30, 8);
	printf("Rectangle1의 좌표\n");
	Rectangle1.PrintPos();
	printf("\n");

	CRectangle Rectangle2(POSITON{20, 4}, POSITON{40, 12});
	printf("Rectangle2의 좌표\n");
	Rectangle2.PrintPos();
    return 0;
}