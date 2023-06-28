#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

//以多态形式实现计算功能拓展
//计算器抽象类
class Calculation
{
public:
	//操作数
	int a1;
	int a2;
	//计算函数（虚函数）
	virtual float calclulation()
	{
		return 0;
	}
};

//加法
class Add :public Calculation
{
public:
	//函数功能重定义
	float calclulation()
	{
		 return a1 + a2;
	}
};


//减法
class Sub :public Calculation
{
public:
	//函数功能重定义
	float calclulation()
	{
		return a1 - a2;
	}
};

//乘法
class Multiple :public Calculation
{
public:
	//函数功能重定义
	float calclulation()
	{
		return a1 * a2;
	}
};

//除法
class Division :public Calculation
{
public:
	//函数功能重定义
	float calclulation()
	{
		if (a2 == 0)
		{
			cout << "除数不能是0";
			return 0;
		}
		else return a1 / (float)a2;
	}
};


//int main()
//{
//	//加法
//	Calculation* p = new Add;
//	p->a1 = 10; p->a2 = 10;
//	cout << p->a1 << "+" << p->a2 << "=" << p->calclulation() << endl;
//
//	//减法
//	delete p;
//	p = new Sub;
//	p->a1 = 10; p->a2 = 10;
//	cout << p->a1 << "-" << p->a2 << "=" << p->calclulation()<< endl;
//
//	//乘法
//	delete p;
//	p = new Multiple;
//	p->a1 = 10; p->a2 = 20;
//	cout << p->a1 << "*" << p->a2 << "=" << p->calclulation() << endl;
//
//	//除法
//	delete p;
//	p = new Division;
//	p->a1 = 10; p->a2 = 20;
//	cout << p->a1 << "/" << p->a2 << "=" << p->calclulation() << endl;
//	
//
//
//}