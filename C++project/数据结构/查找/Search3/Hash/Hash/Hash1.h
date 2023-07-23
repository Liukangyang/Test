#pragma once
#include<iostream>
using namespace std;
#define NULLKEY -1
#define M 13

//哈希单元定义
typedef struct hashnode {
	int key;   //关键字
	int count; //记录匹配次数
	char data;  //数据域
}HashNode;

//哈希表定义
typedef struct hashtable {
	HashNode hashtable[M];   //哈希表
	int n;                   //统计元素个数
	float alpha;             //填充因子
}HashTable;

//插入元素
void InsertHT(HashTable& ha, int key);
//创建哈希表
void CreateHT(HashTable& ha, int keys[], int total);
//删除哈希表
bool DeleteHT(HashTable& ha, int key);
//查找元素
void SearchHT(HashTable& ha, int key);
//输出哈希表
void PrintHash(HashTable& ha);




