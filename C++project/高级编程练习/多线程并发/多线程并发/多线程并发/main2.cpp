#include<iostream>
#include<thread>  //c++11新标准线程库
using namespace std;

//构造子线程的方法
//1.lambda 表达式
void test1()
{
	auto mythread = [] {
		cout << "子线程开始运行！" << endl;
		//。。。。//
		cout << "子线程结束运行！" << endl;
	};
	thread mythread1(mythread);
	mythread1.join();
}

//2.通过类的可调用对象实现
class TA
{
public:
	int m_i;
	void operator()()
	{
		cout << "子线程开始运行！" << endl;
		//。。。。//
		cout << "子线程结束运行！" << endl;
	}
	TA(int i):m_i(i)
	{
		cout << "调用原始构造函数" << endl;
	}
	TA(const TA& ta):m_i(ta.m_i)
	{
		cout << "调用拷贝构造函数" << endl;
	}
	~TA()
	{
		cout << "调用析构函数" << endl;
	}


};

void test2()
{
	TA ta(2);
	thread mythread2(ta);
	mythread2.join();
}

int main()
{
	//test1();
	test2();
	cout << "I love China！" << endl;
	return 0;
}