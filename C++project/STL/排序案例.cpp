#include<iostream>
#include<string>
#include <list>
using namespace std;

//自定义数据类型排序
class Person
{
public:
	string m_Name;
	int m_Age;
	int m_Height;
	Person(string name, int age, int height)
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
};


//逻辑规则
bool mycompare(Person &p1,Person &p2)
{	
	if (p1.m_Age == p2.m_Age)
		return p1.m_Height > p2.m_Height;//身高降序
	else
		return p1.m_Age < p2.m_Age;//年龄升序
}


//int main()
//{
//	list<Person> l;
//
//	Person p1("张三", 32, 180);
//	Person p2("曹操", 45, 180);
//	Person p3("孙权", 40, 170);
//	Person p4("赵云", 25, 190);
//	Person p5("张飞", 35, 160);
//	Person p6("关羽", 35, 200);
//
//	l.push_back(p1); l.push_back(p2);
//	l.push_back(p3); l.push_back(p4);
//	l.push_back(p5); l.push_back(p6);
//
//	//打印
//	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
//			<< " 身高： " << it->m_Height << endl;
//	}
//
//	//排序
//	cout << "排序后的结果：" << endl;
//	l.sort(mycompare);
//	//打印
//	for (list<Person>::iterator it = l.begin(); it != l.end(); it++)
//	{
//		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
//			<< " 身高： " << it->m_Height << endl;
//	}
//
//
//	return 0;
//}