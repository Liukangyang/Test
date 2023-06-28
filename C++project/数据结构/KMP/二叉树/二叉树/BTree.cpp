#include<iostream>
#include<string>
#include "BTree.h"
using namespace std;

/*
* 二叉树基本运算
*/
//1、创建二叉树
void CreateBTree(BTNode*& b, string str) {
	BTNode* St[MAXSIZE];
	BTNode* p = NULL;
	int top = -1;
	int k = 0,i = 0;
	char ch;
	b = NULL;
	
	for (i = 0; i<int(str.length()) && str[i]!='\0'; i++)
	{
		ch = str[i];
		switch (ch)
		{
		case '(':
			top++; St[top] = p; k = 1;
			break;

		case')':
			top--;
			break;

		case ',':
			k = 2;
			break;

		default:
			p = new BTNode;
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL)
				b = p;
			else
			{ 
				if (k == 1)
					St[top]->lchild = p;
				else if(k==2)
					St[top]->rchild = p;
			}
			break;
			
		}

	}

}


//2.销毁二叉树(递归)
void DestoryBTree(BTNode*& b) {
	if (b != NULL)
	{
		DestoryBTree(b->lchild);  //删除左子树
		DestoryBTree(b->rchild);  //删除右子树
		free(b);  //删除根结点
		b = NULL;
	}
}


//3.查找结点(递归)
BTNode* FindNode(BTNode* b, char c) {
	BTNode* p = NULL;
	if (b == NULL) return NULL;
	if (b->data == c) return b;
	else
	{
		p = FindNode(b->lchild,c);
		if (p != NULL) return p;
		else
			return FindNode(b->rchild, c);
	}
 
	return NULL;
}

//4.求高度(递归)
int BTreeHeight(BTNode* b) {
	int lheight = 0, rheight = 0;
	if (b == NULL) return 0;
	else
	{
		lheight = BTreeHeight(b->lchild);
		rheight = BTreeHeight(b->rchild);
		return lheight > rheight ? lheight + 1 : rheight + 1;
	}
	return -1;
}

//5.输出二叉树(递归)
void DispBTree(BTNode* b) {
	if (b != NULL)
	{
		cout << b->data;
		if (b->lchild != NULL || b->rchild != NULL)
		{
			cout << "(";
			DispBTree(b->lchild);
			if (b->rchild != NULL) cout << ",";
			DispBTree(b->rchild);
			cout << ")";
		}

	}
}


//6.求孩子结点
void ChildNode(BTNode* b, char c) {
	BTNode* p = FindNode(b, c);
	if (p != NULL)
	{
		if(p->lchild!=NULL)
			cout << "左孩子节点元素为:" << p->lchild->data << endl;
		if(p->rchild!=NULL)
		cout << "右孩子节点元素为:" << p->rchild->data << endl;
	}
	else
	{
		cout << "在二叉树中不存在该元素!" << endl;
	}

}

//7.求双亲结点(递归)
BTNode* ParentNode(BTNode* b, BTNode* p){
	BTNode* t=NULL;
	if (p == NULL) return NULL;

	if (b != NULL)
	{
		if (b->lchild == p || b->rchild == p) return b;
		else
		{
			t = ParentNode(b->lchild, p);
			if (t != NULL) return t;
			else
				return  ParentNode(b->rchild, p);
		}
	}
	else return NULL;
}

//8.先序遍历
void PreOrder(BTNode* b) {
	if (b != NULL)
	{
		cout << b->data << " ";
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
//9.中序遍历
void InOrder(BTNode* b) {
	if (b != NULL)
	{
		InOrder(b->lchild);
		cout << b->data << " ";
		InOrder(b->rchild);
	}
}
//10.后序遍历
void PostOrder(BTNode* b) {
	if (b != NULL)
	{
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		cout << b->data << " ";
	}
}
//11.层次遍历1
void LevelOrder1(BTNode* b) {
	if (b == NULL) cout << "二叉树不存在" << endl;
	else
	{
		deque<BTNode*> Sq;
		BTNode* p = NULL;
		Sq.push_back(b);
		while (!Sq.empty())
		{
			p = Sq.front();  //获取队头结点
			cout << p->data << " ";   //访问
			Sq.pop_front();    //将已访问结点从队头删除
			if (p->lchild != NULL)
				Sq.push_back(p->lchild);   //加入左孩子结点
			if (p->rchild != NULL)
				Sq.push_back(p->rchild);  //加入右孩子结点
		}
		cout << endl;
		p = NULL;
	}
}

//12.层次遍历2
void LevelOrder2(BTNode* b) {
	if (b == NULL) cout << "二叉树不存在" << endl;
	else
	{
		int cnt = 0;  //当前层次节点数
		int cul = 1;  //当前层次
		deque<BTNode*> Sq;
		BTNode* p = NULL;
		Sq.push_back(b);
		while (!Sq.empty())
		{
			printf("第%d层：", cul);
			cnt = Sq.size();
			for (int i = 0; i < cnt; i++)
			{
				p = Sq.front();  //获取队头结点
				cout << p->data << " ";   //访问
				Sq.pop_front();    //将已访问结点从队头删除
				if (p->lchild != NULL)
					Sq.push_back(p->lchild);   //加入左孩子结点
				if (p->rchild != NULL)
					Sq.push_back(p->rchild);  //加入右孩子结点
			}
			cout << endl;
			cul++;
		}
		cout << endl;
		p = NULL;
	}
}








