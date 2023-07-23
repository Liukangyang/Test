#include "SelectSort.h"


void test1()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a) / sizeof(int);
	SelectSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;
}

int main()
{	
	test1();
	return 0;
}