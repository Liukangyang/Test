#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct hero
{
	string name;
	int age;
	string sex;
};
void bubbleSort(hero arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j].age > arr[j + 1].age)
			{
				hero h;
				h = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = h;
			}

		}
	}

}

//打印数组
void printHeros(hero arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "姓名： " << arr[i].name << " 性别： " << arr[i].sex << " 年龄： " << arr[i].age << endl;
	}
}

void printHeros2(vector<hero> hh)
{	
	for (vector<hero>::iterator it = hh.begin(); it != hh.end(); it++)
	{	
		cout << "姓名： " << it->name << " 性别： " << it->sex << " 年龄： " << it->age << endl;

	}
}

class mycompare
{
public:
	bool operator()(hero h1,hero h2)
	{	
		return h1.age < h2.age;//升序排序
	}
};

int main()
{
	//1.创建结构体数组
	//2.结构体赋值
	struct hero h[] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"},
	};

	vector<hero> hh;
	int len = sizeof(h) / sizeof(h[0]);//len=5
	for (int i = 0; i < len; i++)
	{
		hh.push_back(h[i]);
	}
	//3.排序
	cout << "排序前：" << endl;
	printHeros2(hh);
	
	//bubbleSort(h, len);
	sort(hh.begin(),hh.end(),mycompare());
	cout << "排序后" << endl;
	printHeros2(hh);
	//实验证明，将结构体存储在容器里，然后利用sort算法，结合仿函数也可以实现排序

	//4.打印
	return 0;
}