#include<iostream>
#include<string>
#include <map>
using namespace std;

//template<class T1,class T2>
void printMap2(map<string, int>& m)
{

	for (map<string, int >::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "键：" << it->first << " 值：" << it->second << endl;
	}
	cout << endl;
}


void test38()
{
	//插入
	map<string, int> m;
	//1.
	m.insert(pair<string, int>("LKY", 10));
	//2.
	m.insert(make_pair("YY", 20));//推荐该方式
	//3.
	m.insert(map<string, int>::value_type("ZHANGSAN", 30));
	//4.'[]'+'='
	m["LISI"] = 50;
	printMap2(m);
	cout << m["孙悟空"] << endl;//默认值是0
	printMap2(m);

	//删除
	//1
	m.erase(m.begin());
	printMap2(m);

	//2传入键值
	m.erase("孙悟空");
	printMap2(m);
	//3
	m.clear();
	printMap2(m);

}
//int main()
//{
//	test38();
//	return 0;
//}