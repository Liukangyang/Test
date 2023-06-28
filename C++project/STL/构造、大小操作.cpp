#include<iostream>
#include<string>
#include <deque>
#include<stdio.h>
using namespace std;


void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//静态迭代器
	{
		//*it = 10;
		cout << *it << " ";

	}
	cout << endl;
}
//构造
//deque<T> deqT; //默认构造形式
//deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
//deque(n, elem); //构造函数将n个elem拷贝给本身。
//deque(const deque& deq); //拷贝构造函数
void test18()
{
	//1.默认构造
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//2区间
	deque<int> d2(d1.begin(),d1.end());
	printDeque(d2);

	//3拷贝构造
	deque<int> d3 = d2;
	printDeque(d3);
}

//大小操作
void test19()
{
	deque<int> d1;
	if (d1.empty()) cout << "初始时为空！" << endl;

	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	if (d1.empty()) cout << "初始时为空！" << endl;
	else cout << "容器不为空" << endl;

	printDeque(d1);
	cout << "容器大小：" << d1.size() << endl;

	d1.resize(20, 6);
	printDeque(d1);

	d1.resize(6);
	printDeque(d1);

}
//int main()
//{
//	test19();
//	return 0;
//}