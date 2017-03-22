/*
 * test_code.cpp
 *
 *       Copyright (c) Ruvendix. 모든 저작권은 본인에게 있습니다.
 *
 * 이 파일은 구글 코딩 가이드를 연습하기 위한 파일입니다.
 * C++11 이상의 내용들도 포함되어있습니다.
 *
 */

// 복사 생성자 및 복사 대입 연산자를
// 무효화시키는 매크로 함수
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) { }            \
  void operator=(const TypeName&) { }

#include "test_code.h" // 현재 작업 중인 헤더 파일
#include <assert.h>    // C 라이브러리
#include <inttypes.h>  // C 라이브러리
#include <math.h>      // C 라이브러리
#include <time.h>      // C 라이브러리 => 알파벳 순서 정리
#include <iostream>    // C++ 라이브러리
#include <list>        // C++ 라이브러리
#include <map>         // C++ 라이브러리
#include <memory>      // C++ 라이브러리
#include <vector>      // C++ 라이브러리 => 알파벳 순서 정리

// 조건부 컴파일은 해당 항목 맨 아래에 배치
#ifdef _DEBUG
#include <string>
#endif

#include "Screen.h"       // 외부 라이브러리
#include "ruvendix/Use.h" // 현재 프로젝트의 헤더 파일

// 전역 함수 대신 이름 없는
// namespace를 활용하라!
namespace
{
	void SafeDelete(void *dynamic_ptr)
	{
		delete dynamic_ptr;
		dynamic_ptr = nullptr; // C++11
		printf("힙 메모리 해제!\n");
	}
} // namespace 이름 없음

// 컴파일 타임 때 상수를 결정!
// C++14 이상
constexpr inline int ArrayLength()
{
	return 10;
}

void ExitOrDie()
{
	exit(EXIT_SUCCESS);
}

template <typename T>
class Complex {};

int main(void)
{
	// initializer_list를 이용한 초기화
	// =은 써도 되고 안 써도 됨!
	self_practice::Test test{ 100 };
	std::vector<int> vec_num{ 1, 2, 3 };

	// auto_test1은 initializer_list<double>
	auto auto_test1 = { 2.62 };

	// auto_test2는 double
	auto auto_test2 = double{ 2.62 };

	// 중첩 템플릿은 >> 연산자와의 혼돈을 피하기 위해
	// > > 이렇게 작성하는 게 좋다!
	std::map<int, Complex<int> > map_complex;

	// 위에 있는 map의 반복자를 이용하려면?
	std::map<int, Complex<int> >::iterator iter
		= map_complex.begin();

	// 그냥 auto를 이용하면?
	auto auto_iter = map_complex.begin();

	int num_list[ArrayLength()]; // 이게 가능!
	for (int i = 0; i < 10; ++i)
	{
		num_list[i] = i;
		printf("%d ", i);
	}
	printf("\n");

	const int *num_list_ptr = num_list;
	printf("num_list의 크기 : %d\n", sizeof(num_list));

	// 32비트와 64비트에서 호환되는 정수 형식!
	intptr_t test_int;
	printf("\ntest_int : ");
	scanf("%" SCNdPTR, &test_int);
	printf("test_int : %" PRIdPTR "\n\n", test_int);

	self_practice::TestClass *test_class_ptr
		= new self_practice::TestClass;

	printf("\n");
	test_class_ptr->NowObjectCount();

	printf("\n");
	::SafeDelete(reinterpret_cast<void *>(test_class_ptr));

	// if가 한 줄이면 이렇게 표현하라!
	if (true) printf("\n줄 구분하기!\n\n");

	// 반복자는 이렇게 반복문 안에서 선언하라!
	// 비어있는 for은 이렇게 표현하라!
	// 반복자는 전위 증감 연산자를 사용하라!
	for (int i = 0; i < 10; ++i)
	{ 
		continue;
	}

	// 비어있는 while문은 이렇게 표현하라!
	int i = 0;
	while (++i < 10) continue;

	self_practice::Child child1;
	self_practice::Child child2;
	child1.CopyField(&child2);

	// std::unique_ptr을 활용하라!
	std::unique_ptr<self_practice::Child> test_child1(new self_practice::Child);

	// test_child1은 다른 포인터에 주소를 넘길 수 없음!
	//std::unique_ptr<self_practice::Child> test_child2(test_child1);
	
	printf("test_child1의 주소 : %p\n\n", test_child1);

	// test_child1은 다른 포인터에 주소를 이동시킬 수는 있음!
	std::unique_ptr<self_practice::Child> test_child2(std::move(test_child1));
	printf("test_child1의 주소 : %p\n", test_child1);
	printf("test_child2의 주소 : %p\n", test_child2);
	return 0;
}