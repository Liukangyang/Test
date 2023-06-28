#include"Tu1.h"
#include"MiniTree.h"


/*最小生成树求解*/

//1.Prim算法
void Prim(MatGraph* g, int v)
{
	int closest[MAXV] ;   //候选边在U中的关联顶点
	int lowcost[MAXV] ;   //候选边的权值
	int *Treepath=new int[MAXV];   //最小生成树路径
	int temp=0;
	//map<int, int> edges;  //记录最小生成树的边
	int mindest ;      
	int k;          
	//Treepath[0] = v;
	//初始化
	for (int i = 0; i < g->n; i++)
	{
		lowcost[i] = g->edges[v][i];
		closest[i] = v;
	}


	for (int i = 0; i < g->n-1; i++)
	{
		 mindest = INF;
		 for (int j = 0; j < g->n; j++)
		 {
			 if (lowcost[j] != 0 && lowcost[j] < INF && lowcost[j]<mindest)
			 {
				 mindest = lowcost[j];
				 k = j;
			 }
		 }
		 
		 printf("边(%d,%d)：权值为%d\n", closest[k],k,g->edges[closest[k]][k]);
		 lowcost[k] = 0;  //将节点K加入集合U中
		 
		 //修改候选边集
		 for (int j = 0; j < g->n; j++)
		 {
			 if (lowcost[j] != 0 && g->edges[k][j] < lowcost[j])
			 {
				 lowcost[j] = g->edges[k][j];
				 closest[j] = k;
			 }
		 }
	}
	

}

//2.Kruskal算法
int*& Kruskal(MatGraph* g, Edge*& E)
{
	int sn1, sn2;   //连通分量编号
	int u1, v1;  
	int k = 0;     //vset[]访问下标
	int m = 1;     //边数统计
	int vset[MAXV];  //连通编号数组
	//Edge E[MAXSIZE];    //边结构体数组
	int* if_select = new int[MAXSIZE] {-1}; //标记数组

	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++)
		{
			if (g->edges[i][j] != 0 && g->edges[i][j] != INF)
			{
				E[k].w = g->edges[i][j];
				E[k].u = i; E[k].v = j;
				k++;
			}
		}

	for (int i = 0; i < MAXSIZE; i++)
	{
		E[i].w = abs(E[i].w);   
	}

	//对E数组按照边权值排序(从小到大:冒泡排序)
	Edge temp;
	for (int i = 0; i < MAXSIZE-1; i++)
	{
		for (int z = 0; z < MAXSIZE - 1 - i; z++)
		{
			if (E[z].w > E[z+1].w)       //交换
			{
				temp = E[z + 1];
				E[z + 1] = E[z];
				E[z] = temp;
			}
		}
	}


	for (int i = 0; i < g->n; i++)
		vset[i] = i;
	k = 0;

	while (m<g->n)
	{
		u1 = E[k].u; v1 = E[k].v;
		sn1 = vset[u1]; sn2 = vset[v1];
		if (sn1 == sn2)    //属于同一连通分量
		{
			k++;
			continue;
		}
		else  //属于不同连通分量
		{
			//printf("（%d,%d）:%d\n", u1, v1, E[k].w);  
			if_select[k] = 1;   //加入该边
			for (int i = 0; i < g->n; i++)   //修改连通编号
			{
				if (vset[i] == sn2) vset[i] = sn1;
			}
			k++;   
			m++;   //边数目加一
		}
	}
	return if_select;
}



/*最短路径长度求解*/
//1.单源最短路径算法
int*& Dijkstra(MatGraph* g, int v,int *&dist,int *&S)
{
	//int S[MAXV] = {0};      //标记数组
	//int* S = new int[MAXV] {0};
	//int path[MAXV] = {-1};    
	int* path = new int[MAXV] {-1};   //最短路径前继节点
	//int dist[MAXV] = { 0 };   //
	//int* dist = new int[MAXV] {0};    //最短路径
	int m = 0;
	int k = -1;

	//初始设置
	S[v] = 1;
	path[v] = -1;
	dist[v] = 0;
	for (int i =0; i < g->n; i++)
	{
			dist[i] = g->edges[v][i];
			S[i] = 0;
			//path[i] = v;   
			if (g->edges[v][i] < INF)
				path[i] = v;
			else 
				path[i] = -1;
	}

	//算法迭代
	while (m<g->n)
	{
		int miniest = INF;
		for (int i = 0; i < g->n; i++)
		{
			if (S[i] == 0 && dist[i] < miniest)
			{
				miniest = dist[i];
				k = i;
			}
		}
		if (miniest == INF) break;

		S[k] = 1;
		for (int j = 0; j < g->n; j++)   //修改剩余节点的最短路径长度
		{
			if (S[j] == 0 && dist[k] + g->edges[k][j] < dist[j])
			{
				dist[j] = dist[k] + g->edges[k][j];
				path[j] = k;
			}
		}
		m++;   //S集合顶点数+1
	}
	return path;
}

//输出各条最短路径长度
void DispPath(MatGraph* g,int v,int *path,int *dist,int *S)
{
	int aPath[MAXSIZE];   //每个节点的最短路径
	int d = 0;
	int u=-1;
	for(int i=0;i<g->n;i++)
	{
		//cout << i << endl;
		if (i != v && S[i] == 1)
		{
			aPath[d++] = i;
			u = path[i];       //  第一哥路径前继节点
			while (u!=v)       //路径赋值
			{
				aPath[d++] = u;
				u = path[u];
			}
			aPath[d++] = v;           // 加入源节点
			cout << "从顶点" << v << "出发" << endl;
			cout << "到节点" << i << "的最短路径长度为：" << dist[i] << endl;
			cout << "最短路径为:";
			for (int j = d - 1; j > 0; j--)      //逆序输出路径
			{
				cout << aPath[j] << "->";
			}
			cout << aPath[0] << endl << endl;   //输出源节点
		}
		d = 0;
		u = -1;
	}
}


//2.多源最短路径算法
void Floyd(MatGraph* g)
{
	int A[MAXV][MAXV];          //记录每次迭代时的节点间最短路径长度
	int path[MAXV][MAXV];       //记录每次迭代时的节点间最短路径的后继节点（前继节点）
	int k;                //迭代次数

	//初始化
	for(int i=0;i<g->n;i++)
		for (int j = 0; j < g->n; j++)
		{
			A[i][j] = g->edges[i][j];             //初始时A等于邻接矩阵
			if (i != j && g->edges[i][j] < INF)
				path[i][j] = i;                // 初始时节点j的前继节点为i
			else
				path[i][j] = -1;              //i和j无边
		}

	//算法迭代
	for (k = 0; k < g->n; k++)
	{
		for (int i = 0; i < g->n; i++)
			for (int j = 0; j < g->n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];    //修改最短路径长度
					path[i][j] = path[k][j];        //修改最短路径前继节点
				}
			}
	}

	//输出最短路径
	k = -1;
	int s,d;
	int apath[MAXV];
	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++)
		{
			if (A[i][j] != INF && i != j)
			{
				printf("从节点%d到节点%d的最短路径长度为：%d\n", i, j, A[i][j]);
				k = path[i][j];
				d = 0; apath[d] = j;
				while (k != i)
				{
					apath[++d] = k;
					k = path[i][k];
				}
				apath[++d] = i;

				//输出最短路径
				cout << "最短路径为：";
				for (s = d; s > 0; s--)
				{
					cout << apath[s] << "->";
				}
				cout << apath[s] << endl<<endl;
			}
		}

}