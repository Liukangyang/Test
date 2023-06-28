#include<iostream>
#include<string>
#include <set>
using namespace std;


//查找和统计
void test33()
{
	set<int> s;
	s.insert(10); s.insert(20); s.insert(30); s.insert(40); s.insert(30);
	//查找
	set<int>::iterator it= s.find(30);
	if (it !=s.end())
	{	
		cout << "元素存在：" << *it << endl;
	}
	else
	{
		cout << "元素不存在!" << endl;
	}

	//统计
	cout << "30的个数:" << s.count(30) << endl;


}

//multiset
void test34()
{
	multiset<int> m;
	m.insert(20); m.insert(10); m.insert(30); m.insert(20); m.insert(20);
	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "20的个数:" << m.count(20) << endl;
	cout << "容器大小:" << m.size() << endl;

}

//对组
void test35()
{
	//1.默认构造
	pair<string, int> p("TOM", 22);
	cout << "姓名" << p.first << "年龄" << p.second << endl;

	//2
	pair<string, int> p2 = make_pair("LKY", 23);
	cout << "姓名" << p2.first << "年龄" << p2.second << endl;
}
//int main()
//{
//	test35();
//	return 0;
//}