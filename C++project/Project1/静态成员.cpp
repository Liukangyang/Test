#include <stdio.h>
#include<iostream>
using namespace std;

class Person4
{
public:
	string name;
	static double score;
	int age;

	static void Moid_information()  //静态成员函数
	{
		score = 99;
	}
	//无参构造函数
	Person4() 
	{
		cout << "调用Student构造函数" << endl;
	}

	//有参构造函数1
	Person4(int s_age, string s_name) 
	{
		age = s_age; name = s_name;
		cout << "调用有参构造函数" << endl;
	}


	//析构函数
	~Person4()
	{

		cout << "调用析构函数" << endl;
	}

	//有参构造函数2(拷贝)
	//Person4(const Person4& p)
	//{
	//	//深拷贝
	//	age = new int(*p.age);
	//	cout << "调用拷贝构造函数" << endl;
	//}



};

double Person4::score = 100;  //静态成员初始化


//int main()
//{
//	Person4 p1(22, "LKY");
//	Person4 p2(20, "YY");
//	cout << p1.name << p1.age << p1.score<<endl;
//	cout << p2.name << p2.age << p2.score<<endl;
//	Person4::Moid_information();
//	cout << Person4::score << endl;
//	cout << p1.score << endl;
//	cout << p2.score << endl;
//
//}