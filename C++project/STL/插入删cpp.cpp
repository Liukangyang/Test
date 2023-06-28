#include<iostream>
#include<string>
#include <list>
using namespace std;

void printList2(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

}

//插入与删除
void test29()
{
	list<int> l1;
	//尾插
	l1.push_back(10); l1.push_back(20); l1.push_back(30); 
	printList2(l1);
	//头插
	l1.push_front(100); l1.push_front(200); l1.push_front(300);
	printList2(l1);//300 200 100 10 20 30

	//头删
	l1.pop_front();
	printList2(l1);//200 100 10 20 30 

	//insert
	list<int>::iterator pos = l1.begin();
	l1.insert(++pos, 1000);
	printList2(l1);//200 1000 100 10 20 30

	//erase
	pos = l1.end();
	l1.erase(--pos );//====> 尾删:l1.pop_back()
	printList2(l1);//200 1000 100 10 20 

	//remove(elem)
	l1.push_back(666);	l1.push_front(666);
	printList2(l1);
	l1.remove(666);
	printList2(l1);

	//数据存取
	cout << "头部元素：" << l1.front() << endl;//200
	cout << "尾部元素：" << l1.back() << endl;//20
	list<int> ::iterator it = l1.end();
	it++;//前向
	it--;//后向
	//it = it + 1;//报错：不支持随机访问
}

//降序判断逻辑
bool mycompare(int v1,int v2)
{
	return v1 > v2;
}
//反转和排序
void test30()
{
	
	list<int> l1;
	l1.push_back(10); l1.push_back(50); l1.push_back(40); l1.push_back(30);
	printList2(l1);
	//反转
	cout << "反转后:" << endl;
	l1.reverse();
	printList2(l1);

	//排序
	cout << "排序后：" << endl;
	l1.sort();//默认升序排序
	printList2(l1);

	l1.sort(mycompare);//降序排序
	cout << "降序排序结果：" << endl;
	printList2(l1);
}


//int main()
//{
//	test30();
//	return 0;
//}