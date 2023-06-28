#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

class pp
{
public:
	int m_a;
	int m_b;
	
	pp()
	{

	}
	pp(int a, int b)
	{
		m_a = a;
		m_b = b;
	}

	//成员函数重载
	//ss operator+(ss& p)
	//{
	//	ss temp;
	//	temp.m_a = this->m_a + p.m_a;
	//	temp.m_b = this->m_b + p.m_b;
	//	return temp;
	//}

};

//全局函数重载
pp operator+(pp& p1, pp& p2)
{
	pp temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;

}

//重载函数重载
pp operator + (pp& p, int num)
{
	pp temp;
	temp.m_a = p.m_a + num;
	temp.m_b = p.m_b + num;
	return temp;

}

//重载左移运算符
ostream& operator << (ostream& cout, pp& p)
{
	cout << "m_a=" << p.m_a<<endl;
	cout << "m_b=" << p.m_b << endl;
	return cout;
}


void t1()
{
	pp p1,p2;
	p1.m_a = 10; p1.m_b=10;
	p2.m_a = 20; p2.m_b = 20;
	pp p3 = p1 + p2;
	cout << p3.m_a << endl; 

	pp p4 = p3 + 10;
	cout << p4.m_a << endl;
	cout << p4.m_b << endl;


}

void t2()
{
	pp p1(10,10);
	cout << p1 <<"hello"<<endl;


}

//int main()
//{
//	t2();
//}
