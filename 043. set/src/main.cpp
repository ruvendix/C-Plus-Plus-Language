/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::set에 자료를 넣어보고 출력해봅니다.
 *
 */

#include <iostream>
#include <set> // set을 사용하려면 필수!
#include <vector>

int main()
{
	std::vector<int> vecNum = {1, 4, 8, 9, 6, 3};
	
	// set에 vector 대입
	std::set<int> setNum(vecNum.begin(), vecNum.end());

	// set에 추가로 대입
	setNum.insert(7);

	// set 출력하기
	for (std::set<int>::iterator i = setNum.begin();
		i != setNum.end(); ++i)
	{
		printf("%d ", *i);
	}
	printf("\n");

	// set에서 정보 검색하기
	std::set<int>::iterator result;
	result = setNum.find(8);

	if (result != setNum.end())
	{
		printf("8이 있습니다.\n");
	}
	else
	{
		printf("8이 없습니다.\n");
	}

	return 0;
}
