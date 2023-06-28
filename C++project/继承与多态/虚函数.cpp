#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;


class Base
{
public:
	virtual void func()
	{
		cout << "This is class Base!" << endl;
	}

};

class Son1 :public Base
{
public:
	//函数重写（不是重载）
	void func()
	{
		cout << "This is class Son1!" << endl;
	}
};

class Son2 :public Base
{
public:
	void func()
	{
		cout << "This is class Son2!" << endl;
	}
};

void out(Base *p)
{
	p->func();
}

//int main()
//{
//	//定义子类对象
//	Son1 s1;
//	//未定义虚函数时，调用的是父类函数
//	//out(&s1);
//	//定义虚函数后,调用的是子类覆写函数
//	out(&s1);
//	Son2 s2;
//	out(&s2);
//	return 0;
//}