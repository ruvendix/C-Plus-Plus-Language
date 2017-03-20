// 038. IOstream.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

// 표준 입출력 스트림을 위한 코드
#include <iostream>
#include <fstream> // 파일 입출력에 필요한 헤더 파일
using namespace std;

int main(void)
{
	ofstream WriteFile;
	WriteFile.open("Today.txt", ios_base::out); // 플래그를 이용
	WriteFile << "오늘 날짜 : " << endl << 20170308 << endl; // endl로 구분
	WriteFile.close();

	int iDate;
	char Buffer[128];
	ifstream ReadFile("Today.txt"); // 생성자를 이용, 플래그는 기본 플래그
	
	try
	{
		if (ReadFile.is_open() == true) // 파일 스트림이 열렸는지 확인
		{
			cout << "파일 읽기 성공!" << endl;
			ReadFile.getline(Buffer, sizeof(char) * 128); // 공백도 읽기 위해
			ReadFile >> iDate;
			cout << Buffer << iDate << endl;
			ReadFile.close();
		}
		else
		{
			throw false;
		}
	}
	catch (bool)
	{
		cout << "파일 읽기 실패!" << endl;
	}
	return 0;
}