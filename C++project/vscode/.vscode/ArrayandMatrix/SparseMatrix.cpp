#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;
#define M  5  //行数
#define N  5  //列数
#define MaxSize 20   //非零元素最大个数

//三元组类型
typedef struct 
{
    int r;   //行下标
    int c;   //列下标
    int elem;   // 元素值
}TupNode;


//三元组顺序表类型
typedef struct
{
    int rows;   //行数
    int cols;   //列数
    int nums ;   //非零元素数量
    TupNode data[MaxSize];  //三元组顺序表数组
}TSMatrix;

//从稀疏矩阵创建三元组顺序表
void GetMat(TSMatrix &t, int A[M][N])
{
    int i=0,j=0;
    t.rows=M;t.cols=N;
    t.nums=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(A[i][j]!=0)
            {   
               // cout<<A[i][j]<<" "<<endl;
                t.data[t.nums].r=i;
                t.data[t.nums].c=j;
                t.data[t.nums].elem=A[i][j];
                t.nums++;
            }
        }
    }
}

//三元顺序表的赋值
bool InsertValue(TSMatrix &t,int e,int i,int j)
{
    int k =0,kl;
    if(i>=t.rows || j>=t.cols)
        return false;

    while(k < t.nums && i>t.data[k].r) k++;
    while(k < t.nums && i==t.data[k].r && j >t.data[k].c) k++;
    
    if(t.data[k].r==i && t.data[k].c==j)
    {
        t.data[k].elem=e;
    }
    else
    {
        for(kl=t.nums-1;kl>=k;kl--)
        {
            t.data[kl+1].r=t.data[kl].r;
            t.data[kl+1].c=t.data[kl].c;
            t.data[kl+1].elem=t.data[kl].elem;
        }
        t.data[k].elem=e;
        t.data[k].r=i;t.data[k].c=j;
        t.nums++;
    }
    return true;
}

//将指定位置元素赋给变量
bool AssignElem(TSMatrix &t,int &x,int i,int j)
{
    int k=0;
    if(i>=t.rows || j>=t.cols)
        return false;

    while(k < t.nums && i>t.data[k].r) k++;
    while(k < t.nums && i==t.data[k].r && j >t.data[k].c) k++;
    
    if(t.data[k].r==i && t.data[k].c==j)
    {
        x=t.data[k].elem;
    }
    else
        x=0;

    return true;

}


//输出三元组
void DispMat(TSMatrix t)
{
    if(t.nums==0) cout<<"矩阵无非零元素"<<endl;
    else
    {
        printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
        printf("\t-------------------\n");
        for(int k=0;k<t.nums;k++)
           printf("(%d, %d ,%d) , ",t.data[k].r,t.data[k].c,t.data[k].elem);
    }
    cout<<endl;

}


//三元组顺序表测试
void test1()
{
    int A[5][5]=
    {
        {1,2,0,0,0},{0,0,0,0,6},
        {0,0,0,0,0},{4,0,0,2,0},{0,0,8,0,0}
    };
    TSMatrix t;

    GetMat(t,A);
    DispMat(t);

    bool r=InsertValue(t,10,1,4);
    if(r==true) DispMat(t);

    int x;
    AssignElem(t,x,3,4);
    cout<<"获取的值为："<<x<<endl;
}


//稀疏矩阵十字链表
typedef struct mtxn
{
    int row;
    int col;
    union{
        int value;
        struct mtxn *link;
    }tag;

    struct mtxn *right;
     struct mtxn *down;
}MatNode;


//todo
//数据节点
typedef struct dnode
{
    int data;
    struct dnode* next;
}DType;

//头节点
typedef struct hnode
{
    DType* next;
    struct hnode *link;
}HType;

void GetLianbiao(vector<vector<int>> &a,HType &hnode)
{
    int k=a.size();
    HType *p1=NULL;
    HType *cur1=NULL;
    p1=cur1=&hnode;
    for(int i=0;i<k;i++)
    {
        HType h;
        h.link=NULL;h.next=NULL;
        cur1=&h;
        p1->link=cur1;p1=cur1;

        DType *p2=NULL;
        DType *cur2=NULL;
        for(int j=0;j<a[i].size();j++)
        {
            DType d;
            d.data=0; d.next=NULL;
            d.data=a[i][j];
            //cout<<d.data;
            if(j==0) 
            {
                h.next=&d;
                p2=cur2=&d;
            }
            else
            {
                cur2=&d;
                p2->next=cur2;
                p2=cur2;
            }

        }

    }
   // return &hnode;
}

void Disp(HType& hnode)
{
    HType* h = &hnode;
    DType* d = NULL;
    cout << "{";
    while (h ->link!= NULL)
    {
        h = h->link;
        if(h->next!=NULL)
        { 
            cout << "{";
            d = h->next;
            //cout << d->data;
          while (d != NULL)
          {
                cout << int(d->data);//bug
                d = d->next;
          }
          cout << "} ";
          d = NULL;
        }
    }
    cout << "}";
}

//十字链表测试
void test2()
{
    vector<int> a1={1,3};
    vector<int> a2={1,7,8};
    vector<int> a3={5,6};
    vector<vector<int>> a={a1,a2,a3};

    HType hnode;
    hnode.link=NULL;
    hnode.next=NULL;

    GetLianbiao(a,hnode);
    Disp(hnode);

}

int main()
{

    //test1();
    test2();

    system("pause");
    return 0;
}