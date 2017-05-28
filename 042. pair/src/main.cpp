/*
 * main.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드 및 개인 코딩 가이드 라인을 따릅니다.
 * 이번에는 std::pair에 자료를 넣어보고 출력해봅니다.
 *
 */

#include <iostream>
#include <utility> // pair를 사용하려면 필수!

int main()
{
	// int와 double을 하나의 type으로 설정!
	std::pair<int, double> pairData;

	pairData.first  = 10;    // int를 의미
	pairData.second = 20.0f; // double을 의미

	printf("first  : %d\n", pairData.first);
	printf("second : %.2f\n\n", pairData.second);

	// pair 값을 만들어서 대입
	pairData = std::make_pair(20, 10.0f);

	printf("first  : %d\n", pairData.first);
	printf("second : %.2f\n", pairData.second);

	return 0;
}
