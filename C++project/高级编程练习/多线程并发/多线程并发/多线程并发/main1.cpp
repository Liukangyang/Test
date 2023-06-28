#include<iostream>
#include<thread>  //c++11新标准线程库
using namespace std;

//初始函数
void Myprint()
{
	cout << "子线程开始执行！" << endl;
	//...//
	cout << "Hello world1!" << endl;
	cout << "Hello world2!" << endl;
	cout << "Hello world3!" << endl;
	cout << "Hello world4!" << endl;
	cout << "Hello world5!" << endl;
	cout << "Hello world6!" << endl;
	cout << "子线程执行完毕！" << endl;
	
}

int main()
{
	//1。创建线程
	thread myprocess(Myprint);
	//2.阻塞主线程
	//if (myprocess.joinable())
	//{
	//	cout << "1.jionable!" << endl;
	//}
	//else
	//{
	//	cout << "1.no joinable!" << endl;
	//}
	if(myprocess.joinable())
		myprocess.join();
	else
	{
		cout << "已调用join或detach函数！" << endl;
	}

	//if (myprocess.joinable())
	//{
	//	cout << "2.jionable!" << endl;
	//}
	//else
	//{
	//	cout << "2.no joinable!" << endl;
	//}


	
	//3.分离主线程和子线程
	//	if (myprocess.joinable())
	//{
	//	cout << "1.detachable!" << endl;
	//}
	//else
	//{
	//	cout << "1.no detachable!" << endl;
	//}
	// 
	if(myprocess.joinable())
		myprocess.detach();
	else
	{
		cout << "已调用join或detach函数！" << endl;
	}
	// 
	//if (myprocess.joinable())
	//{
	//	cout << "1.detachable!" << endl;
	//}
	//else
	//{
	//	cout << "1.no detachable!" << endl;
	//}

	//myprocess.join();   //分离后就不能再汇合了！！！
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;
	cout << "I Love China!" << endl; cout << "I Love China!" << endl;

	cout << "主线程执行完毕" << endl;


	return 0;
}


