#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

//cin.ignore()函数
int main()
{
	string str;
	cout << "Enter your content: " << endl;
	cin >> str;
	cout << str << endl;

	cout << "请输入任意字符结束程序！ ";
	//cin.get();//实际上读取了回车
	//1.再次调用get函数
	//cin.get();

	//2.调用ignore函数(提取回车符号并忽略)
	//cin.ignore(1024, '\n');
	cin.ignore();
	cin.get();

	return 0;
}
