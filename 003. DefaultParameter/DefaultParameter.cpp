// DefaultParameter.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

enum DYNAMIC_ALLOCATION {DA_NONE, DA_ACTIVATE};

void *SwitchDynamicAllocation(enum DYNAMIC_ALLOCATION eSelect = DA_NONE, int iDataSize = 0);

int main(void)
{
	char Location[100];
	void *pResult;

	pResult = SwitchDynamicAllocation();

	pResult = SwitchDynamicAllocation(DA_ACTIVATE, 4);
	if (pResult != NULL)
	{
		free(pResult);
	}
	return 0;
}

void *SwitchDynamicAllocation(enum DYNAMIC_ALLOCATION eSelect /*= DA_NONE*/, int iDataSize /*= 0*/)
{
	int iCount;

	if (eSelect == DA_NONE)
	{
		printf("동적 할당을 선택하지 않았습니다.\n");
		printf("-------------------------------------------------------\n");
		return NULL;
	}

	printf("할당할 개수를 입력하세요(현재 할당 크기 단위 : %d) : ", iDataSize);
	scanf("%d", &iCount);

	void *pResult = malloc(iDataSize * iCount);
	printf("%d개를 할당했습니다. 할당된 크기 %d바이트\n", iCount, _msize(pResult));
	printf("-------------------------------------------------------\n");
	return pResult;
}