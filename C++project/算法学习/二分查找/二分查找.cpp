#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
#define ERROR -1

//闭区间，即[left,right]
template<class T>
T search(vector<T>& nums, T target)
{
	int left = 0;
	int right = nums.size() - 1;
	int middle = 0;
	while (left <= right)
	{
		middle = left + ((right - left) / 2);
		if (target > nums[middle])
		{
			left = middle + 1;
		}
		else if (target < nums[middle])
		{
			right = middle - 1;
		}
		else
			return middle;
	}

	return ERROR;

}

//左闭右开区间，即[left,right)
template<class T>
T search2(vector<T>& nums, T target)
{
	int left = 0;
	int right = nums.size() ;
	int middle = 0;
	while (left < right)
	{
		middle = left + ((right - 1 - left) / 2);
		if (target > nums[middle])
		{
			left = middle + 1;
		}
		else if (target < nums[middle])
		{
			right = middle ;
		}
		else
			return middle;
	}

	return ERROR;

}

int  main()
{
	vector<int> nums;
	int input=0;
	int target = 0;
	cout << "请输入数组： " ;
	cin >> input;
	while (input >= 0 && input <= 100)
	{
		nums.push_back(input);
		cin >> input;
	}
	while (1)
	{
		cout << "请输入查找的目标元素： ";
		cin >> target;
		if (target == -1) { break; }

		int Index = search2(nums, target);//
		if (Index == -1) cout << "未找到目标元素！" << endl << endl;
		else cout << "目标元素在数组中的下标为:" << Index << endl << endl;
		
	}
	cout << "退出！" << endl;
	return 0;

}