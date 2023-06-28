#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base构造函数" << endl;

	}
	////虚析构函数
	//virtual ~Base()
	//{
	//	cout << "Base析构函数" << endl;
	//}
	//纯虚析构声明
	virtual ~Base() = 0;

};

//纯虚析构定义
Base::~Base()
{
	cout << "Base纯虚析构" << endl;
}

class Son :public Base
{
public:
	int* p;//指针成员
	Son(int a)
	{

		p = new int(a);  //开辟到堆区
		cout << "Son构造函数" << endl;

	}
	//析构函数
	~Son()
	{
		if (p != NULL)
		{
			delete p;
			p = NULL;
		}
		cout << "Son析构函数" << endl;
	}

};

int main()
{
	//Son s1(10);
	//动态多态
	Base* p = new Son(10);

	delete p;
	p = NULL;
	return 0;
}