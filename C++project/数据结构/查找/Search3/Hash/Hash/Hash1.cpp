#include"Hash1.h"

//基于除余哈希函数和“线性探测法”
//1.插入元素
void InsertHT(HashTable& ha, int key)
{
	int i;
	int k = 1, p = 1;
	int adr, cnt;
	//计算P：小于等于m的最大素数
	while (k <= M)
	{
		for (i = 2; i < k; i++)
		{
			if (k % i == 0) break;
		}
		if (i == k) p = k;
		k++;
	}

	 adr = key % p;   //除余法哈希函数
	if (ha.hashtable[adr].key == NULLKEY)    //无冲突
	{
		ha.hashtable[adr].key = key;
		ha.hashtable[adr].count = 1;
	}
	else								//发生冲突
	{
		cnt = 1;
		while (ha.hashtable[adr].key != NULLKEY) // 线性探测法解决冲突
		{
			adr = (adr + 1) % M;  
			cnt++;
		}
		ha.hashtable[adr].key = key;
		ha.hashtable[adr].count = cnt;
	}
	ha.n++;
}

//2.创建哈希表
void CreateHT(HashTable& ha, int keys[], int total)
{
	//初始化哈希表
	for (int i = 0; i < M; i++)
	{
		ha.hashtable[i].count = 0;
		ha.hashtable[i].key = NULLKEY;
	}
	ha.n = 0;
	ha.alpha = 0;

	//循环插入建表
	for (int i = 0; i < total; i++)
	{
		InsertHT(ha, keys[i]);
	}
	ha.alpha = float(ha.n) / M;
}

//3.删除元素
bool DeleteHT(HashTable &ha,int key)
{
	//计算P：小于等于m的最大素数
	int k = 1, i,p;
	while (k <= M)
	{
		for (i = 2; i < k; i++)
		{
			if (k % i == 0) break;
		}
		if (i == k) p = k;
		k++;
	}
	int adr = key % p;

	while (ha.hashtable[adr].key != NULLKEY && ha.hashtable[adr].key != key)
	{
		adr = (adr + 1) % M;   //线性探测
	}
	if (ha.hashtable[adr].key == key)  //找到指定关键字元素
	{
		int j = (adr + 1) % M;
		//将后继连续的同义词往前移动一个单元
		while (ha.hashtable[j].key != NULLKEY && ha.hashtable[j].key % p == key % p)
		{
			ha.hashtable[(j - 1 ) % M].key = ha.hashtable[j].key;
			ha.hashtable[(j - 1 ) % M].count = ha.hashtable[j].count;
			j = (j + 1) % M;
		}
		ha.hashtable[(j - 1 ) % M].key = NULLKEY;
		ha.hashtable[(j - 1 ) % M].count = 0;
		ha.n--;
		ha.alpha = float(ha.n) / M;
		return true;
	}
	else 
		return false;
}

//4. 查找元素
void SearchHT(HashTable& ha, int key)
{
	//计算P：小于等于m的最大素数
	int k = 1, i, p;
	int cnt = 1;
	while (k <= M)
	{
		for (i = 2; i < k; i++)
		{
			if (k % i == 0) break;
		}
		if (i == k) p = k;
		k++;
	}
	int adr = key % p;   //哈希函数

	while (ha.hashtable[adr].key != NULLKEY && ha.hashtable[adr].key != key)    //线性探测查找
	{
		cnt++;
		adr = (adr + 1) % M;
	}
	if (ha.hashtable[adr].key == key)
	{
		cout << "成功找到关键字对应该元素：[" << ha.hashtable[adr].key << "," << ha.hashtable[adr].count << "]" 
			<< "，查找次数为" << cnt<<endl;
	}
	else
		cout << "未找到该关键字对应元素" << "，查找次数为" << cnt << endl;
}

//5.输出哈希表
void PrintHash(HashTable& ha)
{
	for (int i = 0; i < M; i++)
	{
		cout << "[" << ha.hashtable[i].key << "：" << ha.hashtable[i].count << "]" << endl;
	}
}




