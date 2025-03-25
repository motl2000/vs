//1381：城市路(Dijkstra)
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f                      //无穷大
using namespace std;

int n,m;
int mp[2005][2005];                         //图（邻接矩阵）
bool vis[2005];                             //访问标记
int dis[2005];                              //最短距离

void Dijkstra(int s){//核心代码
    memset(dis,0x3f,sizeof(dis));           //初始化,默认所有节点到s的距离为无穷大
    dis[s]=0;
    for(int i=1;i<=n;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=n;j++){              //找到未访问的最小值
            if(vis[j]==0 && dis[j]<MIN){
                u=j;
                MIN=dis[j];
            }
        }
        if(u==-1) return;                   //找不到最小值，退出
        vis[u]=1;                           //标记u已访问，即u到s的最短距离已确定
        for(int v=1;v<=n;v++){
            //松弛操作
            if(vis[v]==0 && mp[u][v]!=INF && dis[u]+mp[u][v]<dis[v]){
                dis[v]=dis[u]+mp[u][v];
            }
        }
    }
}

int main(){
    memset(mp,0x3f,sizeof(mp));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a][b]=min(c,mp[a][b]);
        mp[b][a]=min(c,mp[a][b]);
    }
    for(int i=1;i<=n;i++){
        mp[i][i]=0;
    }

    Dijkstra(1);
    if(dis[n]!=INF) cout<<dis[n];
    else cout<<-1;
    return 0;
}