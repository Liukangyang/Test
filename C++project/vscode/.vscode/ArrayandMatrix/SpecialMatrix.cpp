#include<iostream>
#include<string>
using namespace std;


/*
对称矩阵压缩存储
*/
int* Symmettycompress(int A[][3],int n,int &len)
{   
    len=n*(n+1)/2;
    int i=0,j=0,k=0;
    int *B= new int[len];
    
    //按行存储
    // for(i=0;i<n;i++)
    //     for(j=i;j<n;j++)
    //     {
    //         B[k]=A[i][j];
    //         k++; 
    //     }

    //按列存储
     for(j=0;j<n;j++)
        for(i=0;i<=j;i++)
        {
            cout<<A[i][j]<<" ";
            B[k]=A[i][j];
            k++;   
        }
        cout<<endl;

    return B;
}

void  test1()
{
     int A[][3]={
        1,2,3,2,4,8,3,8,6
    };
    int len=0;
    int *B=Symmettycompress(A,3,len);
    for(int i=0;i<len;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
}

/*
三角矩阵压缩存储
*/
int* TriangleMatrixycompress(int A[][3],int n,int &len)
{
    len=n*(n+1)/2+1;
    int i=0,j=0,k=0;
    int *B= new int[len];

    //按行存储
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            B[k]=A[i][j];
            k++; 
        }
        B[k]=A[n-1][0];


    return B;
}

void test2()
{
      int A[][3]={
        1,2,3,100,4,5,100,100,6
    };
    int len=0;
    int *B=TriangleMatrixycompress(A,3,len);
    for(int i=0;i<len;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    //test1();
    test2();

    system("pause");
    return 0;
}