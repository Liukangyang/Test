#include<iostream>
#include<string>
using namespace std;

//string构造
void test01()
{
	string s1;//空构造

	const char* str = "hello world!";
	string s2(str); //传入const char *或者字符串
	cout << "s2 = "<<s2 << endl;

	string s3(s2);   //拷贝构造
	cout << "s3 = " << s3 << endl;

	string s4(3, '6');//string(int n,char c)
	cout << "s4 = " << s4 << endl;

}

//string赋值操作
//string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
//string& operator=(const string& s); //把字符串s赋给当前的字符串
//string& operator=(char c); //字符赋值给当前的字符串
//string& assign(const char* s); //把字符串s赋给当前的字符串
//string& assign(const char* s, int n); //把字符串s的前n个字符赋给当前的字符串
//string& assign(const string& s); //把字符串s赋给当前字符串
//string& assign(int n, char c); //用n个字符c赋给当前字符串
void test02()
{

	//赋值号方式
	string str1;
	str1 = "Hello world!";
	cout << str1 << endl;

	string str2=str1;
	cout << str1 << endl;
	
	string str3 = "c";
	cout << str3 << endl;

	//assign()方式
	string str4;
	str4.assign("Hello world!", 5);
	cout << str4 << endl;

	string str5;
	str5.assign(10, 'w');
	cout << str5 << endl;

}

//字符串拼接
//string& operator+=(const char* str); //重载+=操作符
//string& operator+=(const char c); //重载+=操作符
//string& operator+=(const string& str); //重载+=操作符
//string& append(const char* s); //把字符串s连接到当前字符串结尾
//string& append(const char* s, int n); //把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string& s); //同operator+=(const string& str)
//string& append(const string& s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾

void test03()
{
	//+=
	string str1 = "I love";
	str1 += ":";
	cout << "str1=" << str1 << endl;//string& operator+=(const char* str)

	string str2 = "LOL";
	str1 += str2;
	cout << "str1=" << str1 << endl;//string& operator+=(const string& str);

	//append()
	str1.append("and");
	cout << "str1=" << str1 << endl;

	string str3 = "DNF";
	str1.append(str3);
	cout << "str1=" << str1 << endl;

	string str4 = " but I more like...";
	str1.append(str4, 0,16);
	cout << "str1=" << str1 << endl;



}

//int main()
//{
//	test03();
//	return 0;
//
//
//}