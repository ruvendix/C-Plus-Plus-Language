/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::map에 자료를 넣어보고 출력해봅니다.
 *
 */

#include <iostream>
#include <map> // map을 사용하려면 필수!
#include <string>

struct CustomerInfo
{
	std::string strName;
	std::string strAddress;
};

class Customer
{
public:
	Customer(const std::string strName, const std::string strAddress)
	{
		m_info.strName = strName;
		m_info.strAddress = strAddress;
	}

	void ShowInfo() const
	{
		printf("고객의 이름 : %s\n", m_info.strName.c_str());
		printf("고객의 주소 : %s\n\n", m_info.strAddress.c_str());
	}

private:
	CustomerInfo m_info;
};

int main()
{
	//// map 생성하기 => map은 pair 형식을 사용
	//std::map<int, std::string> mapNum;

	//// map에 insert()로 자료 대입하는 방법
	//mapNum.insert({ 3, "셋" }); // { } 이용하기
	//mapNum.insert(std::make_pair(1, "하나")); // make_pair() 이용하기
	//mapNum[2] = "둘"; // [ ] 이용하기

	//// map 출력하기
	//for (std::map<int, std::string>::iterator i = mapNum.begin();
	//	i != mapNum.end(); ++i)
	//{
	//	printf("키 : %d ", i->first);
	//	printf("값 : %s\n", i->second.c_str());
	//}

	//// map에서 정보 검색하기
	//std::map<int, std::string>::iterator result;
	//result = mapNum.find(2);

	//if (result != mapNum.end())
	//{
	//	printf("2가 있습니다.\n");
	//}
	//else
	//{
	//	printf("2가 없습니다.\n");
	//}

	std::map<int, Customer*> mapCustomer;

	// 고객 정보 넣기
	mapCustomer[1] = new Customer("한민호", "서울시 관악구");
	mapCustomer[2] = new Customer("이가희", "대구시 동대구");
	mapCustomer[3] = new Customer("한민호", "인천시 동구");
	
	// 고객 정보 출력
	for (std::map<int, Customer*>::iterator i = mapCustomer.begin();
		i != mapCustomer.end(); ++i)
	{
		i->second->ShowInfo();
	}

	// 고개 정보 검색
	std::map<int, Customer*>::iterator result;
	result = mapCustomer.find(3);

	if (result->second != nullptr)
	{
		printf("3번 고객의 정보\n");
		result->second->ShowInfo();
	}
	else
	{
		printf("3번 고객이 없습니다.\n");
	}

	// 고객 정보 삭제
	for (std::map<int, Customer*>::iterator i = mapCustomer.begin();
		i != mapCustomer.end(); ++i)
	{
		if (i->second != nullptr)
		{
			delete i->second;
		}
	}
	return 0;
}
