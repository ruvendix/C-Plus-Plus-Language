
// <프로젝트 이름>_<소스 파일의 경로>_<소스 파일의 이름>
// 프로젝트 이름    : self-practice
// 소스 파일의 경로 : ruvendix/
// 소스 파일의 이름 : use.h
#ifndef SELF_PRACTICE_RUVENDIX_USE_H_
#define SELF_PRACTICE_RUVENDIX_USE_H_

// 전방 선언 대신! 헤더 파일을 포함시켜라!
#include "test_code.h"

// 헤더 파일에는 이름 있는 namespace만 사용!
namespace self_practice
{
class Test; // 전방 선언
class Use
{
// 클래스의 접근 한정자 순서는
// public -> protected -> private!
public:
	// 이렇게 필드(멤버 변수)를 포인터로
	// 이용하려고 전방 선언을 이용하지 마라!
	Test *test_ptr_;

	Test test_;
	Use() : test_(10) // 생성자에서 필드를 초기화!
	{
		// 생성자에서는 복잡한 작업을 하지 마라!
	}

	// 소멸자는 상속될 가능성이 있으면
	// 가상 함수로 만들어라!
	virtual ~Use()
	{

	}

	// const는 적극적으로 활용하라!
	inline void ShowGuide() const
	{
		printf("10줄 이하는 인라인 함수로 만들어라!\n");
		printf("이렇게 클래스 안에서 굳이 inline을 붙이지 않아도\n");
		printf("인라인 함수가 된다!\n");
	}

	// 매개변수는 입력 -> 출력 순서로 만들어라!
	const int AddNum(const int num1, const int num2, int *result_ptr) const
	{
		*result_ptr = num1 + num2;
		return *result_ptr;
	}
protected:
private:
	DISALLOW_COPY_AND_ASSIGN(Use)
};
} // namespace self_practice

namespace self_practice
{
class TestClass
{
public:
	static int object_count_;
	TestClass();

	// 전역 함수 대신! static 메서드!
	static void NowObjectCount()
	{
		printf("현재 생성된 객체의 수 : %d\n", object_count_);
	}
private:
	// 멤버 클래스
	class MemberClass
	{
	public:
		void Show()
		{
			printf("멤버 클래스 호출!\n");
		}
	};
};
int TestClass::object_count_ = 0;
} // namespace self_practice 이렇게 표시!

 // 외부에서 함수를 정의하려면
 // 반드시 namespace를 일치시켜야 함!
namespace self_practice
{
TestClass::TestClass()
{
	printf("생성자 호출!\n");
	object_count_++;

	// 멤버 클래스 이용하기!
	MemberClass member_class_;
	member_class_.Show();
}
} // namespace self_practice 이렇게 표시!

#endif