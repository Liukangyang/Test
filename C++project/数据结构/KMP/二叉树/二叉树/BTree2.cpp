#include"BTree2.h"
TBTNode* pre;

//求二叉树b中节点值为x的节点的层次（深度）
int Level(BTNode* b, char x, int h)
{
	int depth = 0;
	if (b == NULL) return 0;
	if (b->data == x) return h;
	else
	{
		depth = Level(b->lchild, x, h + 1);//左子树递归
		if (depth != 0)
			return depth;
		else
			return Level(b->rchild, x, h + 1);//右子树递归
	}
}

//2.设计算法求二叉树b中节点值为x的节点的所有祖先
bool Ancestor(BTNode* b, char x)
{
	if (b == NULL) return false;
	if ( (b->lchild!=NULL && b->lchild->data == x) || (b->rchild!=NULL && b->rchild->data == x))
	{
		cout << b->data;
		return true;
	}
	else if (Ancestor(b->lchild, x) || Ancestor(b->rchild, x))
	{
		cout << b->data;
		return true;
	}
	else return false;
}

//线索化递归(中序顺序)
void Thread(TBTNode * &p)
{
	if (p != NULL)
	{
		Thread(p->lchild);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		else
			p->ltag = 0;
		if (pre->rchild == NULL) //pre指针为空?
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		else
			pre->rtag = 0;
		pre = p;
		//Thread(p->lchild);
		Thread(p->rchild);
	}
}

//线索化二叉树
TBTNode* CreateThread(TBTNode*& b)
{
	TBTNode* root = new TBTNode;
	root->data = '\0';
	root->lchild = root->rchild = NULL;
	root->ltag = root->rtag = 0;
	if (b == NULL)
		root->lchild = root;
	else
	{
		root->lchild = b;
		//root->ltag = 1;
		pre = root;
		Thread(b);
		pre->rchild = root;
		pre->rtag = 1;
		root->rchild = pre;
		root->rtag = 1;
	}
	return root;
}

//遍历线索二叉树(先序顺序)
void ThPreOrder(TBTNode*& root) {
	TBTNode* p = root->lchild;
	while (p != root)
	{
		while (p->ltag == 0) p = p->lchild;
		cout << p->data << " ";
		while (p->rtag == 1 && p->rchild != root)
		{
			p = p->rchild;
			cout << p->data << " ";
		}
		p = p->rchild;
	}
}

//初始化线索二叉树
void CreateTBTree(TBTNode*& b, string str){
	TBTNode* St[MAXSIZE];
	TBTNode* p = NULL;
	int top = -1;
	int k = 0, i = 0;
	char ch;
	b = NULL;

	for (i = 0; i<int(str.length()) && str[i] != '\0'; i++)
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
			p = new TBTNode;
			p->data = ch;
			p->lchild = p->rchild = NULL;
			p->ltag = p->rtag=0;
			if (b == NULL)
				b = p;
			else
			{
				if (k == 1)
					St[top]->lchild = p;
				else if (k == 2)
					St[top]->rchild = p;
			}
			break;

		}

	}
}


