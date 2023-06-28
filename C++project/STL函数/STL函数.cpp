// STL函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//仿函数
class Myadd
{
public:
    //仿函数定义
   int operator()(int v1, int v2)const
    {
       return v1 + v2;
    }

};

//函数对象
void test1()
{  
    Myadd myadd;  //定义函数对象
    cout << "相加结果为：" << myadd(10, 20) << endl;  //调用仿函数
}

//一元谓词
class Mycompare
{
public:
    bool operator()(int val)const
    {
        return val > 6;
    }
};


//谓词
//一元谓词
void test2()
{
    vector<int> v;
    v.push_back(2);   v.push_back(4); v.push_back(6);
    v.push_back(2); v.push_back(10);
    vector<int>::iterator it = find_if(v.begin(), v.end(), Mycompare());
     
    if (it == v.end())
    {
        cout << "未找到满足条件的元素！" << endl;
    }
    else
    {
        cout << "找到满足条件的元素:" << *it << endl;
    }
}

//二元谓词
class Mycompare2
{
public:
    bool operator()(int v1, int v2)const
    {
        return v1 > v2;//降序
    }
};

//二元谓词
void test3()
{
    vector<int> v;
    v.push_back(2); v.push_back(1); v.push_back(10);
    v.push_back(6); v.push_back(8); v.push_back(12);
    cout << "原容器内容：" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    
   // sort( v.begin(), v.end() );//默认升序排序
    sort(v.begin(), v.end());
    cout << "调用sort（）排序后容器内容:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //降序排序
    sort(v.begin(), v.end(), Mycompare2());
    cout << "调用仿函数后容器内容:" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

//int main()
//{
//    //test2();
//    test3();
//    return 0;
//
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
