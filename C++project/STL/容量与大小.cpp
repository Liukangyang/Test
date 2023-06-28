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

//容量与大小操作
//empty(); //判断容器是否为空
//capacity(); //容器的容量
//size(); //返回容器中元素的个数
//resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值（0）填充新位置。
//​ //如果容器变短，则末尾超出容器长度的元素被删除。
//resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
void test13()
{
	vector<int> v1;
	cout << "初始容量:" << v1.capacity() << endl;
	cout << v1.empty() << endl;//初始时为空

	for (int i = 0; i < 10; i++)
		v1.push_back(i);

	if (v1.empty())
		cout << "容器为空" << endl;
	else
	{
		cout << "容器不为空" << endl;
		cout << "容量为：" << v1.capacity() << endl;
		cout << "大小为：" << v1.size() << endl;
	}

	//重新指定大小
	v1.resize(15);

	cout << "容量为：" << v1.capacity() << endl;
	cout << "大小为：" << v1.size() << endl;
	printVector(v1);
	v1.push_back(100);
	cout << "容量为：" << v1.capacity() << endl;
	printVector(v1);//

	v1.resize(6);
	cout << "容量为：" << v1.capacity() << endl;
	cout << "大小为：" << v1.size() << endl;
	printVector(v1);  //大小减小了，容量不变
}
//int main()
//{
//	test13();
//	return 0;
//}