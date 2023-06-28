#pragma once
#include<stdio.h>
#include<iostream>
using namespace std;
#define MAXV  10    //最多顶点数
#define MAXSIZE 20    //最多边数
#define INF 100000

/*邻接矩阵类型*/
typedef struct        //顶点类型
{
    int no;
    //int data;
}VertexType;

typedef struct        //邻接矩阵类型定义
{
    int edges[MAXV][MAXV];   //邻接矩阵数组
    VertexType vexs[MAXV];   //顶点数组
    int n, e;                //顶点数、边数
}MatGraph;


/*邻接表类型*/
typedef struct arcnode{       //边结点类型
    int adjvex;
    arcnode* next;
    int weight;
}ArcNode;

typedef struct  {            //头结点类型
    int no;
    ArcNode* first;
}VNode;
  
typedef struct  {            //邻接表类型定义
    VNode adjlist[MAXV];     //头结点数组
    int n, e;     
}AdjGraph;

/*图基本运算*/
//1.创建图
void CreateAdj(AdjGraph*& G, MatGraph*& Mat);

//2.销毁图
void DestroyAdj(AdjGraph*& G);

//3.输出图
void DispAdj(AdjGraph*& G);

//4.邻接表转邻接矩阵
void ListToMat(AdjGraph*& G, MatGraph*& Mat);

