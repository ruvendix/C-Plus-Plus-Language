// 036. Namespace.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//#include "stdafx.h"

#include <iostream>  // 표준 입출력 클래스
using namespace std; // 표준 이름 공간 using 지시

class MyClass
{
protected:
	int A;
public:
	int GetChild2(void) { return A; }
};
class CParent : public MyClass
{
protected:
	int Child;
public:
	CParent(void) : Child(1) {}
	virtual ~CParent(void) {}
	virtual void PrintInfo(void) { cout << "나는 부모다!" << endl; }
	int GetChild(void) { return Child; }
};

class CChild : public CParent
{
private:
	int PocketMoney;
public:
	using CParent::Child; // using으로 부모 클래스에게 접근
	using MyClass::A; // using으로 부모 클래스에게 접근
	CChild(void) : PocketMoney(10000) {}
	virtual ~CChild(void) {}
	virtual void PrintInfo(void) { cout << "나는 자식이다!" << endl; }
	int GetPocketMoney(void) { return PocketMoney; }
};

int main(void)
{
	CParent Parent;
	CChild Child;
	
	// protected라서 접근 불가능!
	//Parent.Child; 

	// protected지만 using 선언이 public에 있으므로 접근 가능!
	// 자식 클래스가 자신이 상속받은 정보를 public으로 허용한다고 했기 때문에
	// 정보 은폐는 깨지지만 자유롭게 이용 가능!
	Child.Child = 3;
	printf("자식 수 : %d\n", Child.GetChild());

	Child.A = 32;
	printf("자식 수 : %d\n", Child.GetChild2());
    return 0;
}