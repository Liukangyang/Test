#include<iostream>
#include<string>
using namespace std;

//插入删除操作
void test09()
{
	//插入
	string str = "hello";
	str.insert(1, "123");//h123ello
	cout << str << endl;

	//删除
	str.erase(1, 3);
	cout << str << endl;;
}

//子串获取
void test10()
{
	string email = "zhangsan@126.com";
	int pos = email.find('@');
	cout << "用户名：" << email.substr(0, pos) << endl;

}


//int main()
//{
//	test10();
//	return 0;
//}