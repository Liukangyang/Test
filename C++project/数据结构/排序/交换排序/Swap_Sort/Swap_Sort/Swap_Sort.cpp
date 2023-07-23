#include "Swap_Sort.h"

//冒泡排序
void BubbleSort(int R[],int n)
{
	int i, j,flag,tmp;
	int count=0;   //统计排序次数
	for (i = 0; i < n-1; i++)  //至多循环n-1趟
	{
		flag = 0;
		//上升法
		for (j = n - 1; j >= i + 1; j--)
		{
			if (R[j - 1] > R[j])
			{
				flag = 1;      //当需要交换时，就设置标志位
				tmp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = tmp;
			}
		}
		count++;
		if (!flag) break;    //若当前趟排序没有任何元素间的交换，说明数组已经有序
	}
	cout << "共执行" << count << "次排序" << endl;
}

//快速排序
int partion(int R[], int s, int t)  //一趟划分
{
	int i = s, j = t;
	int base = R[i];   //以无序区的第一个元素为基准
	while (i < j)  // 交替扫描，直到i=j为止
	{
		//从后往前扫描
		while( j > i && R[j] >= base )
		{
			j--;
		}
		if (i < j)   //R[j]<base
		{
			R[i] = R[j];
			i++;
		}
		//从前往后扫描
		while (j > i && R[i] < base)
		{
			i++;
		}
		if (i < j)   //R[i]>=base
		{
			R[j] = R[i];
			j--;
		}
	}

	//中间位置插入基准元素
	R[i] = base;
	
	//返回中间插入基准元素的位置
	return i;
}

//快速排序递归
void QuickSort(int R[], int s, int t)
{
	int i;
	if (s > t) return;
	else
	{
		i = partion(R, s, t);   
		QuickSort(R, s, i - 1);  //对左区间递归排序
		QuickSort(R, i+1, t);    //对右区间递归排序
	}
}