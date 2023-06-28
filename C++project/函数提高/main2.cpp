#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//函数重载
void func()
{
	cout << "调用func1" << endl;
}

void func(int a)
{
	cout << "调用func2" << endl;
}

//函数形参名字不作为重载条件
/*
void func(int b)
{
	cout << "调用func22" << endl;
}*/

//函数返回值不作为重载条件
/*
int func(int a)
{
	cout << "调用func2" << endl;
}*/

void func(int a,int b)
{
	cout << "调用func3" << endl;
}

void func(double a, int b)
{
	cout << "调用func4" << endl;
}

void func(int a, double b)
{
	cout << "调用func5" << endl;
}



int main2()
{
	func();//func1
	func(10); //func2
	func(10,20); //func3
	func(10.0, 20); //func4
	func(10, 20.0); //func5

	return 0;
}
