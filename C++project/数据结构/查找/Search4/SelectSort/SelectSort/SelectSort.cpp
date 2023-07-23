#include "SelectSort.h"

//直接选择排序（递减顺序）
void SelectSort(int R[], int n)
{
	int i, j, k;
	int tmp;
	for (i = 0; i < n - 1; i++)  //做n-1躺排序
	{
		k = i;   //每躺排序初始时以无序区的第一个元素作为中间元素
		for (j = i + 1; j < n; j++)   //寻找无序区中最大的元素
		{
			if (R[j] > R[k])
				k = j;    //记录最大元素的位置
		}
		if (k != i)
		{
			tmp = R[i];
			R[i] = R[k];
			R[k] = tmp;
		}
	}
}