#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;


class Base
{
public:
	int mA;
};

class Son1:virtual public Base
{

};

class Son2:virtual public Base
{

};

class GrandSon :public Son1, public Son2
{

};

//int main()
//{
//	GrandSon s;
//	//同名成员
//	s.Son1::mA = 100;
//	s.Son2::mA = 200;
//	cout << "Son1's mA is:" << s.Son1::mA<< endl;
//	cout << "Son2's mA is:" << s.Son2::mA << endl;
//	//虚继承后的访问
//	cout << "GrandSon's mA is:" << s.mA << endl;
//
//
//}