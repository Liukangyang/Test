#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;


class pp
{
public:
	int m_a;
	int m_b;
	int* mA;

	pp()
	{
		mA= new int;
	}
	pp(int a, int b,int num)
	{
		m_a = a;
		m_b = b;
		mA = new int(num);
	}

	//~pp()
	//{
	//	if (mA != NULL)
	//	{
	//		delete  mA;
	//		mA = NULL;
	//	}
	//	cout << "调用析构函数!" << endl;
	//}

//赋值运算符重载
	pp& operator =(pp &p)
	{

		delete mA;
		mA = NULL;
		mA = new int(*p.mA);
		return *this;
	}
	

};

void test11()
{
	pp p1(1, 2, 18);
	pp p2(1, 2, 20);
	pp p3(1, 2, 22);
	cout << *p1.mA << endl;	cout << *p2.mA << endl;	cout << *p3.mA << endl;
	//对象赋值
	//p2 = p1;
	p3 = p2 = p1;
	cout << *p3.mA << endl;
	cout << p1.mA << endl; cout << p2.mA << endl; cout << p3.mA << endl;



}
//int main()
//{
//	test11();
//
//}
