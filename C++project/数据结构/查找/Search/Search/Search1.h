#pragma once
#include <iostream>
using namespace std;

//线性表定义
typedef struct {
	int key;    //关键字
	char data;  //元素值
}RecType;

//索引表定义
typedef struct {
	int key;   //关键字
	int link;  //相对地址
}IdxType;

//顺序查找
int SeqSearch(RecType R[], int n, int k);
//折半查找
int BinSearch1(RecType R[], int n, int k);
//折半查找2
int BinSearch2(RecType R[], int n, char str);
//分块查找
int IdxSearch(IdxType *I, RecType R[], int n, int b, int k);
//建立索引表
IdxType* IdxCons(RecType R[], int n, int b);

