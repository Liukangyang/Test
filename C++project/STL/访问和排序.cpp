#include<iostream>
#include<string>
#include <deque>
#include <algorithm>
using namespace std;

void printqeque2(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//静态迭代器
	{
		//*it = 10;
		cout << *it << " ";

	}
	cout << endl;
}

//访问
void test22()
{
	deque<int> d;
	d.push_back(10);d.push_back(20); d.push_back(30);
	d.push_front(100); d.push_front(200); d.push_front(300);
	//300 200 100 10 20 30
	printqeque2(d);
	//[]
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	//at()
	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << " ";
	}
	cout << endl;

	//front
	cout << "首部元素为：" << d.front() << endl;

	//back
	cout << "尾部元素为：" << d.back() << endl;
}

//排序sort
void test23()
{
	deque<int> d;
	d.push_back(10); d.push_back(20);
	d.push_front(100); d.push_front(200);
	printqeque2(d);//200 100 10 20

	sort(d.begin(), d.end());//从小到大排序
	cout << "排序后元素的顺序：" << endl;
	printqeque2(d);//10 20 100 200
}

//int main()
//{
//	test23();
//	return 0;
//}

