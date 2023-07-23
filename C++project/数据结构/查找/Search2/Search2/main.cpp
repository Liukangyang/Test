#include<iostream>
#include<string>
#include"Search2.h"
#include "Ex.h"
using namespace std;
#define MAXV 6

void test1()
{
	//同一关键字集合的不同序列，形成的二叉排序树结构也不一样
	//但是它们的中序遍历序列都是一样的
	int a[MAXV] = { 1,4,2,8,6,5};
	BSTNode* bt = NULL;
	bt = CreateBST(a, MAXV);     //创建二叉排序树
	BST_Scan(bt);                //中序遍历输出
	int k = 6;
	BSTNode* p = NULL;
	p=SearchBST(bt, k);         //查找指定关键字结点
	if (p == NULL) cout << "树中不存在该节点！";
	else cout << "找到该节点：" << p->key;
}

void test2()
{
	int a[MAXV] = { 1,4,2,8,6,5 };
	BSTNode* bt = NULL;
	bt = CreateBST(a, MAXV);     //创建二叉排序树
	BST_Scan(bt);                //中序遍历输出
	cout << endl;
	int k = 8;
	bt=DeleteBST(bt, k);        //删除指定关键字结点
	BST_Scan(bt);				//删除后再输出

}

//字符统计二叉树实验
void test3()
{
	string str = "my name is liukangyang";
	char* alphabet = new char[26];
	int *count = NULL;
	count = Count_Char(str, alphabet);
	
	for (int i = 0; i < 26; i++)
	{
		if( count[alphabet[i]-97] != 0 )
			cout << "[" << alphabet[i] << "," << count[i] << "]->" ;
	}
	cout << endl;
	BSTNode2* bt = NULL;
	bt = CreateBST(alphabet, count, 26);
	BST_Scan(bt);
	cout << endl;
}


int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}

