#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

float function(float a,float b)
{
	if (b == 0)
	{
		throw new string("除数为0！");  //可能出现异常的现场
	}
	return a / b;
}
int main()
{
	float a = 10.2;
	float b = 0.0;
	float r = 0.0;
	try
	{
		 r = function(a, b);
	}
	catch (string* error)//catch(异常类型 形参)
	{
		cout << "捕获异常:" << error->c_str() << endl;
	}

	//cout << "程序继续运行" << endl;
	cout <<"计算结果：" << r << endl;
	system("pause");
	return 0;
}