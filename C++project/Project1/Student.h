#include<iostream>
using namespace std;

class Student
{
public:
	string name;
	int xuehao;
	double score;

	int  Get_information();   //成员函数声明
	int Input_age(int stu_age);   //赋值年龄私有属性
	int Get_age();

	//无参构造函数
	Student()
	{
		cout<< "调用Student构造函数"<<endl;
	}

	//有参构造函数1
	Student(int s_age)
	{
		age = s_age;
		cout << "调用有参构造函数" << endl;
	}

	//有参构造函数2(拷贝)
	Student(const Student &p)
	{
		age = p.age;
		cout << "调用拷贝构造函数" << endl;
	}


	//析构函数
	~Student()
	{
		cout << "调用Student析构函数"<<endl;
	}

private:
	int age;
};
