// 029. VirtualUse.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define PURE = 0
#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr
#define RANDOMIZE() (srand(time(nullptr)))
#define RANDOM(NUM) (rand() % (NUM))
#define BORDER() printf("--------------------------------------------\n")

class CGameStage
{
public:
	CGameStage(void) {}
	virtual ~CGameStage(void) {}
	virtual void StageRule(void) const PURE;
	virtual void StageEnemyAI(void) const PURE;
	virtual void StageSpeed(void) const PURE;
};

class CFastStage : public CGameStage
{
	int Obstacle;
public:
	CFastStage(void) : Obstacle(5) {}
	virtual ~CFastStage(void) {}
	virtual void StageRule(void) const
	{ 
		printf("모든 장애물을 파괴하세요!\n");
		printf("장애물은 총 %d개입니다\n", Obstacle);
	}
	virtual void StageEnemyAI(void) const
	{ 
		printf("적들 수준 : 멍청함\n");
	}
	virtual void StageSpeed(void) const
	{
		printf("게임 속도 : 4배\n");
	}
};

class CHardStage : public CGameStage
{
	int Stone;
public:
	CHardStage(void) : Stone(10) {}
	virtual ~CHardStage(void) {}
	virtual void StageRule(void) const
	{
		printf("모든 적을 제거하세요!\n");
		printf("적들이 가끔 돌을 던지니까 조심하세요.\n");
		printf("적들이 던질 수 있는 돌의 총 개수는 %d입니다.\n", Stone);
	}
	virtual void StageEnemyAI(void) const
	{
		printf("적들 수준 : 천재\n");
	}
	virtual void StageSpeed(void) const
	{
		printf("게임 속도 : 1배\n");
	}
};

class CBonusStage : public CGameStage
{
	int BonusLife;
public:
	CBonusStage(void) : BonusLife(2) {}
	virtual ~CBonusStage(void) {}
	virtual void StageRule(void) const
	{
		printf("보너스 스테이지입니다!\n");
		printf("생명을 추가로 %d개 줄게요!\n", BonusLife);
	}
	virtual void StageEnemyAI(void) const
	{
		printf("적들이 없습니다.\n");
	}
	virtual void StageSpeed(void) const
	{
		printf("게임 속도 : 1배\n");
	}
};

void PlayStage(const CGameStage *pStage)
{
	pStage->StageRule();
	pStage->StageEnemyAI();
	pStage->StageSpeed();
	BORDER();
}

CGameStage *SelectStage(CGameStage *&pStage)
{
	switch (RANDOM(3))
	{
	case 0:
		pStage = new CFastStage;
		break;
	case 1:
		pStage = new CHardStage;
		break;
	case 2:
		pStage = new CBonusStage;
		break;
	}
	return pStage;
}

char CheckFinish(void)
{
	char cBreak;
	printf("스테이지가 종료되었습니다.\n");
	printf("계속 하실 건가요?(Y / N) ");
	cBreak = getch();
	if (tolower(cBreak) != 'n' && tolower(cBreak) != 'y')
	{
		cBreak = 'y';
	}
	return cBreak;
}

void GameStart(void)
{
	CGameStage *pStage;
	char cBreak = ' ';

	RANDOMIZE();
	while (tolower(cBreak) != 'n')
	{
		pStage = SelectStage(pStage);
		PlayStage(pStage);
		cBreak = CheckFinish();
		system("cls");
	}
	delete pStage;
}

int main(void)
{
	GameStart();
	return 0;
}