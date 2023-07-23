#include <iostream>
#include "Search1.h"
#include "Ex1.h"
using namespace std;
#define MAXV 10


void test1()
{
	RecType R[MAXV];
	for (int i = 0; i < MAXV; i++)
	{
		R[i].key = i;
		R[i].data = i + 65;
	}
	R[3].data = 'C'; R[4].data = 'C';
	int k = 8;
	char str = 'C';
	//int r=SeqSearch(R, MAXV,  k);  //顺序查找
	//int r = BinSearch1(R, MAXV, k);  //二分查找
	int r = BinSearch2(R, MAXV, str);
	if (r != -1)
	{
		cout << "元素位置为：" << r;
		cout << "，且元素值为：" << R[r - 1].data << endl;
	}
	else
		cout << "表中无该元素！" << endl;
}

void test2()
{
	RecType R[MAXV];
	IdxType* p;
	for (int i = 0; i < MAXV; i++)
	{
		R[i].key = i+1;
		R[i].data = i + 65;
	}
	int b = 4;
	//索引表建立
	p = IdxCons(R, MAXV, b);
	cout << "索引表为：";
	for (int i = 0; i < b; i++)
	{
		cout << "(" << p[i].key << "," << p[i].link << ") ";
	}
	cout << endl;
	//分块查找
	
	int k = 6;  //指定关键字
	int r=IdxSearch(p, R, MAXV, b, k);
	if (r != -1)
	{
		cout << "元素位置为：" << r;
		cout << "，且元素值为：" << R[r - 1].data << endl;
	}
	else
		cout << "表中无该元素！" << endl;
}

//实验测试
void test3()
{
	RecType R[MAXV];
	for (int i = 0; i < MAXV; i++)
	{
		R[i].key = i+1;
		R[i].data = i + 65;
	}
	R[4].key=R[5].key = R[6].key = R[3].key;
	for (int i = 0; i < MAXV; i++)
	{
		cout << "[" << R[i].key << "," << R[i].data << "]" << endl;
	}
	int key = 4;
	BinSearch_Ex(R, MAXV,key);

}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}