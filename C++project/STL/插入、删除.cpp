#include<iostream>
#include<string>
#include <deque>
using namespace std;

void printqeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)//静态迭代器
	{
		//*it = 10;
		cout << *it << " ";

	}
	cout << endl;
}

void test20()
{
	//push.pop
	deque<int> d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printqeque(d1);
	//头插
	d1.push_front(100);
	d1.push_front(200);
	printqeque(d1);//200 100 0 1.。。
	//头删除
	d1.pop_front();
	printqeque(d1);//100 0 1...
}

void test21()
{
	//插入insert
	deque<int> d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);
	printqeque(d1);//0 1 2...

	d1.insert(d1.begin() + 1, 20);
	printqeque(d1);//0 20 1 2 ...
//删除
	d1.erase(d1.begin() + 1);
	printqeque(d1);

	//d1.erase(d1.begin(), d1.end());
	d1.clear();//清空
	printqeque(d1);
	cout << "容器大小为：" << d1.size() << endl;

	


	
}
//int main()
//{
//	test21();
//	return 0;
//}