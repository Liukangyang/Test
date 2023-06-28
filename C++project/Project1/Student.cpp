#include "Student.h"

/*
int main() {
	cout << "Hello,World!" << endl;
	Student stu1;
	stu1.name = "Tom"; stu1.xuehao = 11; stu1.score = 98;
	stu1.Input_age(22); 
	stu1.Get_information();
	//构造函数的调用
	Student stu2(10);
	Student stu3 = Student(20);
	Student stu4 = 30;

	//拷贝构造函数
	Student stu5(stu4);
	cout << "学生1的年龄是：" << stu1.Get_age() << endl;
	cout << "学生2的年龄是：" << stu2.Get_age() << endl;
	cout << "学生3的年龄是：" << stu3.Get_age() << endl;
	cout << "学生4的年龄是：" << stu4.Get_age() << endl;
	cout << "学生5的年龄是：" << stu5.Get_age() << endl;


	system("pause");
	return 0;

}
*/
int Student::Get_information()
{
	cout << "学生姓名：" << name << " 年龄:" << Get_age() <<" 学号：" << xuehao << "  分数:" << score << endl;
	return 0;
}

int Student::Input_age(int stu_age)
{
	age = stu_age;
	return 0;
}

int Student::Get_age()
{
	return age;
}
