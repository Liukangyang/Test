#include "Tu1.h"
#include "Tu2_bianli.h"
#include"MiniTree.h"
#include "AOE.h"

//基本构造和遍历
void test1(MatGraph* &Mat, AdjGraph* &G, MatGraph* &Mat2,int A[MAXV][MAXV])
{

	//基本运算
	cout << "邻接表结构:" << endl;
	CreateAdj(G, Mat);
	DispAdj(G);

	cout << "转化为邻接矩阵:" << endl;
	ListToMat(G, Mat2);
	for (int i = 0; i < Mat2->n; i++)
	{
		for (int j = 0; j < Mat2->n; j++)
			cout << Mat2->edges[i][j] << " ";
		cout << endl;
	}
	//遍历测试
	////1.深度优先遍历
	//int v;
	//cout << "指定任意初始顶点：";
	//cin >> v;
	//cout << "深度优先遍历结果为：" << endl;
	////DFS1(Mat, v); cout << endl;
	//DFS2(G, v); cout << endl;

	////2.广度优先遍历
	//cout << "广度优先遍历结果为：" << endl;
	//BFS1(Mat, v);
	////BFS2(G, v);

	////判断是否为连通图
	//if (IfConnect(G))
	//	cout << "图G为连通图" << endl;
	//else
	//	cout << "图G不为连通图" << endl;

}

//遍历应用
void test2(AdjGraph*& G)
{
	int u, v;
	for (int i = 0; i < G->n; i++)
		visited[i] = 0;

	cout << "请输入起点:";
	cin >> u;
	cout <<endl<< "请输入终点:";
	cin >> v;

	if (ExistPath(G, u, v))
	{
		cout << "存在简单路径。" << endl;
	}
	else
		cout << "不存在简单路径！" << endl;

	//for (int i = 0; i < G->n; i++)
	//	visited[i] = 0;
	//cout << "路径为:";
	//DispPath(G, path, u, v);

	for (int i = 0; i < G->n; i++)
		visited[i] = 0;
	cout << "所有路径为:" << endl;
	DispAllPath(G, path, u, v);
	cout << endl;

	cout << "最短路径长度为:" << ShortPathLen(G, u, v) << endl;
}

//最小生成树算法测试
void test3()
{
	MatGraph* Mat = new MatGraph;
	Mat->n = 7;
	int A[7][7] = { 
		0,28,INF,INF,INF,10,INF,
		28,0,16,INF,INF,INF,14,
		INF,16,0,12,INF,INF,INF,
		INF,INF,12,0,22,INF,18,
		INF,INF,INF,22,0,25,24,
		10,INF,INF,INF,25,0,INF,
		INF,14,INF,18,24,INF,0,
	};
	for (int i = 0; i < Mat->n; i++)
		for (int j = 0; j < Mat->n; j++)
			Mat->edges[i][j] = A[i][j];
	cout << "Prim算法:" << endl;
	cout << "输入起始点：";
	int v  ;
	cin >> v;
	Prim(Mat, v);
	cout << endl;

	Edge* E = new Edge[MAXSIZE];
	int* select = new int[MAXSIZE];
	cout << "Kruskal算法:" << endl;
	select = Kruskal(Mat,E);
	for (int i = 0; i < MAXSIZE; i++)
	{
		if(select[i]==1) 
			printf("（%d,%d）:%d\n", E[i].u, E[i].v, E[i].w);
	}


}

//测试4
void test4()
{
	MatGraph* Mat = new MatGraph;
	Mat->n = 7;
	int A[7][7] = {
		0,4,6,6,INF,INF,INF,
		INF,0,1,INF,7,INF,INF,
		INF,INF,0,INF,6,4,INF,
		INF,INF,2,0,INF,5,INF,
		INF,INF,INF,INF,0,INF,6,
		INF,INF,INF,INF,1,0,8,
		INF,INF,INF,INF,INF,INF,0
	};
	for (int i = 0; i < Mat->n; i++)
		for (int j = 0; j < Mat->n; j++)
			Mat->edges[i][j] = A[i][j];

	int v = 0;
	int* S = new int[MAXV] {0};
	int* dist = new int[MAXV] {0};
	int* path;
	//单源最短路径
	//path= Dijkstra(Mat, v, dist, S);
	//DispPath(Mat, v, path, dist, S);

	//多源最短路径
	Floyd(Mat);
}

void test5()
{
	MatGraph* Mat=new MatGraph;
	AdjGraph* G=new AdjGraph;
	int A[4][4] = {
		0,2,1,0,
		0,0,0,3,
		0,0,0,2,
		0,0,0,0
	};
	Mat->n = 4;
	for (int i = 0; i < Mat->n; i++)
		for (int j = 0; j < Mat->n; j++)
			Mat->edges[i][j] = A[i][j];

	//构造邻接表
	cout << "邻接表结构:" << endl;
	CreateAdj(G, Mat);
	DispAdj(G);

	//拓扑排序
	 //TopSort(G);
	deque<int> queue;
	queue = TopSort2(G);
	for (int i = 0; i < queue.size(); i++)
	{
		cout << queue[i] << ",";
	}
	cout << endl;

	//求解关键路径
	CriticalPath(G, queue);

}
int main()
{
	//MatGraph* Mat = new MatGraph;
	//AdjGraph* G = new AdjGraph;
	//MatGraph* Mat2 = new MatGraph;
	//Mat->n = 5;
	//int A[MAXV][MAXV] = { 0,1,0,1,1, 1,0,1,1,0, 0,1,0,1,1,
	//	1,1,1,0,1, 1,0,1,1,0,
	//};
	//for (int i = 0; i < Mat->n; i++)
	//	for (int j = 0; j < Mat->n; j++)
	//		Mat->edges[i][j] = A[i][j];

	//测试1 ： 构造和遍历
	//test1(Mat, G, Mat2,A);

	//测试2 ： 深度遍历的应用
	//test2(G);

	//测试3  ：最小生成树
	//test3();

	//测试4 ： 最短路径
	//test4();
	// 
	//测试5：AOE网拓扑排序和关键路径
	test5();
	//G = NULL;
	return 0;
}