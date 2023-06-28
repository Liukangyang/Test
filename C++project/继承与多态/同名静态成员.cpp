#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;


class Base
{
public:
	static int mA;
	Base()
	{
		cout << "Base默认构造函数" << endl;
	}

	~Base()
	{
		cout << "Base析构函数" << endl;
	}
	static void func()
	{
		cout << "Base-func()" << endl;
	}
	static void func(int a)
	{
		cout << "Base-func(int a)" << endl;
	}

};
int Base::mA=100;

class Son1 :public Base
{

public:
	static int mA;
	Son1()
	{
		cout << "Son默认构造函数" << endl;
	}
	~Son1()
	{
		cout << "Son析构函数" << endl;
	}
	static void func()
	{
		cout << "Son-func()" << endl;
	}
};

int Son1::mA = 200;

//int main()
//{
//	Son s;
//	cout <<"Son's mA is: " << s.mA << endl;
//	cout << "Base's mA is: " << s.Base::mA << endl;
//	s.func();
//	s.Base::func();
//	s.Base::func(100);
//	system("pause");
//	return 0;
//}
