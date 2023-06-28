// 文件操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include <fstream>//1.文件操作头文件
using namespace std;

//文本文件

void test1()
{
    //写文件
    //2.创建文件对象
    ofstream ofs;

    //3.打开文件
    ofs.open("text.txt",ios::out);//写文本文件
    //判断打开是否成功
    if (!ofs.is_open())
    {
        cout << "未成功打开文件！" << endl;
        return;
    }
    else
    {
     //4.写数据
        ofs << "姓名：刘康杨" << endl;
        ofs << "年龄：22" << endl;
        ofs << "喜好：唱跳rap" << endl;
    }

    //5.关闭文件
    ofs.close();

}

//读文件
void test2()
{
    //2创建文件流对象
    ifstream ifs;

    //3打开文件
    ifs.open("text.txt",ios::in);
    if (!ifs.is_open())
    {
        cout << "未成功打开文件！" << endl;
        return;
    }
    else
    {
        //4读数据
        //4,1
        //    char buf[1024] = { 0 };
        //    while (ifs >> buf)   //>>每次只能读入一行
        //    {
        //        cout << buf << endl;
        //    }
        //}

        //4.2
        //char buf[1024] = { 0 };
        //while (ifs.getline(buf, sizeof(buf)))//每次读取一行
        //{
        //    cout << buf << endl;
        //}
        // 4.3
        //string buf;
        //while (getline(ifs, buf))
        //{
        //    cout << buf << endl;
        //}

        //4.4
        char c;
        while ((c = ifs.get()) != EOF)//EOF是文件末尾标志
        {
            cout << c;
        }


        //5关闭文件
        ifs.close();
    }
}

//int main()
//{
//    //test1();
//    test2();
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
