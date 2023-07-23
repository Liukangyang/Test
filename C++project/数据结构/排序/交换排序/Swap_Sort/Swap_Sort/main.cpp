#include "Swap_Sort.h"

void test1()
{
	int a[] = {4,3,1,2,5,7,6,8,9};
	int n = sizeof(a) / sizeof(int);
	BubbleSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;
}

void test2()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}