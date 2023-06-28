#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>

#define CEHUA  0//策划
#define MEISHU 1//美术
#define YANFA  2//研发

//员工类
class Worker
{
public:
	Worker(string name,int salary)
	{
		this->w_Name = name;
		this->w_Salary = salary;
	}
	string w_Name;
	int w_Salary;
};
//创建员工
void createWorker(vector<Worker>& v)
{
	string w = "ABCDEFGHIJ";
	for (int i = 0; i < w.size(); i++)
	{
		//string name = "worker" + w[i];
		string name = "员工";
		name += w[i];
		Worker worker(name, rand() % 10000 + 10000);//10000~19999
		v.push_back(worker);
	}
}


//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int ID = rand() % 3;
		m.insert(make_pair(ID, *it));
	}
}

//分部门展示信息
void showWorkerByGourp(multimap<int, Worker>& m)
{
	//第1种方式
	/*
	//策划部门
	int count = 0;
	multimap<int, Worker>::iterator it = m.find(CEHUA);//返回初始位置
	cout << "策划部门:" << endl;
	for (; it != m.end() && count < m.count(CEHUA); it++, count++)
	{
		cout  << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary << endl;
	}
	cout << "---------------------------------------" << endl;

	cout << "美术部门：" << endl;
	count = 0; it = m.find(MEISHU);
	for (; it != m.end() && count < m.count(MEISHU); it++, count++)
	{
		cout << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary << endl;
	}
	cout << "---------------------------------------" << endl;

	cout << "研发部门：" << endl;
	count = 0; it = m.find(YANFA);
	for (; it != m.end() && count < m.count(YANFA); it++, count++)
	{
		cout << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary << endl;
	}
	cout << "---------------------------------------" << endl;
	*/

	//第2种方式
	//cout << "策划部门:" << endl;
	//for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	if(it->first==CEHUA)
	//		cout << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary << endl;
	//}

	//cout << "美术部门:" << endl;
	//for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	if (it->first == MEISHU)
	//		cout << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary << endl;
	//}

	//cout << "研发部门:" << endl;
	//for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	if (it->first == YANFA)
	//		cout << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary << endl;
	//}

	//----------------------------第一种方法比较节省时间

	//第3种方法
	multimap<int, Worker> m1, m2, m3;
	vector<multimap<int, Worker>> vv;
	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->first == CEHUA)
			m1.insert(*it);
		else if (it->first == MEISHU)
			m2.insert(*it);
		else m3.insert(*it);
	}
	vv.push_back(m1); vv.push_back(m2); vv.push_back(m3);
	int count = 0;

	for(vector<multimap<int, Worker>>::iterator it=vv.begin();it!=vv.end();it++)
	{
		count++;
		if (count == 1) cout << "策划部门：" << endl;
		else if (count == 2) cout << "美术部门：" << endl;
		else cout << "研发部门：" << endl;

		for (multimap<int, Worker>::iterator itt = (*it).begin(); itt != (*it).end(); itt++)
		{
			cout << "  姓名：" << itt->second.w_Name << "  工资:" << itt->second.w_Salary << endl;
		}
	}

	//------------------------------第3种方式速度也比较快，但是比较耗费空间

}

int main()
{
	//初始化随机数种子
	srand((unsigned int)time(NULL));

	vector<Worker> v;
	createWorker(v);
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->w_Name << " 工资：" << it->w_Salary << endl;
	}
	cout << "-------------------------------------------" << endl;
	multimap<int,Worker> m;
	setGroup(v,m);
	cout << "公司所有招聘员工信息：" << endl;
	for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "部门：" << it->first << "  姓名：" << it->second.w_Name << "  工资:" << it->second.w_Salary<<endl;
	}
	cout << "-------------------------------------------" << endl;
	showWorkerByGourp(m);

	return 0;
}