#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//2.1类模板的声明
template <class T1,class T2>
class Person;

//2.2类外实现(函数模板)
template <class T1,class T2>
void printPerson2(Person<T1, T2>& p)
{
	cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	//因为是友元，所以可以访问其私有成员
}

template<class T1, class T2>
class Person {
	//1.类内声明同时实现
	friend void printPerson(Person<T1,T2> &p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
		//因为是在类内的环境下，所以可以访问私有成员
	}
	//2.3 空模板参数(实例化函数)
	friend void printPerson2<>(Person<T1, T2>& p);

public:
	//成员函数类内声明
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	

private:
	T1 m_Name;
	T2 m_Age;
};



//int main()
//{
//	Person<string, int> p("LKY", 23);
//	Person<string, int> p2("YY", 22);
//	printPerson(p);
//	printPerson2(p2);
//
//	return 0;
//
//}