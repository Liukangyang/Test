#pragma once
#pragma once
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
typedef struct {
	int u, v;   //边的关联顶点
	int w;     //边权值
}Edge;

//求解最小生成树
void Prim(MatGraph* g, int v);
int*& Kruskal(MatGraph* g, Edge*& E);

//求解最短路径
int*& Dijkstra(MatGraph* g, int v, int*& dist, int*& S);
void DispPath(MatGraph* g, int v, int* path, int* dist, int* S);
void Floyd(MatGraph* g);