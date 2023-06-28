#include<iostream>
#include<string>
#include "BTree.h"
#include"BTree2.h"
using namespace std;

//基础测试
void test1(BTNode* b, BTNode* p)
{

	cout << endl << "二叉树高度为：" << BTreeHeight(b);
	cout << endl;

	//char c;
	//cout << "输入查找元素：";
	//cin >> c;
	//p = FindNode(b, c);
	//if (p != NULL)
	//	cout << "在二叉树查找到该元素!" << endl;
	//else 
	//	cout << "在二叉树中不存在该元素!" << endl;

	char c;
	cout << "输入元素:";
	cin >> c;
	//ChildNode(b, c);
	BTNode* par;
	p = FindNode(b, c);
	par = ParentNode(b, p);
	if (par != NULL) cout << "指定元素结点的双亲结点为:" << par->data << endl;
	else cout << "指定元素结点的双亲结点不存在" << endl;

}

//遍历测试
void test2(BTNode* b)
{
	//cout << "先序遍历结果为：";
	//PreOrder(b);
	//cout << endl;

	//cout << "中序遍历结果为：";
	//InOrder(b);
	//cout << endl;

	//cout << "后序遍历结果为：";
	//PostOrder(b);
	//cout << endl;
	cout << "层次遍历1结果：";
	LevelOrder1(b);
	cout << "层次遍历2结果："<<endl;
	LevelOrder2(b);

}

//算法测试
void test3(BTNode* b)
{
	//char c;
	//cout << "输入想要找的结点值：";
	//cin >> c;
	//int h = Level(b, c);
	//if (h == 0) cout << "你要找的结点不存在!" << endl;
	//else
	//{
	//	cout << "寻找到节点，且节点的深度为：" << h << endl;
	//	cout << "该节点的祖先节点为：";
	//	bool r = Ancestor(b, c);	
	//}
	//cout << endl;
	
}

//线索化二叉树测试
void test4()
{
	TBTNode* b = NULL;
	TBTNode* p = NULL;
	string s;
	cout << "请输入二叉树的括号表达式：";
	cin >> s;

	//二叉树初始化
	CreateTBTree(b,s);
	//二叉树线索化
	TBTNode *root= CreateThread(b);
	//线索二叉树遍历输出
	ThPreOrder(root);
}

int main()
{
	//BTNode* b = NULL;
	//BTNode* p = NULL;
	//string s;
	//cout << "请输入二叉树的括号表达式：";
	//cin >> s;

	//CreateBTree(b, s);
	//cout << "输出二叉树为：";
	//DispBTree(b);
	//cout << endl;

	////二叉树运算测试
	////test1(b, p);
	//test2(b);
	////test3(b);
	test4();

	//DestoryBTree(b);
	//if (b == NULL) cout << "二叉树已销毁" << endl;
	

	return 0;
}