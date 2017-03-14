#pragma once
#include <utility>

struct stMemory
{
	CArray<int> a;

	stMemory()
	{
		a.SetSize(100000);
	}
};

class CMoveSemantics
{
public:

	

	CMoveSemantics()
	{
	}

	virtual ~CMoveSemantics()
	{
	}

	void mainfunc()
	{
		volatile int a = 0;

		//for (int i = 0; i < 10000000; i++)
		//{
		//	//CString s = func();
		//	//CString s = func2();
		//	//CString s = func3();
		//	//CString&& s = func2();
		//	CString&& s = func4();
		//}

		auto i = AAA(10);

		a = 1;
	}

	// 7738
	//stMemory func()
	//{
	//	stMemory s;
	//	return s;
	//}

	//// 7891
	//stMemory func2()
	//{
	//	stMemory&& s;
	//	return s;
	//}

	//// 8182
	//stMemory func3()
	//{
	//	stMemory&& s;
	//	return ::std::move(s);
	//}

	//// 7533
	//stMemory&& func4()
	//{
	//	stMemory&& s;
	//	return std::move(s);
	//}

	auto AAA(int i) -> decltype(i)
	{
		return i + 1;
	}
};

