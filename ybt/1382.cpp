//1382：最短路(Spfa),给定 M条边， N个点的带权无向图。求 1到 N的最短路。
#include<bits/stdc++.h>
using namespace std;
#define N 100005
struct Edge
{
	int t, w; 
	Edge(){}
	Edge(int a, int b):t(a),w(b){}
};
vector<Edge> edge[N];
bool vis[N];                    //vis[i]：顶点i是否在队列中 
int n, m, dis[N];               //dis[i]：当前情况下v0到i的最短路径距离
void initGraph()
{
	int f, t, w;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
    	cin >> f >> t >> w;     //从f到t权值w 
    	edge[f].push_back(Edge(t, w));
    	edge[t].push_back(Edge(f, w));
	}
}
void spfa(int sv)               //sv起始点 
{
	memset(dis, 0x3f, sizeof(dis));//dis初始值为INF
	queue<int> que;
	dis[sv] = 0; 
	vis[sv] = true;
    que.push(sv);
	while(que.empty() == false)
    {
        int u = que.front();
        que.pop();
        vis[u] = false;
        for(int i = 0; i < edge[u].size(); ++i)
        {
            int v = edge[u][i].t, w = edge[u][i].w;
            if(dis[v] > dis[u] + w)
            { 
                dis[v] = dis[u] + w;
                if(vis[v] == false)
                {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
    }
}
int main()
{
	initGraph();
	spfa(1);
	cout << dis[n];
    return 0;
}