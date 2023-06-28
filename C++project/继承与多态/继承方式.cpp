#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

//基类
class  Base
{
public:
	int mA;

protected:
	int mB;

private:
	int mC;

};

//子类1：共有型继承
class Son1 :public Base
{
public:
	void func()
	{
		mA = 10; mB = 20;// mC = 30;
	}

	void out()
	{
		cout << "mA=" << mA << endl;
		cout << "mB=" << mB << endl;
	}
};

//子类2：保护型继承
class Son2 :protected Base
{
public:
	void func()
	{
		mA = 10; mB = 20;// mC = 30;
	}

	void out()
	{
		cout << "mA=" << mA << endl;
		cout << "mB=" << mB << endl;
	}
};

//子类3:私有型继承
class Son3 :private Base
{
public:
	void func()
	{
		mA = 10; mB = 20;// mC = 30;
	}
	void out()
	{
		cout << "mA=" << mA << endl;
;		cout << "mB=" << mB << endl;
	}
};

void test1()
{
	Son1 s1;
	s1.mA = 10; //s.mB = 20;
	Son2 s2;
	s2.func();
	s2.out();
	//s2.mA = 10; s2.mB = 20;
	Son3 s3;
	//s3.mA = 10; s3.mB = 20;

}


//int main()
//{ 
//	test1();
//	return 0;
//}

