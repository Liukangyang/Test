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

//插入与删除
//push_back(ele); //尾部插入元素ele
//pop_back(); //删除最后一个元素
//insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
//insert(const_iterator pos, int count, ele);//迭代器指向位置pos插入count个元素ele
//erase(const_iterator pos); //删除迭代器指向的元素
//erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
//clear(); //删除容器中所有元素
void test14()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	printVector(v);
	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;

	v.pop_back();
	printVector(v);
	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;

	//insert
	v.insert(v.begin() + 1, 100);
	printVector(v);
	v.insert(v.begin(), 2, 1000);
	printVector(v);

	//erase
	v.erase(v.end()-1);//删除最后一个元素
	printVector(v);

	v.clear();//删除所有元素
	printVector(v);
	cout << "容量为：" << v.capacity() << endl;
	cout << "大小为：" << v.size() << endl;

}

//存取
//at(int idx); //返回索引idx所指的数据
//operator[]; //返回索引idx所指的数据
//front(); //返回容器中第一个数据元素--> *(v1.begin())
//back(); //返回容器中最后一个数据元素--->*(v1.end()-1)
void test15()
{	
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	//1.[]
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	//2.at()
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
	//front()
	cout << "首元素为：" << v.front() << endl;;

	//back()
	cout << "尾元素为：" << v.back() << endl;;

}
//int main()
//{
//	test15();
//	return 0;
//}