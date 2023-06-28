#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//类模板
template<class T>
class Base
{
public:
	T m;
};

//子类1
class Son :public Base<int>  //指定类型参数
{

};

//子类2(模板)
template<class T1,class T2>
class Son2 :public Base<T1>
{
public:
	Son2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
	T2 a;
};


//int main()
//{
//	//Son s2;
//	Son2<char, double> s2;
//	cout<<typeid(s2.m).name()<<endl;
//	cout << typeid(s2.a).name();
//
//	return 0;
//}