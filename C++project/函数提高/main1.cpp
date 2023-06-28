#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

//函数默认形参
int func1(int a,int b, int c=10)
{
	return a + b + c;
}


//int func2(int a=10, int b=10);


int func2(int a = 10, int b = 10)
{
	return a + b;
}
int func2(int a, int b);

int main1()
{
	cout << func1(10, 20)<<endl;
	cout << func1(10, 20, 20)<<endl;
	cout << func2(40,20);
	return 0;
}
