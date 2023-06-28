#include <stdio.h>
#include<iostream>
using namespace std;

class Person2
{
public:
	string name;
	double score;
	int age;


	////无参构造函数
	//Person2()
	//{
	//	cout << "调用Student构造函数" << endl;
	//}

	//有参构造函数
	Person2(int s_age)
	{
		age = s_age;
		cout << "调用有参构造函数" << endl;
	}

	//有参构造函数2(拷贝)
	//Person2(const Person2& p)
	//{
	//	age = p.age;
	//	cout << "调用拷贝构造函数" << endl;
	//}

};

//int main()
//{
//	Person2 p1(20);
//	p1.name = "LKY";
//	p1.score = 99;
//
//	Person2 p2(p1);
//	cout << p2.name << p2.age << p2.score << endl;
//	
//	system("pause");
//	return 0;
//}