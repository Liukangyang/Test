#include <iostream>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

void myprint(int val)
{
	cout << val << " ";
}
//set_intersection // 求两个容器的交集
//set_union // 求两个容器的并集
//set_difference // 求两个容器的差集
int main()
{
	vector<int> v1, v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);//0~9
		v2.push_back(i + 5);//5~14
	}
	vector<int> vDest;
	//求交集
	//开辟空间
	cout << "交集：";
	vDest.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vDest.begin());
	for_each(vDest.begin(), itEnd, myprint);//利用算法返回的迭代器，可以实现只遍历到所求集合的最后一个元素
	cout << endl;

	//求并集
	fill(vDest.begin(), vDest.end(), 0);
	//for_each(vDest.begin(), vDest.end(), myprint); 
	vDest.resize(v1.size()+v2.size());

	cout << "并集：";
	itEnd=set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vDest.begin());
	for_each(vDest.begin(), itEnd, myprint);
	cout << endl;

	//求差集
	fill(vDest.begin(), vDest.end(), 0);
	//for_each(vDest.begin(), vDest.end(), myprint); 
	vDest.resize(max(v1.size(),v2.size()));
	cout << "v1-v2:";
	itEnd = set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vDest.begin());
	for_each(vDest.begin(), itEnd, myprint);
	cout << endl;

	cout << "v2-v1:";
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vDest.begin());
	for_each(vDest.begin(), itEnd, myprint);
	cout << endl;



	return 0;
}