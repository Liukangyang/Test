#include <iostream>
#include<string>
using namespace std;

struct Student2
{
    //成员变量
    string name;
    int age;
    int score;
};

//结构体指针
void test2()
{
    Student2 s1 = { "小姐姐",22,99 };
    Student2* p = &s1;
    //通过结构体指针访问成员
    cout <<"姓名：" << p->name <<" 年龄：" << p->age <<" 分数：" << p->score << endl;
}
//int main()
//{
//    test2();
//    return 0;
//
//}