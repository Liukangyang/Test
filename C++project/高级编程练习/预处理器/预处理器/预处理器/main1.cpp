#include<iostream>
#include<string>
using namespace std;

//#defne 宏 替代常量或表达式
#define PI 3.1415926
#define MAX(a,b)  (a>b ? a:b)

void test1()
{

	cout << "圆周率为：" << PI << endl;
	cout << "半径为2的圆的周长为：" << PI * 2 * 2 << endl;

	cout << "最大值为：" << MAX(10.22, 10.2) << endl;
}


//条件编译
//1、
//#ifdef 宏
//#define 
// #ifndef
//#endif
//
//2、
//#if 条件表达式
//#else
//#endif
#define NULL
#define DEBUG
#ifdef NULL
#define NULL 1
#endif

void test2()
{
	//cout << "NULL的值为：" << NULL << endl;
#ifdef DEBUG
	cout << "调试模式!" << endl;
#endif

#if NULL==1
	cout << "NULL的值为1" << endl;
#else
	cout << "NULL的值为0" << endl;
#endif

}

//#和##运算符
#define STRING(x) #x
#define CONCATSTR(x,y) #x ## #y
#define CONCATVAR(x,y) x ## y
void test3()
{
	int xy = 10;
	cout << STRING(HELLO C++) << endl;
	cout << CONCATSTR(HELLO,C++) << endl;
	cout << CONCATVAR(x, y) << endl;
}

//C++预定义宏
//__LINE__	这会在程序编译时包含当前行号。
//__FILE__	这会在程序编译时包含当前文件名。
//__DATE__	这会包含一个形式为 month / day / year 的字符串，它表示把源文件转换为目标代码的日期。
//__TIME__	这会包含一个形式为 hour : minute:second 的字符串，它表示程序被编译的时间。

void test4()
{
	cout << "Value of __LINE__ : " << __LINE__ << endl;
	cout << "Value of __FILE__ : " << __FILE__ << endl;
	cout << "Value of __DATE__ : " << __DATE__ << endl;
	cout << "Value of __TIME__ : " << __TIME__ << endl;
}


#define FUN 5
int main()
{

//#if条件编译嵌套结构
#if FUN==1
	test1();
#else 
	#if FUN==2
		test2();
	#else
		#if FUN==3
			test3();
		#else
			#if FUN==4
				test4();
			#else
				cout << "ERROR!" << endl;
			#endif
			
		#endif
	#endif
#endif
	return 0;
}