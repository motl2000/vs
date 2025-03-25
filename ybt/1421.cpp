//1421：Floyd
#include <bits/stdc++.h>
using namespace std;
int n,m;
long long dis[505][505],a,b,c,inf,ans;

int main()
{
    cin>>n>>m;
    inf=1e16;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i!=j) 
                dis[i][j]=inf;              //赋初值

    for(int i=1; i<=m; i++){
    scanf("%d%d%lld",&a,&b,&c);
    if(dis[a][b]>c)                         //记录最小的边
        dis[a][b]=c;
    }
    for(int k=1; k<=n; k++)                 //floyd
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(dis[i][j]>dis[i][k]+dis[k][j]) 
                    dis[i][j]=dis[i][k]+dis[k][j];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(dis[i][j]>1e13)              //如果两个节点不连通,由于浮点数精度问题，直接比较 dis[i][j] == inf 可能不可靠
                dis[i][j]=inf;              

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            ans^=dis[i][j]+inf;             //算值，^是异或

    cout<<ans<<endl;                        //输出
    return 0;
}
