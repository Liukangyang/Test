#pragma once
#include<iostream>
#include<string>
#include<deque>
using namespace std;
#define MAXSIZE 20

//二叉树结点类型
typedef struct btreenode {
	char data;			 //数据域
	struct btreenode* lchild; //指向左孩子结点
	struct btreenode* rchild; //指向右孩子结点
}BTNode;

/*
* 二叉树基本运算
*/
//1、创建二叉树
void CreateBTree(BTNode*& b, string str);

//2.销毁二叉树
void DestoryBTree(BTNode*& b);


//3.查找结点
BTNode* FindNode(BTNode* b, char c);

//4.求高度
int BTreeHeight(BTNode* b);

//5.输出二叉树
void DispBTree(BTNode* b);

//6.求孩子结点
void ChildNode(BTNode* b, char c);

//7.求双亲结点
BTNode* ParentNode(BTNode* b,BTNode* p);


//遍历算法
//8.先序遍历
void PreOrder(BTNode* b);
//9.中序遍历
void InOrder(BTNode* b);
//10.后序遍历
void PostOrder(BTNode* b);
//11.层次遍历1
void LevelOrder1(BTNode* b);
//12.层次遍历2
void LevelOrder2(BTNode* b);