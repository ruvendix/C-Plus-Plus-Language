// 8. Structure.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct PRODUCTINFO
{
	char Name[20];
	int  Price;
	void PrintInfo(void);
};
typedef PRODUCTINFO *PPRODUCTINFO;

// 소속을 밝히고 ::으로 접근하면 됨
void PRODUCTINFO::PrintInfo(void)
{
	printf("이름 : %12s\n", this->Name);
	printf("가격 : %11d원\n", this->Price);
}

int main(void)
{
	PRODUCTINFO Lego = { "밀레니엄 팔콘", 8000000 };
	Lego.PrintInfo();
	return 0;
}
