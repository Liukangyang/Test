#include<iostream>
#include<string>
#include<vector>
using namespace std;
//打印函数
template<class T>
void printVector(vector<T>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//互换容器
void test16()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	for (int i = 10; i > 6; i--)
	{
		v2.push_back(i);
	}
	cout << "互换前" << endl;
	printVector(v1);
	printVector(v2);
	cout << "v1容量" << v1.capacity() << endl;
	cout << "v1大小" << v1.size() << endl;

	cout << "互换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
	cout << "v1容量" << v1.capacity() << endl;
	cout << "v1大小" << v1.size() << endl;

	cout << "v2容量" << v2.capacity() << endl;

	//收缩空间
	vector<int>v3;
	for (int i = 0; i < 10000; i++)
	{
		v3.push_back(i);
	}
	cout << "v3容量" << v3.capacity() << endl;
	cout << "v3大小" << v3.size() << endl;

	v3.resize(6);
	cout << "v3容量" << v3.capacity() << endl;
	cout << "v3大小" << v3.size() << endl;

	vector<int>(v3).swap(v3);  //匿名对象和v3的数组空间互换
	cout << "v3容量" << v3.capacity() << endl;
	cout << "v3大小" << v3.size() << endl;
}

//预留空间reserve()
void test17()
{
	//动态拓展
	vector<int> v;
	int count = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}
	
	}
	cout << "拓展空间次数:" << count << endl;
	cout << "容器容量" << v.capacity() << endl;

	//预留空间
	vector<int> v2;
	v2.reserve(10000);
	count = 0; p = NULL;
	for (int i = 0; i < 9999; i++)
	{
		v2.push_back(i);
		if (p != &v2[0])
		{
			p = &v2[0];
			count++;
		}

	}
	cout << "拓展空间次数:" << count << endl;
	cout << "容器容量" << v2.capacity() << endl;//只有当大小超过预留容量时，才会重新进行动态拓展

}

//int main()
//{
//	test17();
//	return 0;
//}