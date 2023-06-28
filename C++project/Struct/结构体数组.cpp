//  此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
using namespace std;

#define MAX_SIZE 3
//结构体变量定义
//struct 结构体名 变量名（struct可省略）
//struct 结构体名 变量名 = { 成员1值 ， 成员2值… }
//定义结构体时顺便创建变量
struct Student
{
    //成员变量
    string name;
    int age;
    int score;
};

void test1()
{
    //声明变量
     Student s1;
   // s1.name = "刘康杨"; s1.age = 22; s1.score = 99;
    s1 = {"Liukangyang",22,99};
    cout << "姓名:" << s1.name << "  年龄：" << s1.age << "  分数：" << s1.score << endl;
    
    //结构体数组
    Student ss[MAX_SIZE]=
    {
        {"LKY",22,99},
        {"zhangsan",24,100},
        {"YY",22,100}
    };
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << "姓名:" << ss[i].name 
            << "  年龄：" << ss[i].age 
            << "  分数：" << ss[i].score << endl;
    }
}
//int main()
//{
//    test1();
//    return 0;
//
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
