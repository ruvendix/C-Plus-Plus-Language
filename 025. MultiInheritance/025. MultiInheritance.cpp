// 023. Inheritance.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CCharacter
{
protected:
	int Level;
public:
	CCharacter(void) : Level(1) {}
	explicit CCharacter(int iLevel) : Level(iLevel) {}
	void PrintLevel(void) const {printf("Level : %d\n", Level);}
};

class CKnight : virtual public CCharacter
{
protected:
	int RagePoint;
public:
	CKnight(void) : RagePoint(10), CCharacter(8) {}
	explicit CKnight(int iRagePoint) :
		RagePoint(iRagePoint), CCharacter(8) {}
	void Action(void) const {printf("검을 휘둘렀다!\n");}
	void PrintInfo(void) const {printf("RagePoint : %d\n", RagePoint);}
};

class CMagician : virtual public CCharacter
{
protected:
	int ManaPoint;
public:
	CMagician(void) : ManaPoint(30), CCharacter(12) {}
	explicit CMagician(int iManaPoint) :
		ManaPoint(iManaPoint), CCharacter(12) {}
	void Action(void) const {printf("마법을 시전했다!\n");}
	void PrintInfo(void) const {printf("ManaPoint : %d\n", ManaPoint);}
};

class CKnightMagician : public CKnight, public CMagician
{
private:
	int MadPoint;
public:
	CKnightMagician(void) : MadPoint(5), CCharacter(16), CKnight(20), CMagician(80) {}
	void PrintMadPoint(void) const {printf("MadPoint : %d\n", MadPoint);}
	void PrintMadPoint2(void) const {printf("MadPoint : %d\n", MadPoint);}
};

int main(void)
{
	printf("CCharacter의 크기      : %d\n", sizeof(CCharacter));
	printf("CKnight의 크기         : %d\n", sizeof(CKnight));
	printf("CMagician의 크기       : %d\n", sizeof(CMagician));
	printf("CKnightMagician의 크기 : %d\n", sizeof(CKnightMagician));
	return 0;
}