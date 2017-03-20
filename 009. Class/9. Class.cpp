// 9. Class.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

#pragma pack(push, 1)
class CAR
{
private:
	char Model[13];
	int  Price;
	int  Wheel;
public:
	void InputInfo(const char *szModel, int iPrice, int iWheel)
	{
		strcpy(Model, szModel);
		Price = iPrice;
		Wheel = iWheel;
	}

	void PrintInfo(void)
	{
		printf("차종 : %10s\n", Model);
		printf("가격 : %8d원\n", Price);
		printf("바퀴 : %8d개\n", Wheel);
	}
};
#pragma pack(pop)

typedef CAR *PCAR;

int main(void)
{
	int iLength = 10;
	PCAR CarList = new CAR[iLength];
	memset(CarList, 0, sizeof(CAR) * iLength);

	PCAR(&rCarList) = CarList;
	printf("CAR 배열의 크기 : %d바이트\n", sizeof(CAR) * iLength);
	printf("---------------------------\n");

	rCarList[6].InputInfo("아우디", 63000000, 4);
	rCarList[6].PrintInfo();
	printf("---------------------------\n");
	SAFEDELETEARRAY(rCarList);
	return 0;
}