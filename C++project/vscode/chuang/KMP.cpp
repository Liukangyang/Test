#include<iostream>
#include<string>
using namespace std;

/*
构造next数组
输入：
    t:子串  next:next数组首地址指针
*/
void Getnext(string t,int *next)
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<t.length()-1)
    {
        if(k==-1||t[k]==t[j])
        {
            j++;k++;
            next[j]=k;
            //next[++j]=++k;
        }
        else        
            k=next[k];
    }
}

/*
改进算法
*/
void Getnextval(string t,int *nextval)
{
    int j=0,k=-1;
    nextval[0]=-1;
    while(j<t.length())
    {
        if(k==-1||t[k]==t[j])
        {
            j++;k++;
            if(t[j]!=t[k])
                nextval[j]=k;//next[++j]=++k;
            else
                nextval[j]=nextval[k];
            
        }
        else        
            k=nextval[k];
    }

}

/*
KMP算法函数
输入：
    s:主串 t:子串
返回值：
    匹配：i-j+1子串首字符在主串中的位置
    不匹配：-1
*/
int KMP(string &s,string &t,int &count)
{
    int i=0,j=0;
    int next[ int(t.length()) ]={0};
    Getnext(t,next);//传统KMP算法
    //Getnextval(t,next); //改进KMP算法
    cout<<"next数组为： ";
    for(int k=0;k<t.length();k++)
        cout<<next[k]<<" ";
    cout<<endl;

    while(i<int(s.length()) && j<int(t.length()))   //length()返回的无符号整数，无法与整形直接比较，需强制转化。
    {
        if( j==-1 || s[i]==t[j] )
        {
            i++;
            j++;
        }
        else 
        {
            j=next[j];//子串指针回溯，主串指针不回溯
           // count++;
        } 
        count++;
    }


    if(j>=int(t.length()))
    {
        return i-j+1;  //匹配时，返回子串首字符在主串中的位置
    }
    else    
        return -1;
}



int main()
{
    while(1)
    {
        string s,t;
        cout<<"输入主串:";
        cin>>s;
        cout<<s.length()<<endl;
        cout<<"输入子串:";
        cin>>t;
        cout<<t.length()<<endl;

        int count=0;
        int result=KMP(s,t,count);
        if(result==-1) cout<<"子串与主串不匹配"<<endl;
        else cout<<"子串与主串匹配,匹配起始位置为:"<<result<<endl;
        cout<<"共匹配了 "<<count<<" 次"<<endl;
        cout<<endl;

    }
    system("pause");
    return 0;
}