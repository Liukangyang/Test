#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

class Building
{
	friend void test1();  //全局函数作为友元
	friend class GoodGay;  //友元类
public:
	string Livingroom;

	Building()
	{
		Bedroom = "卧室";
		Livingroom = "客厅";
	}
private:
	string Bedroom;

};


//友元类
class GoodGay
{
public:
	Building *build;  //对象指针成员
	void visit()
	{
		cout << "好基友访问:" << build->Livingroom<<endl;
		cout << "好基友访问:" << build->Bedroom<<endl;
	}

	GoodGay()
	{
		build = new Building;
	}

};


//全局函数
void test1()
{
	Building p1;
	cout << p1.Bedroom << endl;   //声明为友元后即可访问私有成员

}

void test2()
{
	GoodGay goodgay;
	goodgay.visit();

}

//int main()
//{
//	test2();
//
//}