#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//for_each //遍历容器
//transform //搬运容器到另一个容器中
//普通函数
void printVector(int v)
{	
	cout << v << " ";
}

//仿函数
class Transform
{
public:
	int operator()(int v)
	{
		return v+100;
	}
};
//int main()
//{	
//	vector<int> v;
//	for (int i = 0; i < 10; i++)
//		v.push_back(i);
//
//	//遍历
//	cout << "源容器内容:";
//	for_each(v.begin(), v.end(), printVector);
//	cout << endl;
//
//	//遍历+搬运
//	vector<int> Destv;
//	Destv.resize(v.size());
//	transform(v.begin(), v.end(), Destv.begin(), Transform());
//	cout << "目标容器内容:";
//	for_each(Destv.begin(), Destv.end(), printVector);
//	cout << endl;
//
//	return 0;
//}