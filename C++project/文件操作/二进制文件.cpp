#include <iostream>
#include<string>
#include <fstream>//1.文件操作头文件
using namespace std;

class Person
{
public:
	/*Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}*/
	//Person()
	//{}
	string name;
	int age;
};
//写文件
void test3()
{	
	Person p;
	p.age = 22; p.name = "LKY";
	//2.
	ofstream ofs;

	//3.
	ofs.open("person.txt", ios::out | ios::binary);//以二进制形式打开

	//4.
	ofs.write((const char *) & p,sizeof(p));


	//5.
	ofs.close();

}

//读文件
void test4()
{
	//2.
	ifstream ifs;

	//3.
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "未打开成功！" << endl;
		return;
	}

	//4.
	Person p;
	ifs.read((char *)&p, sizeof(Person));

	cout << "姓名：" << p.name << " 年龄：" << p.age << endl;

	//5.
	ifs.close();

}

int main()
{ 
	//test3();
	test4();
}