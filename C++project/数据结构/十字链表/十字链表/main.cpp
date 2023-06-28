#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;

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
    struct hnode* link;
}HType;

void GetLianbiao(vector<vector<int>>& a, HType& hnode)
{
    int k = a.size();
    HType* p1 = NULL;
    HType* cur1 = NULL;
    DType* p2 = NULL;
    DType* cur2 = NULL;
    p1 = cur1 = &hnode;
    for (int i = 0; i < k; i++)
    {
        HType h;
        h.link = NULL; h.next = NULL;
        cur1 = &h;
        p1->link = cur1; p1 = cur1;

        for (int j = 0; j < a[i].size(); j++)
        {
            DType d;
            d.data = 0; d.next = NULL;
            d.data = a[i][j];
            //cout<<d.data;
            if (j == 0)
            {
                h.next = &d;
                p2 = cur2 = &d;
            }
            else
            {
                cur2 = &d;
                p2->next = cur2;
                p2 = cur2;
            }

        }
        p2 = NULL;
        cur2 = NULL;

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
                cout << (d->data);
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
    vector<int> a1;
    a1.push_back(1); a1.push_back(3);
    vector<int> a2;
    a2.push_back(1); a2.push_back(7); a2.push_back(8);
    vector<int> a3 ;
    a3.push_back(5); a3.push_back(6);
    vector<vector<int>> a ;
    a.push_back(a1); a.push_back(a2); a.push_back(a3);

    HType hnode;
    hnode.link = NULL;
    hnode.next = NULL;

    GetLianbiao(a, hnode);
    Disp(hnode);

}

int main()
{

    test2();

    system("pause");
    return 0;
}