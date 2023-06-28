#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

//类模板
template<class NameType, class AgeType = int>
class Person
{
public:
	NameType mName;
	AgeType mAge;
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}

};
//1、指定传入的类型
void Myprint1(Person<string,int> &p)
{
	p.showPerson();

}

//2、参数模板化
template <class T1,class T2>
void Myprint2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1的类型为： " << typeid(T1).name() << endl;
	cout << "T2的类型为： " << typeid(T2).name() << endl;
}

//3.整个类模板化
template <class T>
void Myprint3(T& p)
{
	p.showPerson();
	cout << "T的类型为： " << typeid(T).name() << endl;
}

//int main()
//{
//	Person<string> p("孙悟空", 1000);
//	Myprint1(p);//1
//	Myprint2(p);//2
//	Myprint3(p);//3
//	return 0;
//}
