#include "Tu2_bianli.h"

int visited[MAXV] = { 0 };
int d = -1;
int path[MAXV] = {-1};
/*深度优先遍历*/
//1.以邻接矩阵为存储结构
void DFS1(MatGraph *Mat, int v)
{
    printf("%2d,", v);
    visited[v] = 1;     //标记访问
    for (int j = 0; j < Mat->n; j++)
    {
        if (Mat->edges[v][j] == 1 && visited[j] == 0)
        {
            DFS1(Mat,j);
        }
    }
}

//2.以邻接表为存储结构
void DFS2(AdjGraph * G, int v)
{
    ArcNode* p;
    printf("%2d,", v);
    visited[v] = 1;     //标记访问
    p = G->adjlist[v].first;
    while (p != NULL)
    {
        if (visited[p->adjvex] == 0)
            DFS2(G, p->adjvex);      //递归深度遍历
        p = p->next;   //指向下一个邻接点
    }
}

/*广度优先遍历*/
//1.以邻接矩阵为存储结构
void BFS1(MatGraph* Mat, int v)
{
    int node;
    deque<int> qu;
    for (int i = 0; i < MAXV; i++) visited[i] = 0;
    printf("%2d,", v);
    visited[v] = 1;
    qu.push_back(v);

    while (!qu.empty())
    {
        node = qu[0];
        qu.pop_front();
        for (int j = 0; j < Mat->n; j++)
        {
            
            if (Mat->edges[node][j]!=0 && visited[j] == 0)
            {
                printf("%2d,",j);
                visited[j] = 1;
                qu.push_back(j);
            }
        }
        cout << endl;
    }
}

//2.以邻接表为存储结构
void BFS2(AdjGraph* G, int v)
{
     ArcNode* p;
    int node;
    deque<int> qu;
    for (int i = 0; i < MAXV; i++) visited[i] = 0;
    printf("%2d,", v);
    visited[v] = 1;
    qu.push_back(v);

    while (!qu.empty())
    {
        node = qu[0];
        qu.pop_front();
        p = G->adjlist[node].first;
        while (p != NULL)
        {
            if (visited[p->adjvex] == 0)
            {
                printf("%2d,", p->adjvex);
                visited[p->adjvex] = 1;
                qu.push_back(p->adjvex); 
            }
            p = p->next;
        }
        cout << endl; 
    }
}


//判断图G是否为连通图
bool IfConnect(AdjGraph* G)
{   
    for (int i = 0; i < MAXV; i++) visited[i] = 0;
    if (G != NULL)
    {
        //DFS2(G, 0);
        BFS2(G, 0);
        for (int i = 0; i < MAXV; i++)
        {
            if (visited[i] == 0) 
                return false;          //非连通图
        }
    }
    return true;   //连通图
}

/*深度优先遍历应用*/
//1.判断两顶点间是否存在简单路径
bool ExistPath(AdjGraph* G, int u, int v)
{
    int w; ArcNode* p;
    visited[u] = 1;
    if (u == v) return true;

    p = G->adjlist[u].first;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
        {
            if ( ExistPath(G,w, v))    //邻接点有到V的路径
                return true;  //u有到V的路径
        }
        p = p->next;   // 换下一个邻接点
    } 
    return false;    //无到达v的路径
}

//2.输出一条简单路径
void DispPath(AdjGraph* G, int path[],int u, int v)
{

    int w; ArcNode* p; int i;
    visited[u] = 1;
    d++; path[d] = u;    //将顶点u加入路径
    if (u == v)
    {
        for (int i = 0; i < d; i++)
        {
            cout << path[i] << "->";
        }
        cout << path[d];
        cout << endl;
        return;
    }

    p = G->adjlist[u].first;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
        {
            DispPath(G, path, w, v);    
        }
        p = p->next;   // 换下一个邻接点
    }

}


//3.输出所有简单路径
void DispAllPath(AdjGraph* G, int path[], int u, int v)
{
    int w; ArcNode* p; 
    visited[u] = 1;
    d++; path[d] = u;    //将顶点u加入路径
    if (u == v)
    {
        for (int i = 0; i < d; i++)
        {
            cout << path[i] << "->";
        }
        cout << path[d];
        for (int j = 0; j < MAXV; j++)
            path[j] = -1;
        cout << endl;
        visited[u] = 0;
        d--;
        return;
    }

    p = G->adjlist[u].first;
    while (p != NULL)
    {
        w = p->adjvex;
        if (visited[w] == 0)
        {
            DispPath(G, path, w, v);
        }
        p = p->next;   // 换下一个邻接点
    }
    visited[u] = 0;  //一条简单路径处理完，退回一个顶点继续遍历
    d--;
}


/*广度优先遍历应用*/
//1.求解两顶点间的最短路径长度
int ShortPathLen(AdjGraph* G, int u, int v)
{
    ArcNode* p;
    int node;
    deque<int> qu;
    for (int i = 0; i < MAXV; i++) visited[i] = 0;
    int e, e1;
    e = u;
    visited[u] = 1;
    qu.push_back(u);
    int ans = 0;   //记录层次
    int cnt = 0;  //记录每层的节点数
    int w;
    while (!qu.empty())
    {
        cnt = qu.size();  //当前层次的节点个数
        for (int i = 0; i < cnt; i++)
        {
            e = qu[0];
            qu.pop_front();
            if (e == v) return ans;

            p = G->adjlist[e].first;
            while (p != NULL)
            {
                w = p->adjvex;
                if (visited[w] == 0)
                {
                   // printf("%2d,", p->adjvex);
                    e1 = w;
                    qu.push_back(w);
                    visited[w] = 1;
                    
                }
                p = p->next;
            }
            cout << endl;
        }
        ans++;

    }
}