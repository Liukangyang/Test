#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//函数模板定义
template <typename T>  //typename可用class来代替
void Change(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void func()
{
	cout << "调用func函数" << endl;

}


template <typename T>
T Add(T a, T b)
{
	return a+b;
}

template <typename T>
T Max(T const &a, T const &b)
{
	return a > b ? a : b;   //条件表达式
}

//函数模板重载
template<class T>
void print(T &a,T &b)
{
	cout << "This is the first template!" << endl;
	cout << a << ' ' << b << endl;
}

template<class T1,class T2>
void print(T1 &a, T2 &b)
{
	cout << "This is the second template!" << endl;
	cout << a << ' ' << b << endl;
}


int main()
{
	//调用函数模板生成模板函数
	//1.自动类型推导 
	int a = 10; int b = 20;
	double c = 2.2; double d = 3.3;
	//整形
	Change(a, b);
	cout << "a=" << a << endl; cout << "b=" << b << endl;
	//浮点型
	Change(c, d);
	cout << "c=" << c << endl; cout << "d=" << d << endl;

	//2。显示指定类型
	Change<int>(a, b);
	cout << "c=" << c << endl; cout << "b=" << b << endl;
	cout << "和函数的结果为:" << Add<double>(10, 20.9) << endl;
	cout << "和函数的结果为:" << Add<int>(10.9, 20) << endl;

	//函数模板调用
	func<char>();

	//Max函数
	cout << "最大值为：" << Max(10.2, 20.3) << endl;
	cout << "最大值为：" << Max<double>(10.2, 20) << endl;

	//函数模板重载
	print(a, b);
	print(b, d);
	//print<int>(c, d);  //报错！！！2个重载中没有一个可以转换所有类型
	

	return 0;
}