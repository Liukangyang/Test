#include<stdio.h>
#include<stdlib.h>
#include<winsock2.h>
#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<math.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

//十进制转二进制
deque<int> DecimalToBinary(long long int num)
{
	deque<int> Binary;
	int Yushu = 0;

	//转化步骤
	while (num !=0)
	{
		Binary.push_front(num%2);
		num/=2;
	}

	if (Binary.size() < 8)
	{
		int k = 8 - Binary.size();
		while (k--)
		{
			Binary.push_front(0);
		}
	}

	return Binary;

}

//二进制转十进制
int BinaryToDecimal(deque<int>& Binary)
{
	int sum = 0;
	for (int i = 0,n=Binary.size(); i < n; i++)
	{
	
		sum += Binary[i] != 0 ? pow(2, n - i - 1) : 0;
	}

	return sum;
}




void test01()
{
	deque<int> Binary = DecimalToBinary(192);
	cout << "二进制表示为：";
	for (int i = 0; i < Binary.size(); i++)
	{
		cout << Binary[i];
	}

	cout << endl;
	int sum = BinaryToDecimal(Binary);
	cout << "十进制表示为： " << sum;

}


int main()
{

	test01();



	return 0;

}