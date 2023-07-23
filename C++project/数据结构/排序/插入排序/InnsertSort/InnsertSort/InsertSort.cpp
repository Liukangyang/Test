#include "InsertSort.h"

//插入排序算法
//1.直接插入排序
void InsertSort(int R[],int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)  //R[i]为无序区中第一个元素
	{
		if (R[i] < R[i - 1])
		{
			tmp = R[i];
			j = i - 1;    //从有序区最后一个元素开始，往前遍历
			while (j >=0 && R[j] > tmp)
			{
				R[j + 1] = R[j];
				j--;
			}
			R[j + 1] = tmp;
		}	
	}
}

//2.折半插入排序
void BinInsertSort(int R[], int n)
{
	int i, j, tmp;
	int low, high,mid;
	for (i = 1; i < n; i++)  //R[i]为无序区中第一个元素
	{
		if (R[i] < R[i - 1])
		{
			tmp = R[i];
			j = i - 1;     //从有序区最后一个元素开始，往前遍历
			low = 0; high = i - 1;
			while (low <= high)   //折半查找插入位置
			{
				mid = (low + high) / 2;
				if (tmp < R[mid])
					high = mid - 1;
				else low = mid + 1;
			}
			//元素位置后移
			for (j = i - 1; j >= high + 1; j--)
			{
				R[j + 1] = R[j];
			}
			R[high + 1] = tmp;
		}
	}
}

//3.希尔排序
void ShellSort(int R[], int n)
{
	int i, j, d;  
	int tmp;  
	d = n / 2;   //初始增量

	while (d > 0)
	{
		//分组并对每一组进行插入排序
		for (i = d; i < n; i++)
		{
			tmp = R[i];
			j = i - d;    //从有序区最后一个元素开始，往前遍历
			while (j >= 0 && R[j] > tmp)
			{
				R[j + d] = R[j];
				j-=d;//j=j-d;
			}
			R[j + d] = tmp;
		}
		d = d / 2;   //更新增量
	}
}