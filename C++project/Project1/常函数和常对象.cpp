#include <stdio.h>
#include<iostream>
using namespace std;

class Person4
{
public:
	string name;
	double score;
	mutable int age;

	void Moid_age() const
	{
		//this->age = 100;
		//cout << this->age;   //可以访问属性但是不能修改
		this->age = 100;  //要修改就要添加mutable关键字

	}

	void fun()
	{
		cout << "调用一般函数" << endl;
	}

	//无参构造函数
	Person4()
	{
		cout << "调用默认构造函数" << endl;
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
//	Person4 p1;
//	p1.Moid_age();
//	cout << p1.age << endl;
//	//常对象
//	const Person4 p2;
//	p2.age = 20;   //const对象可法修改特殊属性
//	cout << p2.score << endl;
//	//p2.name = "LKY";  //const对象无法修改一般属性
//	//p2.fun();   //const对象只能直接调用常函数
//

//}