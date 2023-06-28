#include<iostream>
#include<string>
#include <set>
using namespace std;

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test31()
{
	set<int> s;
	//插入insert
	s.insert(40); s.insert(20); s.insert(50);
	printSet(s);

	//拷贝构造
	set<int> s2(s);
	printSet(s2);

	//=
	set<int> s3;
	s3 = s;
	printSet(s3);
}

//插入删除
void test32()
{
	set<int> s;
	s.insert(30); s.insert(10); s.insert(40); s.insert(20);
	printSet(s);

	//删除
	s.erase(s.begin());
	printSet(s);

	s.erase(30);
	printSet(s);

	s.clear();
	printSet(s);
	cout << "容器大小为：" << s.size() << endl;

}

//int main()
//{
//	test32();
//	return 0;
//}