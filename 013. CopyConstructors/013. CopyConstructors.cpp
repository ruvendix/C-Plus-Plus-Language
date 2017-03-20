// 013. CopyConstructors.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

class CMonster
{
private:
	char *Name;
	int  Level;
	int  HP, HPMAX;
public:
	CMonster(void) {}

	CMonster(const char *szName, int iLevel, int iHPMAX)
	{
		// 종료 문자 포함
		Name = new char[strlen(szName) + 1];
		strcpy(Name, szName);
		Level = iLevel;
		HP = HPMAX = iHPMAX;
	}

	CMonster(const CMonster &rStudent)
	{
		// 종료 문자 포함
		Name = new char[strlen(rStudent.Name) + 1];
		strcpy(Name, rStudent.Name);
		Level = rStudent.Level;
		HP = HPMAX = rStudent.HPMAX;
	}

	~CMonster(void)
	{
		SAFEDELETEARRAY(Name);
	}

	void SetInfo(const char *szName, int iLevel, int iHPMAX)
	{
		// 종료 문자 포함
		Name = new char[strlen(szName) + 1];
		strcpy(Name, szName);
		Level = iLevel;
		HP = HPMAX = iHPMAX;
	}

	void PrintInfo(void)
	{
		printf("몬스터 이름 : %s\n", Name);
		printf("몬스터 레벨 : %d\n", Level);
		printf("몬스터 체력 : %d/%d\n", HP, HPMAX);
	}
};

typedef CMonster *PCMonster;

int main(void)
{
	// 동적 객체 배열 생성
	// 오버로딩된 생성자 호출
	PCMonster MonsterList =
		new CMonster[3]{CMonster("날개 기사", 12, 500)};

	// SetInfo() 호출
	MonsterList[1].SetInfo("로스릭 기사", 9, 420);

	// 복사 생성자 호출
	MonsterList[2] = MonsterList[0];

	for (int i = 0; i < 3; ++i)
	{
		MonsterList[i].PrintInfo();
		printf("-------------------------\n");
	}
    return 0;
}