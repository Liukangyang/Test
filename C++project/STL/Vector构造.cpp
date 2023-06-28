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

//构造函数
void test11()
{
	//1.默认构造
	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	printVector(v1);

	//2.vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//3.vector(n, elem); //构造函数将n个elem拷贝给本身。
	vector<int> v3(10, 20);
	printVector(v3);

	//4.vector(const vector &vec); //拷贝构造函数
	vector <int>v4(v3);
	printVector(v4);


}

//赋值操作
//vector& operator=(const vector& vec);//重载等号操作符
//assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem); //将n个elem拷贝赋值给本身。
void test12()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);
	//printVector(v1);

	//1
	vector<int> v2;
	v2 = v1;
	printVector(v2);

	//2
	vector<int> v3;
	v3.assign(v1.begin(),v1.end());
	printVector(v3);

	//3
	vector<int> v4;
	v4.assign(10, 6);
	printVector(v4);


}

//int main()
//{
//	test12();
//	return 0;
//}