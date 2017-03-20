#pragma once

// .h + .cpp = .hpp
template <typename T>
class CMyData
{
private:
	T Data;
public:
	CMyData(void);
	explicit CMyData(T tData);
	virtual ~CMyData(void);
	T GetData(void);
};

#pragma region CMyData 정의
template <typename T>
CMyData<T>::CMyData(void) { printf("생성자 호출!\n"); }

template <typename T>
CMyData<T>::CMyData(T tData) : Data(tData) { printf("생성자 호출!\n"); }

template <typename T>
CMyData<T>::~CMyData(void) { printf("소멸자 호출!\n"); }

template <typename T>
T CMyData<T>::GetData(void) { return Data; }
#pragma endregion