#pragma once
#include<iostream>
using namespace std;

//二叉排序树定义
typedef struct node {
	int key;                         //关键字
	char data;				         //数据域
	struct node* lchild, * rchild;   //指针域

}BSTNode;


//二叉排序树的插入
BSTNode* InsertBSTNode(BSTNode* bt, int k);
//二叉排序树的创建
BSTNode* CreateBST(int a[], int n);
//二叉排序树的遍历（中序遍历）
void BST_Scan(BSTNode* bt);
//查找结点
BSTNode* SearchBST(BSTNode* bt, int k);
//删除结点
BSTNode* DeleteBST(BSTNode* bt, int k);
