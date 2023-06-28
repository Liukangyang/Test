#include"speechManager.h"
#include<algorithm>

SpeechManager::SpeechManager()
{
	//属性初始化
	this->initSpeech();

	//创建选手
	this->createSpeaker();

	//加载往届记录
	this->loadRecord();

	this->m_Record.clear();
}

SpeechManager::~SpeechManager()
{}


void SpeechManager::show_Menu()
{

	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

}
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);//退出程序
}

void SpeechManager::createSpeaker()
{
	string nameseed = "ABCDEFGHIJKL";
	for(int i=0;i<nameseed.size();i++)
	{ 
		string name = "选手_";
		name += nameseed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}
		//编号
		this->v1.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));

	}
}

//初始化属性
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	this->m_Index = 1;
}

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示晋级结果
	this->showScore();

	//第二轮比赛
	this->m_Index++;
	//1、抽签
	this->speechDraw();
	//2、比赛
	this->speechContest();
	//3、显示最终结果
	this->showScore();
	//4、保存分数
	this->saveRecord();

	//重置属性，获取记录
	//属性初始化
	this->initSpeech();
	//创建选手
	this->createSpeaker();
	//加载往届记录
	this->loadRecord();


}

//抽签
void SpeechManager::speechDraw()
{
	cout << "第<" << this->m_Index << ">轮抽签" << endl;
		cout<<"------------------------------"<<endl;
		cout << "抽签后顺序如下：" << endl;
		if (this->m_Index == 1)
		{
			random_shuffle(v1.begin(), v1.end());
			for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
			{
				cout << *it << " ";
			}

		}
		else 
		{
			random_shuffle(v2.begin(), v2.end());
			for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				cout << *it << " ";
			}
			

		}
		cout << endl;
		cout << "------------------------------" << endl;
		system("pause");
		

}

//比赛
void SpeechManager::speechContest()
{
	cout << "第" << this->m_Index << "轮比赛正式开始！" << endl;
	vector<int> v_Src;//比赛人员
	multimap<double, int, greater<int>> groupScore; //临时容器，保存key分数 value 选手编号
	int num = 0;
	if (this->m_Index == 1)
	{
		v_Src = v1;

	}
	else
	{
		v_Src = v2;
	}

	//遍历所有选手比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		deque<double> d;//评委分数
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end());//升序排序
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();

		//打印平均分
		//cout << "编号:" <<*it<< " 姓名：" <<this->m_Speaker[*it].m_Name
		//	<< " 平均分：" <<avg<< endl;

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int>>::iterator it2 = groupScore.begin(); it2 != groupScore.end(); it2++)
			{
				cout << "编号："<<it2->second 
					<< "  姓名：" <<this->m_Speaker[it2->second].m_Name 
					<< " 平均分：" << this->m_Speaker[it2->second].m_Score[this->m_Index-1] 
					<< endl;
			}

			//取前三名
			int count = 0;
			for (multimap<double, int, greater<int>>::iterator it3 = groupScore.begin(); it3 != groupScore.end() && count < 3; it3++, count++)
			{
				if (this->m_Index == 1)
				{
					this->v2.push_back(it3->second);
				}
				else
				{
					this->vVictory.push_back(it3->second);
				}
			}
			groupScore.clear();
			cout << endl;

		}

	}
	cout << "------------- 第" << this->m_Index << "轮比赛完毕  ------------- " << endl;
	system("pause");
}


//显示晋级选手
void SpeechManager::showScore() 
{
	cout << "第<" << this->m_Index << ">轮晋级选手信息如下：" << endl;

	vector<int> v;
	if (this->m_Index == 1)
		v = v2;
	else
		v = this->vVictory;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name
			<< " 平均分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;;
	}
	cout << "----------------------------------" << endl;
	system("pause");
	system("cls");
	this->show_Menu();

}

//保存分数
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("result.csv", ios::out | ios::app);//追加模式

	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;//最后要换行

	ofs.close();

	this->fileIsEmpty = false;//更新标志位
	cout << "分数记录完毕！" << endl;
	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}


//读取记录
void SpeechManager::loadRecord()
{
	ifstream ifs("result.csv",ios::in);

	//判断文件存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		this->fileIsEmpty = true;
		return;
	}
	
	//判断文件清空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件已清空！" << endl;
		this->fileIsEmpty = true;
		return;
	}

	//读取数据
	this->fileIsEmpty = false;
	ifs.putback(ch);

	string data;
	int Index = 0;
	
	while (ifs >> data)//每次读取一行
	{	
		vector<string> v;
		int pos = -1;
		int start = 0;
		//cout << data;
		Index++;
		while(true)
		{		//拆分字符串
			pos=data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			else
			{
				string temp=data.substr(start, pos - start);//pos - start表示截取的字符个数
				v.push_back(temp);
				start = pos + 1;
			}
		}
		
		this->m_Record.insert(make_pair(Index, v));

	}
	ifs.close();
	//for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end();it++)
	//{
	//	cout << "第" << it->first << "届比赛结果；" << endl;
	//	cout<<" 编号:" << it->second[2] <<
	//		" 分数:" << it->second[3];
	//}
	cout << endl;

}


//显示往届记录
void SpeechManager::showRecord()
{	
	//添加文件判断
	if (this->fileIsEmpty)
	{
		cout << "记录为空！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 1; i <= this->m_Record.size(); i++)
	{
		cout << "第" << i  << "届 " <<
			"冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] << " " <<
			"亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] << " " <<
			"季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << " " << endl;
	
	}


	system("pause");
	system("cls");
}

//清空记录
void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1:是" << endl;
	cout << "2:否" << endl;

	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs("result.csv", ios::trunc);
		cout << "记录已删除！" << endl;
		//属性初始化
		this->initSpeech();

		//创建选手
		this->createSpeaker();


		//加载往届记录
		this->loadRecord();
		

	}

	system("pause");
	system("cls");
}