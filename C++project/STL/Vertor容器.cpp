#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;


void MyPrint(int val)
{
	cout << val << endl;
}


//1.基本使用
void test1()
{
	//创建vector容器
	vector<int> v1;
	v1.push_back(10);	v1.push_back(20);	v1.push_back(30);
	v1.push_back(40);

	//访问元素
	//1.for循环
	vector<int>::iterator i_Begin = v1.begin();
	vector<int>::iterator i_End = v1.end();

	for (; i_Begin != i_End; i_Begin++)
	{
		cout << *i_Begin << endl;
	}

	//2.使用STL提供的标准遍历算法
	for_each(i_Begin, i_End, MyPrint);
}


//2.容器嵌套容器
void test2()
{
	vector<vector<int>> v;

	vector<int> v1, v2, v3, v4;
	
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 1);//1,2,3,4,5
		v2.push_back(i + 2);//2,3,4,5,6
		v3.push_back(i + 3);//3,4,5,6,7
		v4.push_back(i + 4);//4,5,6,7,8
	}

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//遍历
	for (vector<vector<int>>::iterator it=v.begin(); it!=v.end(); it++)
	{
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;

	}


}
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}