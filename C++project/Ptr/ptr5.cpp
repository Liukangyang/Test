#include<iostream>
#include<stdio.h>
using namespace std;


//冒泡排序(从小到大)
int Bubblesort(int *arr,int len)
{
	int count = 0;
	bool isSort = true;
	for (int i = 0; i < len - 1; i++)//控制循环轮次
	{
		for (int j = 0; j < len - 1 - i; j++)//控制每一轮次的比较次数
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				isSort = false;
			}
		}
		count++;
		if (isSort) break;
		else isSort = true;
	}
	return count;
}

//打印输出数组
void Printvalue(int *arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << ',' ;
	}
	cout << endl;
}
int main2()
{
	//冒泡排序
	int count = 0;
	int arr[10] = { 1,3,2,5,4,6,7,9,10,8};
	count=Bubblesort(arr,size(arr));
	Printvalue(arr, size(arr));
	cout << "排序算法执行轮次：" << count << endl;

	return 0;
}