#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;


//抽象类
class Base
{
public:
	virtual void func() = 0;
};

//子类
class Son :public Base
{
public:
	void func()
	{
		cout << "func()" << endl;
	}

};
//int main()
//{
//	Base* b = new Son;
//	b->func();
//	return 0;
//}
