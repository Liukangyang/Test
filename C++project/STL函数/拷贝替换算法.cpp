#include <iostream>
#include<string>
#include<vector>
#include <deque>
#include<algorithm>
#include<functional>
#include <ctime>
using namespace std;
void print3(int val)
{
	cout << val << " ";
}

//拷贝
void test10()
{
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++)
		v1.push_back(i);

	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());
	for_each(v2.begin(), v2.end(), print3);//目标容器

	deque < int> q;
	q.resize(v1.size());
	copy(v1.begin(), v1.end(), q.begin());
	for_each(q.begin(), q.end(), print3);//目标容器
	//结果证明，不同类型的容器之间也可以相互拷贝

}

class Greater1000
{
public:
	bool operator()(int val)
	{	
		return val >= 1000;
	}
};
//替换
//replace // 将容器内指定范围的旧元素修改为新元素
//replace_if // 容器内指定范围满足条件的元素替换为新元素
void test11()
{
	//replace
	vector<int> v;
	v.push_back(2); v.push_back(1); v.push_back(2);
	v.push_back(3); v.push_back(4); v.push_back(2);
	cout << "替换前：";
	for_each(v.begin(), v.end(), print3);
	cout << "替换后：";
	replace(v.begin(), v.end(), 2, 1000);
	for_each(v.begin(), v.end(), print3);

	//replace_if
	replace_if(v.begin(), v.end(), Greater1000(), 2);
	cout << "条件替换后：";
	for_each(v.begin(), v.end(), print3);


}

//int main()
//{
//	test11();
//	return 0;
//}