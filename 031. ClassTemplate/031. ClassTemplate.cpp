// 031. ClassTemplate.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MyData.hpp"

int main(void)
{
	CMyData<int> Data(100);
	printf("Data : %d\n", Data.GetData());
	return 0;
}