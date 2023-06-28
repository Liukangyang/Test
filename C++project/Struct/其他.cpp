#include <iostream>
#include<string>
using namespace std;

struct Student3
{
    //成员变量
    string name;
    int age;
    int score;
};

struct Teacher
{
    string name;
    int age;
    int bianhao;
    Student3 stu;
};

//结构体嵌套结构体
void test3()
{
    Teacher tea;
    tea.age = 30; tea.name = "王老师"; tea.bianhao = 50200;
    tea.stu.age = 22; tea.stu.name = "小王"; tea.stu.score = 99;
    cout << "学生姓名：" << tea.stu.name << " 学生年龄：" << tea.stu.age << " 学生分数：" << tea.stu.score << endl;

}

//结构体做函数参数
//1.值传递
void Myprint(Student3 s)
{
    s.age = 100;
    cout << "学生姓名：" << s.name
        << " 学生年龄：" << s.age
        << " 学生分数：" << s.score << endl;
}

//2.地址传递
void Myprint(Student3 *p)
{
    p->age = 100;
    cout << "子函数" << endl;
    cout << "学生姓名：" << p->name
        << " 学生年龄：" << p->age
        << " 学生分数：" << p->score << endl;
}

void test4()
{
    Student3 s = { "小王",22,99};
    //Myprint(s);//值传递
    Myprint(&s);//地址传递
    cout << "主函数" << endl;
    cout << "学生姓名：" << s.name
        << " 学生年龄：" << s.age
        << " 学生分数：" << s.score << endl;
}

//const关键字使用
void printStrust(const Student3 *p)
{
    //p->age= 100;  //声明const后，形参不可再修改
    cout << "学生姓名：" << p->name
        << " 学生年龄：" << p->age
        << " 学生分数：" << p->score << endl;
}
void test5()
{
    Student3 s = { "小王",22,99 };
    printStrust(&s);
    s.age = 100;  //只能通过实参进行修改
    printStrust(&s);
}


//int main()
//{
//    //test3();
//    //test4();
//    test5();
//    return 0;
//}
