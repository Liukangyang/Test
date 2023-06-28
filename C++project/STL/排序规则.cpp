#include<iostream>
#include<string>
#include <set>
using namespace std;

class Mycompare
{
public:
	bool operator()(int v1,int v2)const//注意，VS编译器对此进行了更新，需在仿函数后加入const关键字
	{ 
		return v1 > v2;//降序
	}
};
void test36()
{
	
	set<int> s;
	s.insert(20); s.insert(10); s.insert(40); s.insert(30);
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//实现降序排序
	set<int, Mycompare> s2;
	s2.insert(20); s2.insert(10); s2.insert(40); s2.insert(30);
	for (set<int,Mycompare>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//int main()
//{
//	test36();
//	return 0;
//}