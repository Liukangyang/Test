#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

template<class T1, class T2>
class Person {
public:
	T1 m_Name;
	T2 m_Age;
	//成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();
};

//类外实现
template <class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template <class T1,class T2>    //需要声明通用类型参数
void Person<T1,T2>::showPerson()   //类模板名字后需加上类型参数列表，表示来自于类模板
{
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}




//int main()
//{
//	Person<string, int> p("LKY", 22);
//	p.showPerson();
//	return 0;
//}
