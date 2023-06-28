#include<iostream>
using namespace std;

class Person4
{
public:
	string name;
	double score;
	int age;


	//无参构造函数
	Person4():age(20),name("张三"),score(100)
	{
		cout << "调用Student构造函数" << endl;
	}

	//有参构造函数1
	Person4(int s_age,string s_name,double s_score):age(s_age),name(s_name),score(s_score)
	{
		cout << "调用有参构造函数" << endl;
	}


	//析构函数
	~Person4()
	{

		cout << "调用析构函数" << endl;
	}

	//有参构造函数2(拷贝)
	//Person4(const Person4& p)
	//{
	//	//深拷贝
	//	age = new int(*p.age);
	//	cout << "调用拷贝构造函数" << endl;
	//}



};
//int main()
//{
//	Person4 p1;
//	cout << p1.name << p1.age << p1.score << endl;
//	Person4 p2(22, "李四", 98);
//	cout << p2.name << p2.age << p2.score << endl;
//	system("pause");
//	return 0;
//}