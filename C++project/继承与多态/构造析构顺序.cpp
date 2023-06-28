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
	Base(int a)
	{
		cout << "Base有参构造函数" << endl;
		mA = a;
	}
	~Base()
	{
		cout << "Base析构函数" << endl;
	}


};

class Son1 :public Base
{

public:
	int mA;
	Son1():Base(88)  //显示调用父类有参构造
	{
		cout << "Son默认构造函数" << endl;
	}
	~Son1()
	{
		cout << "Son析构函数" << endl;
	}
};

//int main()
//{
//	Son s;
//	s.Base::mA = 10;
//	s.mA = 20;
//	cout << "子类的mA=" << s.mA << endl;
//	cout << &s.mA << endl;
//	cout << "父类的mA=" << s.Base::mA << endl;
//	cout << &s.Base::mA << endl;
//	system("pause");
//	return 0;
//}