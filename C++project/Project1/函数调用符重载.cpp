#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

class Myoperator
{
	//（）重载
public:
	//重载功能：显示信息
	void operator()(string information)
	{
		cout << information << endl;

	}
	//重载功能：数据相加
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}


};


int main()
{
	Myoperator My1;
	My1("helloworld!");
	cout << "相加结果为：" << My1(10, 20) << endl;
}
