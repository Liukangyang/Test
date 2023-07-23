#include "Hash2.h"
//基于除余哈希函数和“拉链法”
//1.插入元素
void InsertHT(HashTable2& ha, int key)
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
	
	NodeType* q=new NodeType;
	q->key = key;
	q->next = NULL;
	if (ha.hashtable[adr].first == NULL)
		ha.hashtable[adr].first = q;
	else
	{
		//头插法
		q->next = ha.hashtable[adr].first;
		ha.hashtable[adr].first = q;      //作为新的头结点
	}
	ha.n++;
}

//2.创建哈希表
void CreateHT(HashTable2& ha, int keys[], int total)
{
	for (int i = 0; i < M; i++)
	{
		ha.hashtable[i].first = NULL;   //初始化每个指针
	}
	for (int j = 0; j < total; j++)
	{
		InsertHT(ha, keys[j]);         //循环插入关键字序列
	}
	ha.alpha = float(ha.n) / M;
}

//3. 删除元素
bool DeleteHT(HashTable2& ha, int key)
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
	NodeType* q, * preq;
	q = ha.hashtable[adr].first;    //单链表第一个同义词结点
	if (q == NULL) return false;
	if (q->key == key)   //先判断头结点
	{
		ha.hashtable[adr].first = q->next;
		free(q);
		ha.n--;
		ha.alpha = float(ha.n) / M;
		return true;
	}

	//判断单链表的其余节点
	preq = q; q = q->next;
	while (q != NULL)
	{
		if (q->key == key) break;
		preq = q;
		q = q->next;
	}
	if (q != NULL)
	{
		preq->next = q->next;
		free(q);
		ha.n--;
		ha.alpha = float(ha.n) / M;
		return true;
	}
	else
		return false;
}

//4.查找元素
void SearchHT(HashTable2& ha, int key)
{
	int cnt = 0,adr;
	int i;
	int k = 1, p = 1;
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
	NodeType* q;
	q = ha.hashtable[adr].first;
	while (q != NULL)
	{
		cnt++;
		if (q->key == key) break;
		q = q->next;
	}
	if (q != NULL)
		cout << "成功找到关键字对应元素:" << q->key <<"，且查找次数为："<<cnt << endl;
	else
		cout << "不存在该关键字对应元素" << "，且查找次数为：" << cnt << endl;
}

//5.输出哈希表
void PrintHash(HashTable2& ha)
{
	NodeType* q;
	for (int i = 0; i < M; i++)
	{
		q = ha.hashtable[i].first;
		cout << "->[";
		while (q != NULL)      
		{
			cout << q->key << ",";
			q = q->next;
		}
		cout << "]" << endl;
	}
}
