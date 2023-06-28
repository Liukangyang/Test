#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <ctime>
#include <Windows.h>
using namespace std;

void print(int val)
{	
	cout << val << " ";
}

void printVector(vector<int> &v)
{
	for_each(v.begin(), v.end(), print);
	cout << endl;
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
	//重载==
	bool operator==(const Person& p)
	{	
		return this->m_Age == p.m_Age && this->m_Name == p.m_Name;
	}
};
//find
void test4()
{
	//查找内置数据类型
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	printVector(v);

	vector<int>::iterator it=find(v.begin(), v.end(), 8);
	if (it == v.end())
		cout << "未找到元素！" << endl;
	else
	{
		cout << "找到元素：" << *it << endl;
	}

	//查找自定义数据类型
	Person p1("zhangsan", 22);
	Person p2("lisi", 26);
	Person p3("wangwu", 28);
	vector<Person> v2;
	v2.push_back(p1); v2.push_back(p2); v2.push_back(p3);
	Person pp("zhangsan", 22);
	vector<Person>::iterator it2=find(v2.begin(), v2.end(), pp);
	if (it2 == v2.end())
		cout << "未找到对象！" << endl;
	else
	{
		cout << "找到对象：" << " " << it2->m_Name <<"  " <<it2->m_Age<< endl;
	}

}

//仿函数
class mycompare
{
public:
	bool operator()(int val)
	{
		return val >= 9;
	}
};
//find_if
void test5()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	printVector(v);

	vector<int>::iterator it=find_if(v.begin(), v.end(), mycompare());
	if (it == v.end())
		cout << "未找到元素！" << endl;
	else
	{
		cout << "找到元素：" << *it << endl;
	}

}

void test6()
{
	//查找相邻重复元素
	vector<int> v;
	v.push_back(2); v.push_back(4); v.push_back(1); v.push_back(3);
	v.push_back(8); v.push_back(7); v.push_back(9);
	printVector(v);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
		cout << "未找到元素！" << endl;
	else
	{
		cout << "找到重复元素：" << *it << endl;//指定第一个重复元素
		cout << "前一个元素为:" << *(it - 1) << endl;
	}

	//二分法查找
	cout << "二分法查找！" << endl;
	//变为有序序列
	sort(v.begin(), v.end());
	printVector(v);

	DWORD Start = GetTickCount();
	bool ret=binary_search(v.begin(), v.end(), 9);
	DWORD End = GetTickCount();
	
	if (ret)
	{
		cout << "找到元素！" << endl;
		cout << "二分法查找时间:" << (End-Start)*55 << "ms" << endl;
	}
	else
	{
		cout << "元素不存在！" << endl;	
	}



}

class Compare
{
public:
	bool operator()(Person &p)const
	{
		return p.m_Age > 23;
	}
};
//统计
void test7()
{
	//count()
	vector<int> v;
	v.push_back(2); v.push_back(3); v.push_back(3); v.push_back(3); v.push_back(4);
	int num = count(v.begin(), v.end(), 3);
	cout << "元素个数为：" << num << endl;

	//统计内置数据类型
	vector<Person> v2;
	Person p1("zhangsan", 22); Person p2("lisi", 24);
	Person p3("LKY", 23); Person p4("YY", 23);
	Person p5("zhangsan", 22);

	v2.push_back(p1); v2.push_back(p2);
	v2.push_back(p3); v2.push_back(p4);
	v2.push_back(p5);

	Person pp("zhangsan", 22);
	num = count(v2.begin(), v2.end(), pp);
	cout << "相同对象个数：" << num << endl;

	//count_if
	num=count_if(v2.begin(), v2.end(), Compare());
	cout << "满足条件的对象个数：" << num << endl;

}


//int main()
//{	
//	//test4();
//	//test5();
//	//test6();
//	test7();
//	return 0;
//}