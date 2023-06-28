#pragma once
#include<stdio.h>
#include<iostream>
#include <deque>
#include "Tu1.h"
using namespace std;

extern int visited[MAXV];//访问数组
extern int d ;
extern int path[MAXV];

//深度优先遍历
void DFS1(MatGraph* Mat, int v);
void DFS2(AdjGraph* G, int v);
//广度优先遍历
void BFS1(MatGraph* Mat, int v);
void BFS2(AdjGraph* G, int v);

//判断是否为连通图
bool IfConnect(AdjGraph* G);

/*深度优先遍历应用*/
//1.判断两顶点间是否存在简单路径
bool ExistPath(AdjGraph* G, int u, int v);
//2.输出一条简单路径
void DispPath(AdjGraph* G, int path[], int u, int v);
//3.输出所有简单路径
void DispAllPath(AdjGraph* G, int path[], int u, int v);

/*广度优先遍历应用*/
//1.求解两顶点间的最短路径长度
int ShortPathLen(AdjGraph* G, int u, int v);