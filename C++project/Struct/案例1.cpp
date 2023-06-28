#include <iostream>
#include<string>
#include<vector>
using namespace std;
#define NUMOFT 3
#define NUMOFS 5
//学生结构体
struct Student
{
	string stu_name;
	int score;
};

//老师结构体
struct Teacher
{
	string tea_name;
	//vector<Student> stu;//学生容器
	struct Student stu[5] ;
};

//赋值函数
void allocateSpace(Teacher *tea, int len)
{
	string teaname = "Teacher";
	string stuname = "Student";
	string nameseed = "12345";
	for (int i = 0; i < len; i++)
	{
		tea[i].tea_name = teaname+nameseed[i];

		for (int j = 0; j < 5; j++)
		{
			struct Student s;
			s.stu_name = "Student_";
			s.stu_name += nameseed[j];
			cout << "学生名赋值" << endl;
			s.score = rand() % 61 + 40;//(40~100)

			////tea[i].stu.push_back(s);
			tea[i].stu[j] = s;

			//tea[i].stu[j].stu_name = stuname + nameseed[j];
			//tea[i].stu[j].score = rand() % 61 + 40;
		}

	}
}

void printTeachers(Teacher *tea, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << "老师:" << tea[i].tea_name << endl;
		//cout << "对应学生：" << endl;
		//for (vector<Student>::iterator it = tea[i].stu.begin(); it != tea[i].stu.end(); it++)
		//{
		//	cout <<"\t姓名：" << it->name <<" 分数：" << it->score << endl;
		//}
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tea[i].stu[j].stu_name << " 分数：" << tea[i].stu[j].score << endl;
		}

	}
}


//int main()
//{
//	srand((unsigned int)time(NULL));
//	//1。创建老师结构体数组
//	 Teacher tea[3];
//
//	//2.赋值
//	int len = sizeof(tea)/sizeof(tea[0]);   //len=3
//	allocateSpace(tea, len);
//
//
//	////3.打印输出
//	//printTeachers(tea, len);
//
//	return 0;
//}
