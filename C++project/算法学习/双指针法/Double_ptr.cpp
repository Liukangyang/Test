#include<stdio.h>
#include<vector>
#include <iostream>
#include <math.h>
#include<algorithm>
using namespace std;

void Print_vector(vector<int> nums, int length)
{
    vector<int>::iterator ptr = nums.begin();
    for (int i = 0; i < length; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}
//(删除指定元素)快慢指针法
int removeElement(vector<int>& nums, int val) {
    int slowIndex = 0;
    for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
        if (val != nums[fastIndex]) {
            nums[slowIndex++] = nums[fastIndex];
        }
    }
    return slowIndex;//返回新数组长度
}

//(删除有序数组的重复元素)
int removeDuplicates(vector<int>& nums)
{
    int fast = 1; int slow = 1;
    for (; fast <= nums.size() - 1; fast++)
    {
        if (nums[fast] != nums[fast - 1])//元素未重复即进行赋值操作
        {
            nums[slow++] = nums[fast];
            //slow++;
        }
    }
    return slow;  //返回新数组长度
}


//(删除所有0元素)
int remove_Zeros(vector<int>& nums)
{
    int fast = 0; int slow = 0;
    while(fast<=nums.size()-1)
    {
        if (nums[fast] != 0)
        {
            nums[slow++] = nums[fast];
        }
        fast++;
    }
    return slow;  //返回新数组长度
}

void swap(vector<int>& num, int fast, int slow)
{
    int temp = num[slow];
    num[slow] = num[fast];
    num[fast] = temp;
}

//移动0元素
int move_Zeros(vector<int>& nums)
{
    int fast = 0; int slow = 0;
    for (; fast <= nums.size() - 1; fast++)
    {
        if (nums[fast] != 0)
        {
            swap(nums, fast, slow);
            slow++;
        }
    }
    return fast;
}

//有序数组平方1
void sortedSquares1(vector<int>& nums)
{
    vector<int>::iterator it_b = nums.begin();
    vector<int>::iterator it_e = nums.end();
    for (; it_b < it_e; it_b++)
    {
        (*it_b) = (*it_b) * (*it_b);
    }
    sort(nums.begin(),nums.end());
}

//有序数组平方2(相向指针)
vector<int> sortedSquares2(vector<int>& nums)
{
    int begin = 0; int end = nums.size() - 1;
    vector<int> squarenums(nums.size(),0);//构造函数
    int k = end;
    while(begin<=end)
    {
        if (nums[begin] * nums[begin] >= nums[end] * nums[end])
        {
            squarenums[k--] = nums[begin] * nums[begin];
            begin++;
        }
        else
        {
            squarenums[k--] = nums[end] * nums[end];
            end--;
        }
    }
    return squarenums;
}


int main()
{
    vector<int> num;
    num.push_back(-2); num.push_back(-1); num.push_back(0);
    num.push_back(2); num.push_back(3); num.push_back(4);
    Print_vector(num, num.size());

    //int len=removeElement(num, 2);
   // Print_vector(num, len);

    //int len = removeDuplicates(num);
   // Print_vector(num, len);

    //int len = remove_Zeros(num);
    //Print_vector(num, len);

    //int len = move_Zeros(num);
   // Print_vector(num, len);

    //sortedSquares1(num);
   // Print_vector(num, num.size());

    vector<int> squarenums = sortedSquares2(num);
    Print_vector(squarenums, squarenums.size());


    return 0;


}






