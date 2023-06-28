#include<iostream>
#include<string>
using namespace std;

/*BF算法
输入:
    mainstr:主串
    substr:子串
*/
int BruteForce(string mainstr,string substr)
{
    int mlen=mainstr.size();
    int sublen=substr.size();

    int n=mlen-sublen+1;
    for (int i=0;i<n;i++)
    {
        int j=0;
        for(;j<sublen;j++)
            if(mainstr[i+j]!=substr[j])
                break;
        if(j==sublen) return i+1; //完全匹配，则返回物理位序
    }  

    return -1; //不匹配
}

int main()
{
    string mainstr,substr;
    cout<<"字符串模式匹配：BF算法"<<endl;
    cout<<"输入主串:";
    cin>>mainstr;
    cout<<"输入子串:";
    cin>>substr;
    cout<<endl;

    int result=BruteForce(mainstr,substr);
    if(result!=-1)
    {
        cout<<substr<<"的起始位置为:"<<result<<endl;
    }
    else 
    cout<<"字串与主串不匹配"<<endl;
    system("pause");
    return 0;
}