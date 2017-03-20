// 023. Inheritance.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr

class CHuman
{
protected:
	char *Name;
	int Age;
public:
	CHuman(void) : Name(new char[1]), Age(0) {}
	CHuman(const char *szName, int iAge) :
		Name(new char[strlen(szName) + 1]), Age(iAge) {strcpy(Name, szName);}
	~CHuman(void) {SAFEDELETEARRAY(Name);}
};

class CPolice : public CHuman
{
private:
	int Rank;
public:
	CPolice(const char *szName, int iAge, int iRank) :
		CHuman(szName, iAge), Rank(iRank) {}
	void PrintInfo(void) const
	{
		printf("이름 : %s\n", Name);
		printf("나이 : %d\n", Age);
		printf("계급 : %d\n", Rank);
	}
	void Action(void) const {printf("경찰서에서 근무한다.\n");}
};

class CStudent : public CHuman
{
private:
	int Grade;
public:
	CStudent(const char *szName, int iAge, int iGrade) :
		CHuman(szName, iAge), Grade(iGrade) {}
	void PrintInfo(void) const
	{
		printf("이름 : %s\n", Name);
		printf("나이 : %d\n", Age);
		printf("학년 : %d\n", Grade);
	}
	void Action(void) const {printf("학교에서 공부한다.\n");}
};

class CProgrammer : public CHuman
{
private:
	int AvailableLanguage;
public:
	CProgrammer(const char *szName, int iAge, int iAvailableLanguage) :
		CHuman(szName, iAge), AvailableLanguage(iAvailableLanguage) {}
	void PrintInfo(void) const
	{
		printf("이름 : %s\n", Name);
		printf("나이 : %d\n", Age);
		printf("언어 : %d\n", AvailableLanguage);
	}
	void Action(void) const {printf("프로그램을 만든다.\n");}
};

int main(void)
{
	CPolice Police("이호철", 32, 2);
	Police.PrintInfo();
	Police.Action();
	printf("\n");

	CStudent Student("서예진", 18, 2);
	Student.PrintInfo();
	Student.Action();
	printf("\n");

	CProgrammer Programmer("키리토", 29, 5);
	Programmer.PrintInfo();
	Programmer.Action();
	return 0;
}