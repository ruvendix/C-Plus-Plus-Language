// 018. Friend.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

struct CBaseAbility
{
	int HP, HPMAX;
	int MP, MPMAX;
	int Strength, Dexterity;
};

class CPlayer; // 함수의 원형 전방 선언과 같음
class CManager
{
	friend CPlayer;
private:
	int NowMapCode;
public:
	explicit CManager(int iNowMapCode) : NowMapCode(iNowMapCode) {}
	void PrintPlayerAbility(CPlayer &rPlayer);
};

class CPlayer
{
	friend CManager;
private:
	CBaseAbility BaseAbility;
public:
	CPlayer(int iHP, int iMP, int iStr, int iDex)
	{
		BaseAbility.HP = BaseAbility.HPMAX = iHP;
		BaseAbility.MP = BaseAbility.MPMAX = iMP;
		BaseAbility.Strength = iStr;
		BaseAbility.Dexterity = iDex;
	}

	void PrintNowMapCode(CManager &Manager)
	{
		printf("현재 맵 코드 : %05d\n", Manager.NowMapCode);
	}
};

void CManager::PrintPlayerAbility(CPlayer &rPlayer)
{
	printf("------------\n");
	printf("객체의 정보\n");
	printf("------------\n");
	printf("체력 : %d/%d\n", rPlayer.BaseAbility.HP, rPlayer.BaseAbility.HPMAX);
	printf("마력 : %d/%d\n", rPlayer.BaseAbility.MP, rPlayer.BaseAbility.MPMAX);
	printf("힘   : %d\n", rPlayer.BaseAbility.Strength);
	printf("민첩 : %d\n", rPlayer.BaseAbility.Dexterity);
}

int main(void)
{
	CPlayer Player(100, 50, 6, 4);
	CManager Manager(5);
	Player.PrintNowMapCode(Manager);
	Manager.PrintPlayerAbility(Player);
	return 0;
}