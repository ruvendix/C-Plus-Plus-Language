// 022. OperatorOverloading.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr

class CMyString
{
	friend CMyString operator +(const char *szData, const CMyString &rString);
	friend ostream &operator <<(ostream &rCout, const CMyString &rString);
	friend istream &operator >>(istream &rCin, const CMyString &rString);
private:
	char *Data;
	mutable char Buffer[128];
public:
	CMyString(void) : Data(new char[1]) {strcpy(Data, ""); printf("BC\n");}
	CMyString(const char *szData) : Data(new char[strlen(szData) + 1]) {strcpy(Data, szData); printf("CC1\n");}
	CMyString(const CMyString &rString) : Data(new char[strlen(rString.Data) + 1]) {strcpy(Data, rString.Data); printf("CC2\n");}
	CMyString(CMyString &&rrString) : Data(Data = rrString.Data) {rrString.Data = nullptr; printf("MC\n");}
	~CMyString(void) {SAFEDELETEARRAY(Data); printf("D\n");}

	const CMyString &operator +=(const CMyString &rString)
	{
		CMyString Temp(Data);
		Data = new char[strlen(Data) + strlen(rString.Data) + 1];
		strcpy(Data, Temp.Data);
		strcat(Data, rString.Data);
		return *this;
	}

	const CMyString operator +(const CMyString &rString)
	{
		CMyString Temp = *this;
		Temp += rString;
		return Temp;
	}

	const CMyString &operator =(const CMyString &rString)
	{
		delete Data;
		Data = new char[strlen(rString.Data) + 1];
		strcpy(Data, rString.Data);
		return *this;
	}

	bool operator ==(const CMyString &rString) const
	{
		return (strcmp(Data, rString.Data) == 0);
	}

	bool operator !=(const CMyString &rString) const
	{
		return !(*this == rString);
	}

	bool operator <(const CMyString &rString) const
	{
		return (strcmp(Data, rString.Data) < 0);
	}

	bool operator <=(const CMyString &rString) const
	{
		return ((*this < rString) || (*this == rString));
	}

	bool operator >(const CMyString &rString) const
	{
		return !(*this <= rString);
	}

	bool operator >=(const CMyString &rString) const
	{
		return !(*this < rString);
	}

	char operator[](int iIndex)
	{
		if (iIndex < 0 || iIndex >= strlen(Data))
		{
			return ' ';
		}
		return Data[iIndex];
	}

	char *GetBuffer(void) { return Data; }
};

CMyString operator +(const char *szData, const CMyString &rString)
{
	CMyString Temp(szData);
	Temp += rString;
	return Temp;
}

ostream &operator <<(ostream &rCout, const CMyString &rString)
{
	rCout << rString.Data;
	return rCout;
}

istream &operator >>(istream &rCin, CMyString &rString)
{
	char Buffer[128];
	cin.getline(Buffer, 128);
	rString = Buffer;
	return rCin;
}

int main(void)
{
	printf("-----------------------------------------------------------------------------------\n");
	printf("BC(기본 생성자) | CC1(변환 생성자) | CC2(복사 생성자) | MC(이동 생성자) | D(소멸자)\n");
	printf("-----------------------------------------------------------------------------------\n");
	
	CMyString String;
	String = "CMyString 실험!";
	String += " 문자열의 기초!";
	cout << String << endl;
	return 0;
}