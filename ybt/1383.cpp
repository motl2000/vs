//1383：刻录光盘(cdrom)
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N=205;
int n;
int mapp[N][N];
int p[N];                            //p[i]表示i的父节点
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=n;i++){
        int x;
        while(scanf("%d",&x)&&x!=0){
            mapp[i][x]=1;           //mapp[i][x]=1表示i与x是连通的,有向边
        }
    }
    for(int k=1;k<=n;k++)           //floyd算法标记是否连通
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mapp[i][j]=mapp[i][j]||(mapp[i][k]&&mapp[k][j]);
 
    for(int i=1;i<=n;i++)           
        for(int j=1;j<=n;j++)
            if(mapp[i][j])
                p[j]=p[i];          //p[i]是p[j]的父节点

    int cnt=0;
    for(int i=1;i<=n;i++)           //统计连通分量
        if(p[i]==i)                 //如果p[i]==i,说明i是根节点，是一个连通分量的根节点
            cnt++;  

    printf("%d\n",cnt);
    return 0;
}