#include "Ex.h"

/*
统计字符串中的字符及其出现次数，，并构建二叉排序树
分析：先依次统计字符串中每个字符的出现次数，按照字符顺序输出，然后以出现次数作为关键字，
将每个字符插入到二叉树的每个节点中，再输出二叉排序树序列进行输出结果比较。
*/

//统计字符个数
int* Count_Char(string str,char *alphabet)
{
	//alphabet = new char[26];   //字母表
	int* count = new int[26]{ 0 };
	for (int i = 0; i < 26; i++)
	{
		alphabet[i] = i + 97;    //小写字母集合
	}
	for (int i = 0; i < str.size(); i++)
	{
		if( (str[i] - 97)>=0 && (str[i] - 97) < 26)  //限定为小写字母范围
			count[str[i] - 97] +=1;
	}
	return count;
}

//二叉排序树的插入
BSTNode2* InsertBSTNode2(BSTNode2* bt, int *count,char k)
{
	if (bt == NULL)
	{
		bt = new BSTNode2;
		bt->c = k; bt->count = count[k - 97];
		bt->lchild = bt->rchild = NULL;
	}
	else if (k < bt->c)
	{
		bt->lchild = InsertBSTNode2(bt->lchild, count,k);
	}
	else if (k > bt->c)
	{
		bt->rchild = InsertBSTNode2(bt->rchild, count,k);
	}
	return bt;
}

// 二叉排序树的创建
BSTNode2 * CreateBST(char *alphabet, int* count,int n)
{
	BSTNode2* bt = NULL;
	int i = 0;
	while (i < n)
	{
		if(count[ alphabet[i]-97] != 0)   //对应字母出现次数大于0
			bt = InsertBSTNode2(bt, count, alphabet[i]);
		i++;
	}
	return bt;
}

//二叉排序树的遍历（中序遍历）
void BST_Scan(BSTNode2* bt)
{
	if (bt != NULL)
	{
		if (bt->lchild != NULL)
			BST_Scan(bt->lchild);    //左子树
		cout << "[" << bt->c << ","<<bt->count<<"]->";   //根结点
		if (bt->rchild != NULL)
			BST_Scan(bt->rchild);    //右子树
	}
}