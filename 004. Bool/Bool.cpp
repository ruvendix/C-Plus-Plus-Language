// Bool.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"

int main(void)
{
	unsigned bool ubData = -10;
	signed   bool sbData = 30;
	int iNum = 36;
	double dNum = -0.5f;

	printf("ubData  : %+3d\n", ubData);
	printf("sbData  : %+3d\n", sbData);

	ubData += iNum;
	sbData += dNum;
	printf("ubData  : %+3d\n", ubData);
	printf("sbData  : %+3d\n", sbData);
	printf("~ubData : %+3d\n", ~ubData);
	printf("~sbData : %+3d\n", ~sbData);
	return 0;
}