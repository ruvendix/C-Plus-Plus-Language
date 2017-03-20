// 015. RvalueReference.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>
#include "stdafx.h"

class MyClass
{
private:
	double a[100];
	int b;
public:
	MyClass(void)
	{
		a[0] = 100;
		b = 20;
	}

	MyClass &operator+(MyClass &c)
	{
		c.a[0] += a[0];
		return c;
	}

	MyClass& operator=(const MyClass &c)
	{
		return *this;
	}

	MyClass(MyClass &&C)
	{
		printf("\n이동 생성자 등장\n");
	}

	void Print(void)
	{
		printf("%f\n", a[0]);
	}
};

class TEST2
{
public:
	int nValue;

	TEST2()
	{
		std::cout << "TEST2 생성자" << std::endl;
	}

	~TEST2()
	{
		std::cout << "TEST2 소멸자" << std::endl;
	}
	
	TEST2(const TEST2& obj)
	{
		nValue = obj.nValue;
		std::cout << "TEST2 복사 생성자" << std::endl;
	}

	TEST2(TEST2&& obj)
	{
		nValue = obj.nValue;
		std::cout << "TEST2 move 생성자" << std::endl;
	}
};

TEST2 GetTest2_1()
{
	TEST2 test2;
	test2.nValue = 11;
	return test2;
}

TEST2 GetTest2_2(TEST2 a)
{
	TEST2 test2;
	test2.nValue = 11;

	//if (nTemp > 100)
	//{
	//	test2.nValue = 111;
	//	return test2;
	//}
	return a;
}

class YY
{
public:
	double o[100];
	int n[100];

	YY(void)
	{
		printf("생성자 호출\n");
	}

	YY(const YY &B)
	{
		printf("복사 생성자 호출\n");
	}

	YY(YY &&b)
	{
		printf("이동 생성자 호출\n");
	}
};

YY &&NN(void)
{
	YY o;
	memset(&o, 0, sizeof(YY));
	return (YY &&)o;
}

int &PreFixPlus(int &iOperand)
{
	return iOperand += 1;
}

int PostFixPlus(int &iOperand)
{
	int iTemp = iOperand;
	iOperand += 1;
	return iTemp;
}

int main(void)
{
	//MyClass iNum1, iNum2, iNum3;
	//MyClass iNum4 = iNum1 + iNum2 + iNum3;
	////MyClass BB(iNum1);
	//iNum4.Print();

	//std::cout << "TEST2 - NRVO 사용" << std::endl;
	
	//	auto test2_1 = GetTest2_1();
	//
	//std::cout << std::endl;

	////std::cout << "TEST2 - move 생성자 사용" << std::endl;
	//{
	//	GetTest2_2(test2_1);
	//	//test2_2.nValue = 10;
	//}

	//YY E, E1, E2, E3;
	//E.n[0] = E1.n[0] = E2.n[0] = E3.n[0] = 10;

	//E.n[0] = E1.n[0] + E2.n[0] + E3.n[0];

	int iNum = 10;
	printf("iNum : %d\n\n", iNum);

	// PreFixPlus()의 반환값은 l-value
	int &rNum = PreFixPlus(iNum);
	printf("선 증가 연산 결과\n");
	printf("iNum : %d | rNum  : %d\n\n", iNum, rNum);


	// PostFixPlus()의 반환값은 r-value
	
	
	
	//printf("후 증가 연산 결과\n");
	//printf("iNum : %d | rrNum : %d\n\n", iNum, rrNum);

	iNum = 10;
	int iResult1 = iNum++ + 10 + ++iNum;
	printf("iResult1 : %d\n", iResult1);

	iNum = 10;
	int iResult2 = PostFixPlus(iNum) + 10 + PreFixPlus(iNum);
	printf("iResult2 : %d\n", iResult2);


	NN();
	return 0;
}