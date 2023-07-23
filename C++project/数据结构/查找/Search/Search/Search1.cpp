#include "Search1.h"

//查找算法

//1.顺序查找
int SeqSearch(RecType R[], int n, int k)
{
	int i = 0;
	int count = 0;
	/*
	while (i < n)
	{
		if (R[i].key == k) return i + 1;  //返回逻辑序号
		i++;
	}
	return -1;    //未找到指定元素
*/
	while (i < n && R[i].key != k)
	{
		i++;
		count++;
	}
	if (i >= n) return -1;
	else 
	{ 
		count++;
		cout << "共查找" << count << "次" << endl;
		return i + 1; 
	}
}

//2.折半查找1（二分查找）
int BinSearch1(RecType R[], int n, int k)
{
	int count=0;
	int low = 0, high = n - 1;  // 区间左右端点
	int mid = -1;
	while ( low <= high )
	{
		mid = (low + high) / 2;   //取中间值
		if (R[mid].key == k) 
		{
			count++;
			cout << "共查找" << count << "次" << endl;
			return mid + 1;
		}

		if (k < R[mid].key) high = mid - 1;  //缩短为左半区间
		else low = mid + 1;                 //缩短为右半秋区间
		count++;
	}
	return -1;  

}

//折半查找2（扩展）
int BinSearch2(RecType R[], int n, char str)
{
	int low = 0, high = n - 1;  // 区间左右端点
	int mid = -1;
	int s=-2;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (str <= R[mid].data)
		{
			high = mid - 1;
			if (str == R[mid].data)
				s = mid;
		}
		else low = mid + 1;
	}
	return s+1;
}

//3.分块查找
int IdxSearch(IdxType *I,RecType R[],int n,int b,int k)
{
	int s = int((float)n / b + 1);
	int low = 0, high = b - 1, mid = -1,i=0;
	//第一阶段：折半查找索引表，获取所在分块
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (I[mid].key >= k) high = mid - 1;
		else low = mid + 1;
	}

	//第二阶段：顺序查找线性表，获取元素位置
	i = I[low].link;	
	while (i <= I[low + 1].link+s-1)
	{ 

		if (R[i].key == k) return i + 1;   //返回元素逻辑位序
		else i++;
	}
	return -1;
}

//建立索引表
IdxType* IdxCons(RecType R[], int n, int b)
{
	int s = int((float)n / b + 1);
	IdxType* p = new IdxType[b];
	//将线性表分块
	//抽取每块中的最大关键字加入索引表中并记录对应元素的下标位置
	int i = 0;
	int key = 0, max = 0,link=0;
	int j = 0;
	int ss = 0;
	while (i < n)
	{
		max = R[i].key; link = (i / s) * s;
		if (n - i >= s) ss = s;
		else ss = n -i;
		for (int k = i; k < i + ss; k++)
		{
			if (R[k].key > max) 
			{ 
				max = R[k].key;
				link = (k / s) * s;
			}
		}
		p[j].key = max;
		p[j].link = link;
		j++;
		i += ss;  //下一个分块的起始下标
	}

	//返回索引表
	return p;
}




