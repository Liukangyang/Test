#include<iostream>
#include<string>
#include <stack>
#include<queue>
using namespace std;

//stack
void test24()
{
	stack<int> s;
	s.push(10); s.push(20); s.push(30); s.push(40);
	cout << "大小为：" << s.size() << endl;

	while (!s.empty())
	{
		cout << s.top() << " ";  //获取栈顶元素
		s.pop();//弹出栈顶元素
	}
	cout << endl;
	cout << "大小为：" << s.size() << endl;
}

//queue
void test25()
{
	queue<int> q;
	//入队
	q.push(10); q.push(20); q.push(30); q.push(40);
	cout << "大小为：" << q.size() << endl;

	//依次获取元素
	while (!q.empty())
	{
		cout << q.front() << " ";  //获取队头元素
		q.pop();//出队
	}
	cout << endl;
	cout << "大小为：" << q.size() << endl;


}
//int main()
//{
//	test25();
//	return 0;
//}