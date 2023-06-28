#include <stdio.h>
#include<iostream>
using namespace std;

class Person4
{
public:
	string name;
	double score;
	int *age;


	//无参构造函数
	Person4()
	{
		cout << "调用Student构造函数" << endl;
	}

	//有参构造函数1
	Person4(int s_age)
	{
		age = new int(s_age);
		cout << "调用有参构造函数" << endl;
	}


	//析构函数
	~Person4()
	{
		if (age != NULL)
		{ 
			delete age;
			age = NULL;
		}

		cout << "调用析构函数" << endl;
	}

	int Get_age()
	{
		if (age!=NULL)
			return *age;
	}
	//有参构造函数2(拷贝)
	Person4(const Person4& p)
	{
		//深拷贝
		age = new int(*p.age);
		cout << "调用拷贝构造函数" << endl;
	}

};
//int main()
//{
//	Person3 p1(22);
//	Person3 p2(p1);
//	cout << "p1指针地址:" << p1.age << endl;
//	cout << "p2指针地址:" << p2.age << endl;
//	cout << "p2年龄" << *p2.age << endl;
//	*p1.age = 18;
//	cout << "p2年龄" << *p2.age << endl;
//	system("pause");
//	return 0;
//}