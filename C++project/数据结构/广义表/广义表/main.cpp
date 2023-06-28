#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;
#define MAXSIZE 20


//广义表定义
typedef struct lnode
{
    int tag;  //标志位

    union {
        char data;   //数据域
        struct lnode* sublist;    //指向子表第一个元素
    }val;   //联合体类型

    struct lnode* link;   //指向兄弟节点
}GLNode;

/*算法设计*/
//1.求长度
int GetLength(GLNode* &g)
{
    int n = 0;
    if (g != NULL)
    {
        GLNode* g1 = g->val.sublist;
        while (g1 != NULL)
        {
            n++;
            g1 = g1->link;
        }
    }
    return n;
}

//2.求深度
int GetDepth(GLNode* &g)
{
    int maxd = 0, dep;
    GLNode* g1;
    if (g->tag == 0)
        return 0;

    g1 = g->val.sublist;
    if (g1 == NULL)
        return 1;

    while (g1 != NULL)
    {
        if (g1->tag == 1)
        {
            dep = GetDepth(g1);
            if (dep > maxd) maxd = dep;
        }
        g1 = g1->link;

    }
    return maxd + 1;
}

//3.输出广义表
void DispGL(GLNode* &g)
{
    if (g != NULL)
    {
        //cout << g->tag << endl;
        if (g->tag == 0)
        { 
            cout << g->val.data << " ";
        }
        else
        {
            cout << "(";
            //GLNode* g1 = g->val.sublist;
            if (g->val.sublist == NULL)
                cout << "#";
            else
                DispGL(g->val.sublist);
            cout << ")";
        }
        if ( (g->link) != NULL)
        {
            cout << ",";
            DispGL(g->link);
        }
    }
}

//4.生成广义表
GLNode* GetGLN(string s,GLNode* g)
{
    //GLNode* g = NULL;
   // g->link = NULL; g->val.sublist = NULL;
    GLNode* par, * bro, * cur;
    par = bro = cur = NULL;
    char c;
    int k = 0; //标记s

    GLNode* St[MAXSIZE];  //双亲节点堆栈
    int top = -1;  //栈顶指针


    for (int i = 0; i < int(s.length()) && s[i] != '\0'; i++)
    {
        c = char(s[i]);
        switch (c)
        {
        case '('://头节点
        {

            if (g != NULL)
            {
                GLNode hnode;   //递归广义表头节点
                hnode.tag = 1;
                hnode.val.sublist = NULL;
                hnode.link = NULL;
                cur = &hnode;
                par = St[top];
                if (k == 1)
                {
                    par->val.sublist = cur;
                    bro = cur;
                }
                else
                {
                    bro->link = cur;
                    bro = cur;
                }
            }
            else   //根节点
            {
                g = new GLNode;
                g->tag = 1;
                g->link = NULL;
                g->val.sublist = NULL;
                par = cur =g;
                //g = cur;
            }
            top++;
            St[top] = cur; k = 1;
            break; }

        case ',':   //兄弟节点
        {
            k = 2;        //标记兄弟节点
            break;
        }

        case ')': //子表结束
        {
            top--;    //双亲节点出栈
            break;
        }


        default://数据节点
        {

            if (g != NULL)
            {
                GLNode dnode;
                dnode.tag = 0;
                dnode.val.data = c;
                dnode.link = NULL;
                cur = &dnode;
                par = St[top];
                if (k == 1)
                {
                    par->val.sublist = cur;
                    bro = cur;
                }
                else
                {
                    bro->link = cur;
                    bro = cur;
                }
            }
            else
            {
                g = new GLNode;
                g->tag = 0;
                g->val.data = c;
                g->link = NULL;
                cur = g;
                //g = cur;
               //return g;  //广义表只有一个原子元素，直接返回
                //cout << g->tag << endl;
                //cout << g->link << endl;
                //cout << g->val.data << endl;
                //cout << (g->link == NULL) << endl;    
            }
            break;
        }

        }
    }

    return g;
}

int main()
{
    string s;
    cout << "请以括号表示法输入广义表:" << endl;
    cin >> s;
    GLNode* g=NULL;
    GLNode *gg = GetGLN(s,g);
    
   // DispGL(gg);
    cout << "长度为" << GetLength(gg) << endl;
    cout << "深度为" << GetDepth(gg) << endl;
    cout << endl;
    system("pause");
    return 0;
}