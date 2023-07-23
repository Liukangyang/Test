#pragma once
#include<iostream>
using namespace std;
#define NULLKEY -1
#define M 13

//单链表定义
typedef struct node{
	int key;      //关键字
	char data;    //数据域
	node* next;   //指向下一个同义词
}NodeType;

//哈希单元定义
typedef struct hashnode2 {
	NodeType* first;    //头结点指针
}HashNode2;

//哈希表定义
typedef struct hashtable2 {
	HashNode2 hashtable[M];   //哈希表（头结点指针数组）
	int n;                   //统计元素个数
	float alpha;             //填充因子
}HashTable2;

//插入元素
void InsertHT(HashTable2& ha, int key);
//创建哈希表
void CreateHT(HashTable2& ha, int keys[], int total);
//删除元素
bool DeleteHT(HashTable2& ha, int key);
//查找元素
void SearchHT(HashTable2& ha, int key);
//输出哈希表
void PrintHash(HashTable2& ha);

