// 012. Destructors.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

//class CStudent
//{
//private:
//	char *Name;
//	int  Grade;
//public:
//	CStudent(const char *szName, int iGrade)
//	{
//		Name = new char[strlen(szName) + 1]; // 종료 문자 포함
//		strcpy(Name, szName);
//		Grade = iGrade;
//	}
//
//	~CStudent(void)
//	{
//		SAFEDELETEARRAY(Name);
//	}
//
//	void PrintInfo(void)
//	{
//		printf("학생 이름 : %s\n", Name);
//		printf("학생 학년 : %d학년\n", Grade);
//	}
//};

//typedef CStudent *PCStudent;

int main(void)
{
	//// 객체 배열 초기화
	//PCStudent StudentList =
	//	new CStudent[3]{CStudent("정아연", 2),
	//	CStudent("이아름", 1), CStudent("박철민", 2)};

	//for (int i = 0; i < 3; ++i)
	//{
	//	StudentList[i].PrintInfo();
	//	printf("------------------\n");
	//}

	//SAFEDELETEARRAY(StudentList);
    return 0;
}