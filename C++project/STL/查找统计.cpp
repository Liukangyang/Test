#include<iostream>
#include<string>
#include <map>
using namespace std;

//template<class T1,class T2>
void printMap3(map<int, int>& m)
{

	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "键：" << it->first << " 值：" << it->second << endl;
	}
	cout << endl;
}



void test40()
{
	map<int, int> m;
	m.insert(make_pair(1, 10));//只有第一次可以插入
	m.insert(make_pair(1, 20));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	printMap3(m);
	//查找
	map<int, int>::iterator it = m.find(3);
	if (it == m.end())
		cout << "未找到该元素" << endl;
	else
		cout << "找到该元素，其值为：" << it->second << endl;

	//统计
	int num = m.count(4);
	cout << "元素数量为：" << num << endl;
}
//int main()
//{
//	test40();
//	return 0;
//}