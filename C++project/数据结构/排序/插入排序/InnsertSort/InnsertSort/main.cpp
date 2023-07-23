#include <iostream>
#include "InsertSort.h"
using namespace std;

//÷±Ω”≤Â»Î≈≈–Ú
void test1()
{
	int a[] = { 2,1,4,6,9,8,3,7,10,5 };
	//cout << sizeof(a) / sizeof(int);
	int n = sizeof(a) / sizeof(int);
	InsertSort(a,n);
	for (int i = 0; i < n-1; i++)
		cout<< a[i] << ",";
	cout << a[9] << endl;
}

//’€∞Î≤Â»Î≈≈–Ú
void test2()
{
	int a[] = {10,9,8,7,6,5,4,3,2,1 };
	//cout << sizeof(a) / sizeof(int);
	int n = sizeof(a) / sizeof(int);
	BinInsertSort(a, n);
	for (int i = 0; i < n-1; i++)
		cout << a[i] << ",";
	cout << a[9] << endl;
}

//œ£∂˚≈≈–Ú
void test3()
{
	int a[] = { 2,1,4,6,9,8,3,7,10,5};
	//cout << sizeof(a) / sizeof(int);
	int n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << ",";

}

void main()
{
	//test1();
	//test2();
	test3();
}