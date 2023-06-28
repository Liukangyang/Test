#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//引用做函数重载条件
void func(int &a)
{
	cout << "调用(int &a)" << endl;
}

void func(const int& a)
{
	cout << "调用(const int &a)" << endl;
}

//函数重载用默认参数
void func1(int a ,int b=10)
{
	cout << "调用func1" << endl;

}

void func1(int a)
{
	cout << "调用func2" << endl;

}
int main()
{
	int a = 10;
	func(a);   //int &a=a;
	func(10.4);  //const int &a=10;
	//func1(10);//二义性
	func1(10, 20);
	return 0;
}