#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
//#pragma warning(disable:4996)

//枚举类型实例
void test1()
{
	//定义
	enum S {
		HELLO = 100,
		ROUTING = 200,
		INFO = 300,
		INFOAFK=400
	};
	//声明和赋值
	enum S tmp;
	tmp = HELLO;

	//int 类型无法自动转化为枚举类型，需强制类型转化
	//tmp = 200;
	tmp = S(300);

	//输出格式
	cout << tmp << endl;//输出为整数值

	//枚举类型字节数
	cout << sizeof(S) << endl;
	cout << sizeof(tmp) << endl;

}


//联合体类型实例
void test2()
{
	//
	union Student
	{
		int age;
		float score;
		char name[20];
	};

	//
	union Student stu;
	stu.age = 100;
	cout << stu.age << endl;
	cout << &stu.age << endl;

	//stu.name 未提前赋予指向空间
	//memcpy((void *)stu.name, (const void*)"LKY", sizeof("LKY"));

	strcpy(stu.name, "LKY");
	cout << stu.name << endl;
	cout << &stu.name << endl;

	cout << stu.age << endl;//此时age值已经变为随机值了
	cout << &stu.age << endl;
}


int main()
{
	//test1();
	test2();
	return 0;
}