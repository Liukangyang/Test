#include "BTree.h"

typedef struct node{
	char data;
	int ltag, rtag;
	struct node* lchild;
	struct node* rchild;
}TBTNode;

extern TBTNode* pre;
//求二叉树b中节点值为x的节点的层次（深度）
int Level(BTNode* b, char x, int h=1);

//2.设计算法求二叉树b中节点值为x的节点的所有祖先
bool Ancestor(BTNode* b, char x);

//线索化递归(先序顺序)
void Thread(TBTNode*& p);

//线索化二叉树
TBTNode* CreateThread(TBTNode*& b);

//遍历线索二叉树
void ThPreOrder(TBTNode*& root);

//初始化线索二叉树
void CreateTBTree(TBTNode*& b, string str);

