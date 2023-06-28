#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

//ÀàÄ£°å
template<class T>
class MyClass
{
public:
	T obj;
	void func1() {
		obj.showPerson1();
	}

	void func2() {
		obj.showPerson2();
	}
};


//int main()
//{
//	MyClass<Person2> p;
//	//p.func1();
//	p.func2();
//
//	return 0;
//}