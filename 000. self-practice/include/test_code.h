
// <프로젝트 이름>_<소스 파일의 경로>_<소스 파일의 이름>
#ifndef SELF_PRACTICE_TEST_CODE_H_
#define SELF_PRACTICE_TEST_CODE_H_

#include <iostream>

namespace self_practice
{
class Test
{
public:
	// 생성자 위임
	Test() : Test{ 0 } { }
	
	// 변환 생성자에는 무조건 explicit을 써라!
	explicit Test(const int test_int) : test_int_(test_int)
	{ 

	}

	// std::initializer_list를 이용하면
	// 중괄호 초기화가 가능하다!
	Test(std::initializer_list<int> test_int)
	{

	}

	void Show() { printf("유후후\n"); }
protected:
private:
	int test_int_; // 필드는 _를 하나 더 붙임!

	// 복사 생성자 및 대입 연산자를
	// 사용하지 않는다면 이렇게 private으로 막아라!
	DISALLOW_COPY_AND_ASSIGN(Test)
};
} // namespace self_practice

namespace self_practice
{
// abstract는 추상 클래스라는 표시
class Parent abstract
{
public:
	// Parent()의 초기화를
	// explicit Parent(const int test_int)가 담당!
	// 이게 바로 생성자 위임! (Constructors Delegation)
	Parent() : Parent(0) { }
	explicit Parent(const int test_int)
		: test_int_(test_int) { }
	virtual ~Parent() { }

	// 가상 함수
	virtual void Talk() const abstract
	{
		printf("나는 부모다!\n");
	}

	// 이럴 때 abstract를 쓰면 순수 가상 함수로 취급
	// 무조건 자식 클래스에서 오버라이딩을 해야 함!
	virtual void Action() const abstract;
private:
	int test_int_;
};

// 상속은 public 상속!
// final => 상속 관계 종결!
class Child final : public Parent
{
public:
	// 자식 클래스가 부모 클래스의
	// 생성자를 가진 것처럼 작동!
	// 이게 바로 생성자 상속! (Constructors Inheritance)
	using Parent::Parent;
	virtual ~Child() { }

	// 가상 함수
	// override => 오버라이딩 메서드라는 표시
	// final => 오버라이딩 종결
	virtual void Talk() const override final
	{
		printf("나는 자식이다!\n");
	}

	virtual void Action() const override final
	{
		printf("돌아다니자!\n");
	}

	// 연산자 오버로딩 대신 복사 함수!
	void CopyField(Child *child_ptr)
	{
		child_ptr->test_char_ = test_char_;
	}

	void Show()
	{
		printf("%c\n", test_char_);
	}

	// 정보 은폐를 위한 접근 함수
	char get_test_char_()
	{
		return test_char_;
	}
	void set_test_char_(const char &test_char)
	{
		test_char_ = test_char;
	}
private:
	// 정보 은폐를 위해 필드는 private으로!
	char test_char_ = '\0'; // 생성자 상속 때문에 등장한 문법!
};

// POD 구조체
// 구조체는 일반 변수의 이름 규칙을 적용!
struct Coordinates
{
	int x, y;
};

// C++ 스타일의 구조체
struct Object
{
	// 필드
	Coordinates obj_pos;
	int obj_code;
	static int obj_count;
	
	// 메서드
	Coordinates get_obj_pos() const
	{
		return obj_pos;
	}

	// 참조자 매개변수는 const를 붙여라!
	void set_obj_pos(const int &x, const int &y)
	{
		obj_pos.x = x;
		obj_pos.y = y;
	}
};
int Object::obj_count = 0;

} // namespace self_practice

namespace self_practice
{
class TestOrder
{
public:
	typedef int *IntPtr;
	enum class EnumClass
	{
		kOne, kTwo
	};
	static const int kObjectCount;
	TestOrder() { }
	virtual ~TestOrder() { }
	static const int get_kObjectCount() { return kObjectCount; }
	int test_int_;
protected:
private:
	friend void TestFunction();
	DISALLOW_COPY_AND_ASSIGN(TestOrder)
};
} // namespace self_practice

void self_practice::TestFunction()
{

}
#endif