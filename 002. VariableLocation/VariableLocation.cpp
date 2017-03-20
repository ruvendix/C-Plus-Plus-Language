// VariableLocation.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define Pause() system("pause")
#define Clear() system("cls")

int main()
{
	int iStart, iEnd, iSum;

	while (1)
	{
		iSum = 0;
		printf("숫자의 시작 범위와 끝 범위를 입력하세요 : ");
		scanf("%d %d", &iStart, &iEnd);

		for (int i = iStart; i <= iEnd; ++i)
		{
			iSum += i;
		}
		printf("%d부터 %d까지의 합은 %d입니다.\n", iStart, iEnd, iSum);
		Pause();
		Clear();
	}
    return 0;
}