/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵� �� ���� �ڵ� ���̵� ������ �����ϴ�.
 * �̹����� std::map�� �ڷḦ �־�� ����غ��ϴ�.
 *
 */

#include <iostream>
#include <map> // map�� ����Ϸ��� �ʼ�!
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
		printf("���� �̸� : %s\n", m_info.strName.c_str());
		printf("���� �ּ� : %s\n\n", m_info.strAddress.c_str());
	}

private:
	CustomerInfo m_info;
};

int main()
{
	//// map �����ϱ� => map�� pair ������ ���
	//std::map<int, std::string> mapNum;

	//// map�� insert()�� �ڷ� �����ϴ� ���
	//mapNum.insert({ 3, "��" }); // { } �̿��ϱ�
	//mapNum.insert(std::make_pair(1, "�ϳ�")); // make_pair() �̿��ϱ�
	//mapNum[2] = "��"; // [ ] �̿��ϱ�

	//// map ����ϱ�
	//for (std::map<int, std::string>::iterator i = mapNum.begin();
	//	i != mapNum.end(); ++i)
	//{
	//	printf("Ű : %d ", i->first);
	//	printf("�� : %s\n", i->second.c_str());
	//}

	//// map���� ���� �˻��ϱ�
	//std::map<int, std::string>::iterator result;
	//result = mapNum.find(2);

	//if (result != mapNum.end())
	//{
	//	printf("2�� �ֽ��ϴ�.\n");
	//}
	//else
	//{
	//	printf("2�� �����ϴ�.\n");
	//}

	std::map<int, Customer*> mapCustomer;

	// �� ���� �ֱ�
	mapCustomer[1] = new Customer("�ѹ�ȣ", "����� ���Ǳ�");
	mapCustomer[2] = new Customer("�̰���", "�뱸�� ���뱸");
	mapCustomer[3] = new Customer("�ѹ�ȣ", "��õ�� ����");
	
	// �� ���� ���
	for (std::map<int, Customer*>::iterator i = mapCustomer.begin();
		i != mapCustomer.end(); ++i)
	{
		i->second->ShowInfo();
	}

	// �� ���� �˻�
	std::map<int, Customer*>::iterator result;
	result = mapCustomer.find(3);

	if (result->second != nullptr)
	{
		printf("3�� ���� ����\n");
		result->second->ShowInfo();
	}
	else
	{
		printf("3�� ���� �����ϴ�.\n");
	}

	// �� ���� ����
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
