#pragma once
#include "MyArray.hpp"

//自定义类
class Person
{
public:
	Person()
	{}

	Person(string name,int age)
	{
		m_Name = name;
		m_Age = age;
	}

	string m_Name;
	int m_Age;


};


void test06()
{
	MyArray<> arr1(10);//默认int
	for (int i = 1; i <= 11; i++)
	{
		arr1.Push_Back(i);  //插入数据
	}

	arr1.Get_allelement();
	arr1.Get_CapacityandSize();//获取容量和当前大小
	

	arr1.Pop_Back();//删除元素
	arr1.Get_allelement();
	arr1.Get_CapacityandSize();//获取容量和当前大小


	arr1.Push_Back(100);//添加元素
	arr1.Get_allelement();
	arr1.Get_CapacityandSize();//获取容量和当前大小

}

void test07()
{
	Person p1("LKY",23);
	Person p2("YY", 23);
	Person p3("孙悟空", 5000);
	Person p4("猪八戒", 1000);

	MyArray<Person> arr(10);
	arr.Push_Back(p1); arr.Push_Back(p2);
	arr.Push_Back(p3); arr.Push_Back(p4);
	
	cout << "----------------------------------------" << endl;
	cout << "当前数组内容为：" << endl;
	for (int i = 0; i < arr.Ger_Size(); i++)
	{
		cout << "姓名:" << arr[i].m_Name << " 年龄:" << arr[i].m_Age << endl;

	}
	cout << "----------------------------------------" << endl;
	arr.Get_CapacityandSize();


	arr.Pop_Back();
	cout << "----------------------------------------" << endl;
	cout << "当前数组内容为：" << endl;
	for (int i = 0; i < arr.Ger_Size(); i++)
	{
		cout << "姓名:" << arr[i].m_Name << " 年龄:" << arr[i].m_Age << endl;

	}
	cout << "----------------------------------------" << endl;
	arr.Get_CapacityandSize();


}

int main()
{
	test07();

	//MyArray<> arr2(arr1);  //拷贝构造
	//MyArray<> arr3(100);
	//arr3 = arr1;  //重载
	return 0;

}


