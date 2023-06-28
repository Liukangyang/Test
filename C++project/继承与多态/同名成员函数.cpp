#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

class Base
{
public:
	int mA;
	Base()
	{
		cout << "Base默认构造函数" << endl;
	}

	~Base()
	{
		cout << "Base析构函数" << endl;
	}
	void func()
	{
		cout << "Base-func()" << endl;
	}
	void func(int a)
	{
		cout << "Base-func(int a)" << endl;
	}

};

class Son1 :public Base
{

public:
	int mA;  //子类中的同名成员属性
	Son1() 
	{
		cout << "Son默认构造函数" << endl;
	}
	~Son1()
	{
		cout << "Son析构函数" << endl;
	}
	void func()
	{
		cout << "Son-func()" << endl;
	}
};

//int main()
//{
//	Son s;
//	s.func();
//	s.Base::func();
//	s.Base::func(100);
//
//	//父类指针指向子类对象
//	Base* p = new Son();
//	p->func();// 调用的是父类的同名函数
//	system("pause");
//	return 0;
//}
