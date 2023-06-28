#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<deque>
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
#include"speaker.h"

using namespace std;

//管理类
class SpeechManager
{
public:
	//构造
	SpeechManager();
	//析构
	~SpeechManager();

	//菜单功能界面
	void show_Menu();

	//退出功能
	void exitSystem();

	//初始化属性
	void initSpeech();

	//创建选手
	void createSpeaker();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();
	
	//显示得分
	void showScore();

	//记录得分
	void saveRecord();

	//读取往届记录
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清空记录
	void clearRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	map<int,vector<string>> m_Record;

	//容器
	vector<int> v1;
	vector<int> v2;
	vector<int> vVictory;

	map<int,Speaker> m_Speaker;

	//比赛轮次
	int m_Index;



};