#pragma once
#include<iostream>
#include<string>
using namespace std;

//二叉排序树定义
typedef struct node2 {
	char c;                         //字符（关键字）
	int count;				         //出现次数（数据域）
	struct node2* lchild, * rchild;   //指针域
}BSTNode2;

//统计字符个数
int* Count_Char(string str, char* alphabet);
//二叉排序树的插入
BSTNode2* InsertBSTNode2(BSTNode2* bt, int* count, char k);
// 二叉排序树的创建
BSTNode2* CreateBST(char* alphabet, int* count, int n);
//二叉排序树的遍历（中序遍历）
void BST_Scan(BSTNode2* bt);
