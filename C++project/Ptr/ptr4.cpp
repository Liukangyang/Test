#include<iostream>
#include<stdio.h>
using namespace std;

int main1()
{
	int arr[6] = { 0,1,2,3,4,5 };
	//·ÃÎÊÊı×é
	// 
	//1.arr[i]
	//cout << arr[2] << endl;
	//cout << size(arr);
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
	//2.*p
	int* p = arr;
	//cout << *(p+2) << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << *(p+i) << endl;
	}
	cout << endl;
	/*
	for (int i = 0; i < size(arr); i++)
	{
		cout << *p  << endl;
		p++;
	}*/

	//cout << p[3] << endl;
	for (int i = 0; i < size(arr); i++)
	{
		cout << p[i] << endl;
	}
	cout << endl;

	cout << endl;

	return 0;
}

