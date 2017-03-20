// 037. PreMain.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CGameManager
{
private:
	char *Resoultion;
	bool bFileIntegrity;
	bool bSystemSpecifications;
	bool bResult;
public:
	CGameManager(void)
	{ 
		printf("생성자 호출!\n");
		Resoultion = "1920 * 1080";
		bFileIntegrity = true;
		bSystemSpecifications = false;
		if (bFileIntegrity == true && bSystemSpecifications == true)
		{
			bResult = true;
		}
		else
		{
			bResult = false;
		}
	}
	virtual ~CGameManager(void) { printf("소멸자 호출!\n"); }
public:
	bool GetResult(void) { return bResult; }
	void ShowGameManagerInfo(void)
	{
		cout << "해상도 : " << Resoultion << endl;
		if (bFileIntegrity == true) { cout << "파일 검사 성공!" << endl; }
		else { cout << "파일 검사 실패!" << endl; }
		if (bSystemSpecifications == true) { cout << "사양이 충분합니다!" << endl; }
		else { cout << "사양이 부족합니다!" << endl; }
	}
};
CGameManager g_GameManager;
bool g_bInitResult = g_GameManager.GetResult(); // 함수로 초기화 가능!

int main(void)
{
	printf("main() 이전에 초기화 가능!\n\n");
	g_GameManager.ShowGameManagerInfo();
	printf("초기화 결과 : %d\n\n", g_bInitResult);
    return 0;
}