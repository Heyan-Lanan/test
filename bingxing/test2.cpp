#include<bits/stdc++.h>
using namespace std;

int a[1010],b[1010];
//每一个数的阶乘
void mul(int n)
{
    int q = 0;
    for(int i=100;i>=0;i--)
    {
        b[i] = b[i] * n + q;
        q = b[i] / 10;
        b[i] = b[i] % 10;
    }
}
//阶乘完之后的加法
void add()
{
    int q = 0;
    for(int i=100;i>=0;i--)
    {
        a[i] = a[i] + b[i] + q;
        q = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

int main()
{
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    a[100] = 1;
    b[100] = 1;
    //开始计算
    for(int i=2;i<=n;i++)
    {
        mul(i);
        add();
    }
    //找到第一个不为0的数，从这里开始输出
    int j = 0;
    for(int i=0;i<=100;i++)
    {
        if(a[i]!=0)
        {
            j = i;
            break;
        }
    }

    for(int m=j;m<=100;m++)
    {
        cout<<a[m];
    }
    return 0;
}
