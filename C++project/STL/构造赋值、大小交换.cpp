#include<iostream>
#include<string>
#include <map>
using namespace std;

void printMap(map<int,int> &m)
{
	
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "健：" << it->first << " 值：" << it->second << endl;
	}
	cout << endl;
}


void test37()
{
	//构造
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));//匿名对组赋值
	m.insert(pair<int, int>(4, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 40));

	//遍历
	printMap(m);

	//赋值
	map<int, int> m2;
	m2 = m;
	printMap(m2);

}
//int main()
//{
//	test37();
//	return 0;
//}