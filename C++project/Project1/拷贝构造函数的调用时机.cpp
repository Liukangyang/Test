#include <stdio.h>
#include<iostream>
using namespace std;

class pp
{
public:
	string name;
	double score;
	int age;


	//无参构造函数
	pp()
	{
		cout << "调用Student构造函数" << endl;
	}

	//有参构造函数1
	pp(int s_age)
	{
		age = s_age;
		cout << "调用有参构造函数" << endl;
	}

	//有参构造函数2(拷贝)
	pp(const pp& p)
	{
		age = p.age;
		cout << "调用拷贝构造函数" << endl;
	}


	//析构函数
	/*
	~Student()
	{
		cout << "调用Student析构函数" << endl;
	}*/


};


void test01()
{
	pp s1(12);
	pp s2(s1);
	cout << "年龄为：" << s2.age << endl;
}

void work1(pp s)
{
	cout << "调用自定义函数" << endl;
	cout << "年龄为：" << s.age << endl;
}
void test02()
{
	pp s1(12);
	work1(s1);
}

pp work2()
{
	pp s(22);
	cout << "调用函数返回值" << endl;
	return s;
}
void test03()
{
	pp s2 = work2();
	cout << "年龄为：" << s2.age << endl;
}

//int main()
//{	
//	test03();
//	system("pause");
//	return 0;
//}