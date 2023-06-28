#include"Tu1.h"

/*图基本运算*/
//1.创建图
void CreateAdj(AdjGraph*& G, MatGraph*& Mat) {
	int i, j;
	int n = Mat->n;
	ArcNode* p=NULL;
	G->n = Mat->n; G->e = Mat->e;
	for (i = 0; i < n; i++)
	{
		G->adjlist[i].first = NULL;
		G->adjlist[i].no = i ;
	}
	for(i=0;i<n;i++)
		for (j = n-1; j >=0; j--)
		{
			if ( Mat->edges[i][j] != 0 )
			{
				p = new ArcNode;
				p->adjvex = j;
				p->weight = Mat->edges[i][j];
				p->next = G->adjlist[i].first;  //头插法
				G->adjlist[i].first = p;
			}
		}
}

//2.销毁图
void DestroyAdj(AdjGraph*& G) {
	int i; ArcNode* pre; ArcNode* p;
	for (i = 0; i < G->n; i++)
	{
		pre = G->adjlist[i].first;
		if (pre != NULL)
		{
			p = pre->next;
			while (p != NULL)
			{
				free(pre);
				pre = p;
				p = p->next;
			}
			free(pre);
		}
	}
	free(G);
}

//3.输出图
void DispAdj(AdjGraph*& G) {
	int i;ArcNode* p;
	if (G == NULL) cout << "图不存在！" << endl;
	else
	{
		for (i = 0; i < G->n; i++)
		{
			cout << G->adjlist[i].no << " : ";
			p = G->adjlist[i].first;
			while (p!= NULL)
			{
				printf("%3d[%d]", p->adjvex, p->weight);
				p = p->next;
			}
			cout << "#" << endl;
		}
	}
}

//4.邻接表转邻接矩阵
void ListToMat(AdjGraph*& G, MatGraph*& Mat) {
	int i;
	ArcNode* p;
	Mat->n = G->n; Mat->e = G->e;
	for (int i = 0; i < Mat->n; i++)
		for (int j = 0; j < Mat->n; j++)
			Mat->edges[i][j] = 0;
	for (i = 0; i < G->n; i++)
	{
		p = G->adjlist[i].first;
		while (p != NULL)
		{
			Mat->edges[i][p->adjvex] = p->weight;
			p = p->next;
		}
	}
}