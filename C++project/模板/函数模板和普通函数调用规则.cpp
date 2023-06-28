#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//普通函数
void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}

//函数模板
template <class T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}

//模板重载
template<typename T>
void myPrint(T a, T b, T c)
{
	cout << "调用重载模板" << endl;
}


//int main()
//{
//	int a = 10; int b = 10;
//	myPrint(a, b);  //1.都匹配时，优先调用普通函数
//
//	myPrint<>(a, b);  //2.强制调用函数模板
//
//	myPrint(a, b, 100); //3.模板重载
//
//	myPrint(2.2, 10.2);  //4.函数模板优先匹配
//
//	return 0;
//}