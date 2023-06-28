#include<iostream>
#include<stdlib.h>
using namespace std;

//引用做函数返回值
//1.不要返回对（一般的）局部变量的引用
int& test1()
{
  int a = 10;
	return a;//返回对a的引用
}

//若确实需要返回对a的引用，则需声明为静态变量
//静态变量开辟在内存区，函数调用完后还会继续保留，故引用仍然有效。
int& test2()
{
	static int a = 10;
	return a;//返回对a的引用
}

int& test3()
{
	static int a = 20;
	return a;//返回对a的引用
}

//2.若函数的返回值是一个引用，则函数的调用本身可以作为（运算符的）左值
int& test4()
{
	static int a = 60;
	return a;//返回对a的引用
}



int main()
{
	int& q1 = test1();//q是对a的引用
	cout << "a=" << q1 << endl;//函数调用完后局部变量就被释放掉了

	int& q2 = test2();
	cout << "a=" << q2 << endl;//函数调用完后静态局部变量仍然保留，故q2引用有效

	int& q3 = test3();
	cout << "a=" << q3 << endl;

	cout << "test2()中的变量值" << q2 << endl;
	cout << "test3()中的变量值" << q3 << endl;
	q3 = q2;//赋值操作
	cout << "test2()中的变量值" << q2 << endl;
	cout << "test3()中的变量值" << q3 << endl;
	//说明通过外部引用可实现函数内部局部变量的修改赋值操作
	cout << endl;

	//2测试
	int& q4 = test4();
	cout << "test4()的值" << q4<<endl;
	test4() = 100;
	cout << "test4()的值" << q4<<endl;


	return 0;
}