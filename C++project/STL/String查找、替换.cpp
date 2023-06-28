#include<iostream>
#include<string>
using namespace std;

//查找
//int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
//int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
//int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
//int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
//int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
void test05()
{
	string str1 = "abcdeldajslde";
	int pos=str1.find("de");
	cout << "pos = " << pos << endl;

	int pos2 = str1.rfind("de");
	cout << "pos2 = " << pos2 << endl;
}


//替换
//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

void test06()
{
	string str1 = "djkhsad";
	string str2 = " www. ";
	cout << "替换前str1=" << str1 << endl;
	str1.replace(3, 3, str2);
	cout << "替换后str1=" << str1 << endl;
}
//int main()
//{
//	test06();
//	return 0;
//
//}