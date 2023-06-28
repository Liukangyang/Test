#include<iostream>
#include<csignal>
#include<Windows.h>
using namespace std;

//信号处理函数
void signalHandler(int signum) 
{
	cout << "signal" << '(' << signum << ')' << "received!" << endl;
	exit(signum);
}

int main()
{
	//注册信号并关联信号处理函数
	signal(SIGINT, signalHandler);
	int i = 0;
	while (1)
	{
		cout << "Programme is running!" << endl;
		Sleep(500);
		
		i++;
		if (i == 3)
			raise(SIGINT);//raise()函数生成信号

	}
	return 0;
}