#include <stdio.h>
#include<iostream>
using namespace std;

class Person4
{
public:
	string name;
	double score;
	int age;

	//无参构造函数
	Person4()
	{
		cout << "调用Student构造函数" << endl;
	}

	//有参构造函数1
	Person4(int age, string s_name)
	{
		this->age = age; name = s_name;
		cout << "调用有参构造函数" << endl;
	}

	//析构函数
	~Person4()
	{

		cout << "调用析构函数" << endl;
	}

	Person4& Addage(int age)   //返回对象本身
	{
		this->age += age;
		return *this;
	}

	//有参构造函数2(拷贝)
	//Person4(const Person4& p)
	//{
	//	//深拷贝
	//	age = new int(*p.age);
	//	cout << "调用拷贝构造函数" << endl;
	//}



};

//int main()
//{
//	Person4 p1(10, "YY");
//	cout << p1.age << endl;
//	p1.Addage(10).Addage(10).Addage(10);   //链式编程
//	cout << p1.age<<endl;
//}