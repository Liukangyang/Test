#include "Hash1.h"
#include "Hash2.h"

//开放地址法构建哈希表
void test1()
{
	int keys[] = {16,74,60,43,54,90,46,31,29,88,77};
	int total = sizeof(keys) / sizeof(int);
	HashTable ha;
	CreateHT(ha, keys, total);
	cout << "输出哈希表：" << endl;
	PrintHash(ha);
	int key = 40;
	/*
	if (DeleteHT(ha, key))
	{
		cout << "删除后的哈希表为：" << endl;
		PrintHash(ha);
	}
	else
		cout << "哈希表中不存在该关键字！" << endl;*/
	SearchHT(ha, key);
}

//拉链法构建哈希表
void test2()
{
	int keys[] = { 16,74,60,43,54,90,46,31,29,88,77 };
	int total = sizeof(keys) / sizeof(int);
	HashTable2 ha;
	CreateHT(ha, keys, total);
	cout << "输出哈希表：" << endl;
	PrintHash(ha);
	int key = 90;
	/*
	if (DeleteHT(ha, key))
	{
		cout << "删除后的哈希表为：" << endl;
		PrintHash(ha);
	}
	else
		cout << "哈希表中不存在该关键字！" << endl;*/
	SearchHT(ha, key);
}


int main()
{
	//test1();
	test2();
	return 0;
}