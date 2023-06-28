#include<iostream>
#include<stdlib.h>
using namespace std;

//引用传递（引用做函数参数）
//等价于地址传递，但是更加简洁高效
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main2()
{
	int a = 10;
	int b = 20;
	cout << "交换前的值: " << endl;
	cout << "a:" << a << "  b: " << b << endl;
	Swap(a, b);
	cout << "交换后的值:" << endl;
	cout << "a:" << a << "  b: " << b << endl;
	return 0;
}