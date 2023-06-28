#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
using namespace std;

int main()
{
	char name[100];
	string data;
	char Choice='y';
	//创建并打开文件
	ofstream outfile;
	outfile.open("TEST.txt", ios::out | ios::trunc);

	cout << "Writing to the file" << endl;
	//cout << "Enter your content: "<<endl;
	
	while (1)
	{	//输入内容
		if (Choice == 'y' || Choice == 'Y')
		{
			cout << "Enter your content: " << endl;
			cin >> name;
			outfile << name << endl;
			cout << "Continue?:(y/n) :";
			cin >> Choice;
		}
		else
			break;

	}

	//关闭文件
	outfile.close();

	//打开文件
	ifstream infile;
	infile.open("TEST.txt", ios::in);

	cout <<endl<< "Reading from the file:" << endl;

	//读取内容并显示在屏幕上
	//1.每次输出一个字符
	
	char c;
	while ((c = infile.get()) != EOF)
	{
		cout << c;
		Sleep(200);
	}
	cout << endl;

	//2.只读一行
	/*
	infile.clear(ios::goodbit);
	infile.seekg(0, ios::beg); 
	getline(infile, data);
	cout << data << endl;*/

	//2.连续读出
	//while ( infile >> data )
	infile.clear(ios::goodbit);  //当文件处于EOF状态时，需要重新设置为goodbit才能设置文件指针位置。
	infile.seekg(0, ios::beg);
	while( getline(infile,data) )
	{
		cout << data << endl;
	}



	//关闭文件
	infile.close();


	return 0;
}

