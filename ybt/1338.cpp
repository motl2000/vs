//1338：【例3-3】医院设置
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int maxn=0x3f3f3f3f;          //定义一个最大值
int a[101];
int g[101][101];                    //邻接表
int main()
{
    int n;
    cin>>n;
    int l,r;
    for(int i=1;i<=n;i++)           //初始化
        for(int j=1;j<=n;j++)
            g[i][j]=maxn;
    for(int i=1;i<=n;i++)           //读入数据
    {
        g[i][i]=0;
        cin>>a[i]>>l>>r;
        if(l>0) g[i][l]=g[l][i]=1;
        if(r>0) g[i][r]=g[r][i]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);   //floyd算法，计算最短路径
            }
    int minn=maxn;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=0;
        for(int j=1;j<=n;j++)
        {
            sum+=g[i][j]*a[j];          //计算每个节点到j的距离
 
        }
        if(sum<minn)
            minn=sum;
 
    }
    cout<<minn<<endl;
    return 0;
}