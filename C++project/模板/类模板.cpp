#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//类模板
template<class Nametype=string,class Agetype=int>  //提供默认类型参数
class Person
{
public:
	Person(Nametype name,Agetype age)
	{
		m_name = name;
		m_age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_name << " age: " << this->m_age << endl;
	}
	Nametype m_name;
	Agetype m_age;

};

//int main()
//{
//	//实例化类
//	Person<string, int> p1("孙悟空", 1000);
//	p1.showPerson();
//
//	Person<> p2("猪八戒", 999);
//	p2.showPerson();
//	return 0;
//}