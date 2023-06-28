#include<iostream>
#include"speechManager.h"
using namespace std;


int main()
{
	srand((unsigned int)time(NULL));//初始化随机数种子
	//创建管理类对象
	SpeechManager sm;

	int choice = 0;
	//创建选手测试
	/*
	cout << "参赛选手：" << endl;
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< " 姓名： " << it->second.m_Name
			<< " 成绩： " << it->second.m_Score[0] << endl;

	}*/

	while (true)
	{
		sm.show_Menu();
		cout << "输入您的选择：" ;
		cin >> choice;

		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://显示往届记录
			sm.showRecord();
			break;
		case 3://清除记录
			sm.clearRecord();
			break;
		case  0:
			sm.exitSystem();
		    break;
		default:
			system("cls");//清屏
			break;

		}

	}
}