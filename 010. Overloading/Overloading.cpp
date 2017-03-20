// 010. Overloading.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

// 구조체는 자료만 모아놓을 때 사용
struct SCORE
{
	int Kor;
	int Eng;
	int Math;
};

// 클래스는 C를 앞에 붙이는 게 관례
class CStudent
{
private:
	char Name[10];
	SCORE Score;
public:
	void InputInfo(const char *szName, int iKor, int iEng, int iMath)
	{
		strcpy(Name, szName);
		Score.Kor = iKor;
		Score.Eng = iEng;
		Score.Math = iMath;
	}

	void PrintInfo(void)
	{
		printf("이름        : %s\n", Name);
		printf("언어 성적   : %4d점\n", Score.Kor);
		printf("외국어 성적 : %4d점\n", Score.Eng);
		printf("수리 성적   : %4d점\n", Score.Math);
	}

	// 성적을 분리해서 더하는 경우(정수)
	void AddExtraPoint(int iKor, int iEng, int iMath)
	{
		Score.Kor  += iKor;
		Score.Eng  += iEng;
		Score.Math += iMath;
	}

	// 성적을 분리해서 더하는 경우(실수)
	void AddExtraPoint(double dKor, double dEng, double dMath)
	{
		Score.Kor  += (int)dKor;
		Score.Eng  += (int)dEng;
		Score.Math += (int)dMath;
	}

	// 성적을 뭉태기로 더하는 경우
	void AddExtraPoint(SCORE ExtraPoint)
	{
		Score.Kor  += ExtraPoint.Kor;
		Score.Eng  += ExtraPoint.Eng;
		Score.Math += ExtraPoint.Math;
	}
};

typedef CStudent *PCStudent;

int main(void)
{
	PCStudent pStudentList = new CStudent[4];

	pStudentList[0].InputInfo("김이수", 80, 76, 64);
	pStudentList[1].InputInfo("서나연", 92, 89, 99);
	pStudentList[2].InputInfo("이호민", 88, 74, 70);
	pStudentList[3].InputInfo("정아연", 79, 99, 85);

	for (int i = 0; i < 4; ++i)
	{
		printf("--------------------\n");
		pStudentList[i].PrintInfo();
	}
	printf("--------------------\n");

	SAFEDELETEARRAY(pStudentList);
    return 0;
}