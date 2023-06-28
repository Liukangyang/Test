#include<iostream>
#include<string>
#include <list>
using namespace std;

void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造
void test26()
{
	//// list declaration of integer type 
	//list<int> mylist{ 1, 5, 3, 2, 4 };//可以在定义时就指定内容
	//默认
	list<int> l1;
	l1.push_back(10); l1.push_back(20); l1.push_back(30); l1.push_back(40);
	printList(l1);

	//传入区间
	list<int> l2(l1.begin(), l1.end());
	printList(l2);

	//拷贝构造
	list<int> l3(l2);
	printList(l3);

	//(n.elem);
	list<int> l4(10, 6);
	printList(l4);

}
//赋值
//assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem); //将n个elem拷贝赋值给本身。
//list& operator=(const list& lst); //重载等号操作符

void test27()
{
	list<int> l1;
	l1.push_back(10); l1.push_back(20); l1.push_back(30); l1.push_back(40);
	printList(l1);

	//operator =
	list<int> l2;
	l2 = l1;
	printList(l2);

	//assign
	list<int> l3;
	l3.assign(l1.begin(), l1.end());//===> l3=l1
	printList(l3);

	//assign(n,elem)
	list<int> l4;
	l4.assign(10, 6);
	printList(l4);


}

//交换
void test28()
{
	list<int> l1;
	l1.push_back(10); l1.push_back(20); l1.push_back(30); l1.push_back(40);

	list<int> l2;
	l2.push_back(40); l2.push_back(30); l2.push_back(20); l2.push_back(10);
	cout << "交换前的容器内容：" << endl;
	printList(l1);	printList(l2);

	//交换
	//l1.swap(l2);
	l2.swap(l1);
	cout << "交换后的容器内容：" << endl;
	printList(l1);	printList(l2);
}

//int main()
//{
//	test28();
//	return 0;
//}

