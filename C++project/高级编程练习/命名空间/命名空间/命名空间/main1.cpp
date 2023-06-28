#include<iostream>
#include<string>
using namespace std;

namespace name1
{
	void func()
	{
		cout << "This is the first name_space!" << endl;
	}
}

namespace name2
{
	void func()
	{
		cout << "This is the sencond name_space!" << endl;
	}
}

namespace A
{
	void func1()
	{
		cout << "This is the first name_space!" << endl;
	}

	namespace B
	{
		void func1()
		{
			cout << "This is the second name_space!" << endl;
		}

	}
}
void test1()
{
	//1.命名空间名::函数名
	//func();  //报错：未定义表示标识符（编译器无法识别）
	name1::func();
	name2::func();

	//2.提前使用using指令指定命名空间
	using namespace name1;
	func();
	name2::func();   //显示声明

}

void test2()
{
	//
	A::func1();
	A::B::func1();

	//
	using namespace A;
	func1();
	A::B::func1();

}
int main()
{
	//测试1
	//test1();

	//测试2
	test2();

	return 0;
}