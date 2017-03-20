// 032. Exception.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <exception> // set_terminate()
#include "stdafx.h"

enum EErrorCode
{
	ERRORDEFAULT,
	ERRORNEGATIVE,
	ERRORDIVISORZERO
};

// 예외 지정 => "이런이런 예외 객체가 발생할 거다"라고 알리는 것
void CheckDivisorZero(int iDivisor) throw (EErrorCode, int)
{
	if (iDivisor == 0)
	{
		throw ERRORDIVISORZERO;
	}
}

void KnownError(void)
{
	printf("무슨 오류인지는 모르겠지만 암튼 오류가 발생했습니다!\n");
}

int main(void)
{
	try
	{
		set_terminate(KnownError);
		CheckDivisorZero(0);
	}
	catch (int)
	{
		printf("여기로는 오지 않습니다\n");
	}
	return 0;
}