#include<iostream>
#include<string>
#include <map>
using namespace std;

//template<class T1,class T2>
void printMap4(map<int, int>& m)
{

	for (map<int, int >::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "¼ü£º" << it->first << " Öµ£º" << it->second << endl;
	}
	cout << endl;
}




class mycompare
{
public:
	bool operator()(int v1, int v2)const
	{
		return v1 > v2;   //½µĞòÅÅĞò
	}
};

void test41()
{
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	printMap4(m);//Ä¬ÈÏÉıĞòÅÅĞò

	//½µĞòÅÅĞò
	map<int, int, mycompare> m2;
	m2.insert(make_pair(2, 20));
	m2.insert(make_pair(1, 10));
	m2.insert(make_pair(3, 30));
	for (map<int, int,mycompare>::iterator it = m2.begin(); it != m2.end(); it++)
	{
		cout << "¼ü£º" << it->first << " Öµ£º" << it->second << endl;
	}
	cout << endl;



}

//int main()
//{
//	test41();
//	return 0;
//}