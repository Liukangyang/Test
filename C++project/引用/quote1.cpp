#include<iostream>
#include<stdlib.h>
using namespace std;

int main1()
{
	//引用示例
	int a = 10;
	int &b = a;//必须一开始就初始化
	cout << b << endl;

	b = 22;//等价于对a的修改
	cout << b << endl;
	cout << a << endl;

	int c = 100;
	b = c;//可以更改引用吗？(不可以，该语句实则为赋值操作)
	cout << b << endl;
	cout << a << endl;

	return 0;
}