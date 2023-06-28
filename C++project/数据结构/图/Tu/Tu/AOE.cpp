#include<stdio.h>
#include<iostream>
#include"AOE.h"

//拓扑排序1（顺序堆栈）
void TopSort(AdjGraph* G)
{
	 stack<int> ss; //  用堆栈保存入度为0的点
	 int indegree[MAXV];   //入度数组
	 for (int i = 0; i < G->n; i++) indegree[i] = 0;
	 for (int i = 0; i < G->n; i++)    //计算每个顶点的初始入度
	 {
		 ArcNode* p = G->adjlist[i].first;
		 while (p != NULL)
		 {
			 int w = p->adjvex;
			 indegree[w]++;   //i->w
			 p = p->next;
		 }
	 }

	 for (int i = 0; i < G->n; i++)//将初始所有入度为0的点都加入堆栈中
		 if (indegree[i] == 0)
			 ss.push(i);

	 while (!ss.empty())   //堆栈不空时循环
	 {
		 int k = ss.top();   //获取栈顶顶点
		 cout << k<<",";
		 ss.pop(); //退出栈顶顶点，即删除该点
		 ArcNode* p = G->adjlist[k].first;
		 while (p != NULL)
		 {
			 int w = p->adjvex;
			 indegree[w]--;                         //删除出边
			 if (indegree[w] == 0) ss.push(w);      //若入度为0 ，则加入堆栈
			 p = p->next;
		 }	 
	 }
}

//拓扑排序2（顺序队列）
deque<int> TopSort2(AdjGraph* G)
{
	deque<int> queue; //  用队列保存入度为0的点
	int front=0, rear=-1;   //头指针和尾指针
	int indegree[MAXV];   //入度数组
	for (int i = 0; i < G->n; i++) indegree[i] = 0;
	for (int i = 0; i < G->n; i++)    //计算每个顶点的初始入度
	{
		ArcNode* p = G->adjlist[i].first;
		while (p != NULL)
		{
			int w = p->adjvex;
			indegree[w]++;   //i->w
			p = p->next;
		}
	}

	for (int i = 0; i < G->n; i++) //将初始所有入度为0的点都加入队列中
		if (indegree[i] == 0)
		{
			queue.push_back(i); rear++;
		}


	while (rear>=front)   //堆栈不空时循环
	{
		int k = queue[front];//获取队首顶点
		//cout << k << ",";
		front++;        //删除该顶点
		ArcNode* p = G->adjlist[k].first;
		while (p != NULL)
		{
			int w = p->adjvex;
			indegree[w]--;                         //删除出边
			if (indegree[w] == 0) { queue.push_back(w); rear++; }      //若入度为0 ，则加入队列
			p = p->next;
		}
	}
	return queue;
}

//关键路径
void CriticalPath(AdjGraph* G,deque<int> qu)
{
	int k = 0;
	int ve[MAXV] = {0};
	int vl[MAXV] = {0};
	ArcNode* p;

	//1.计算每个顶点的ve
	ve[0] = 0;   //ve[x]=0
	for (int i = 0; i < qu.size(); i++)  
	{
		k = qu[i];
		p = G->adjlist[k].first;   
		while (p != NULL)
		{	
			if (ve[k] + p->weight > ve[p->adjvex]) ve[p->adjvex] = ve[k] + p->weight;
			p = p->next;
		}
	}

	//2.计算每个顶点的vl
	for (int i = 0; i < G->n; i++) vl[i] = ve[qu.size() - 1];//所有顶点的vl均设置为ve[y]

	for (int i = qu.size()-1; i >=0; i--)   
	{
		k = qu[i];
		p = G->adjlist[k].first;   
		while (p != NULL)
		{
			if (vl[p->adjvex] - p->weight < vl[k]) vl[k] = vl[p->adjvex] - p->weight;
			p = p->next;
		}
	}

	//3. 计算每个活动的e和l并判断关键活动
	int e = 0,l = 0;
	cout << "关键活动为：";
	for (int i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].first;
		while (p != NULL)
		{
			e = ve[i]; 
			l = vl[p->adjvex] - p->weight;
			if (l == e) cout << "<" << i << "," << p->adjvex << ">,";
			p = p->next;
		}

	}
}
