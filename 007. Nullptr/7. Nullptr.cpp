// 7. Nullptr.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr

#pragma pack(push, 1)
typedef struct PLAYERINFO
{
	char Name[10];  // 캐릭터 이름
	int  Level;     // 캐릭터 레벨
	int  HP, HPMAX; // 캐릭터 체력
	int  MP, MPMAX; // 캐릭터 마력
}PLAYERINFO, *PPLAYERINFO;
#pragma pack(pop)

int main(void)
{
	PPLAYERINFO Player = new PLAYERINFO{"용사", 16, 200, 200, 100, 100};

	printf("플레이어가 생존 중입니다.\n");
	printf("------------------------------------------------------\n");
	printf("캐릭터 이름 : %10s \t 캐릭터 레벨 : %2d\n",
		Player->Name, Player->Level);
	printf("캐릭터 체력 : %6d/%d \t 캐릭터 마력 : %3d/%d\n",
		Player->HP, Player->HPMAX, Player->MP, Player->MPMAX);
	printf("------------------------------------------------------\n");

	int iSelect;
	printf("어떤 스위치를 누를까요? (1. 오른쪽 | 2. 왼쪽): ");
	scanf("%d", &iSelect);

	if (iSelect == 2)
	{
		SAFEDELETE(Player);
	}

	if (Player == nullptr)
	{
		printf("장치가 폭발해서 플레이어가 죽었습니다...\n");
	}
	else
	{
		printf("장치를 무사히 해제했습니다! ^^\n");
	}
	return 0;
}