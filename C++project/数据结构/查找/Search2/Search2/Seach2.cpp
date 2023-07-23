#include"Search2.h"

//二叉排序树的插入
BSTNode* InsertBSTNode(BSTNode* bt, int k)
{
	if (bt == NULL)
	{
		bt = new BSTNode;
		bt->key = k; bt->lchild = bt->rchild = NULL;
	}
	else if (k < bt->key)
	{
		bt->lchild = InsertBSTNode(bt->lchild, k);
	}
	else if (k > bt->key)
	{
		bt->rchild = InsertBSTNode(bt->rchild, k);
	}
	return bt;
}

//二叉排序树的创建
BSTNode* CreateBST(int a[], int n)
{
	BSTNode* bt = NULL;
	int i = 0;
	while (i < n)
	{
		bt = InsertBSTNode(bt, a[i]);
		i++;
	}
	return bt;
}

//二叉排序树的遍历（中序遍历）
void BST_Scan(BSTNode* bt)
{
	if (bt != NULL)
	{
		if(bt->lchild!=NULL)
			BST_Scan(bt->lchild);    //左子树
		cout << bt->key << " ";  //根结点
		if (bt->rchild != NULL)
			BST_Scan(bt->rchild);    //右子树
	}
}

//查找结点
BSTNode* SearchBST(BSTNode* bt, int k)
{
	//1.递归方法
	if (bt == NULL || bt->key == k)
		return bt;
	if (k < bt->key)
		return SearchBST(bt->lchild, k);
	else 
		return SearchBST(bt->rchild, k);
	//2.非递归方法
	/*
	BSTNode* p = bt;
	while (p != NULL)
	{
		if (p->key == k) break;
		else if (k < p->key) p = p->lchild;
		else p = p->rchild;
	}
	return p;
	*/
}

//删除结点
BSTNode* DeleteBST(BSTNode* bt, int k)
{
	if (bt == NULL) return bt;
	BSTNode* p = bt, *f = NULL;  //节点指针，双亲指针
	//查找待删除结点
	while (p != NULL)
	{
		if (p->key == k) break;
		f = p;
		if (k < p->key) p = p->lchild;
		else p = p->rchild;
	}
	if (p == NULL) return bt;   //未找到节点，直接返回

	//1.P为叶子节点
	if (p->lchild == NULL && p->rchild == NULL)
	{
		if (p == bt) bt=NULL;
		else  
		{
			if (f->lchild = p) f->lchild = NULL;
			else f->rchild = NULL;
		}
		free(p);
	}
	//2.P含有单一非空子树
	else if (p->rchild == NULL)   //只含有左子树
	{
		if (f == NULL) bt = bt->lchild;
		else
		{
			if (f->lchild = p) f->lchild = p->lchild;
			else f->rchild = p->lchild;
		}
		free(p);
	}
	else if (p->lchild == NULL) //只含有右子树
	{
		if (f == NULL) bt = bt->rchild;
		else
		{
			if (f->lchild = p) f->lchild = p->rchild;
			else f->rchild = p->rchild;
		}
		free(p);
	}
	//3.P含有两个非空子树
	else
	{
		BSTNode* q = p->lchild;
		while (q->rchild != NULL)
		{
			f = q;
			q = q->rchild;
		}
		//
		p->key = q->key;
		p->data = q->data;
		if (f->lchild = q) f->lchild = q->lchild;
		else f->rchild = q->lchild;
		free(q);  //等效删除q
	}
	return bt;
}

