//1379：热浪(heatwv)
//1.Dijsktra算法
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>

// using namespace std;

// const int MAXN = 105;
// const int INF = INT_MAX;

// vector<pair<int, int>> adj[MAXN]; // 邻接表存储图
// int dist[MAXN];                   // 存储从起点到各点的最短距离
// //最简洁的Dijkstra算法
// void dijkstra(int start)                
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 小根堆，存储距离和顶点，按距离排序，方便取出最小距离的顶点
//     fill(dist, dist + MAXN, INF);                                                       // 初始化距离为无穷大
//     dist[start] = 0;
//     pq.push({0, start}); // 起点入队

//     while (!pq.empty())
//     {
//         int u = pq.top().second;        // 顶点
//         int d = pq.top().first;         // 距离
//         pq.pop();

//         if (d > dist[u])                // 如果当前距离大于最短距离，则跳过
//             continue;

//         for (const auto &edge : adj[u])       // 遍历所有邻接点
//         {
//             int v = edge.first;
//             int w = edge.second;
//             if (dist[u] + w < dist[v])  
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
// }
// int main()
// {
// 	int n,m,s,t,u, v, w;
// 	cin >> n >> m >> s >> t;            //n:顶点数 m:边数 s:起点 t:终点 
// 	for(int i = 1; i <= m; ++i)
// 	{
// 		cin >> u >> v >> w;
//         adj[u].push_back({v, w});       //双向
//         adj[v].push_back({u, w});        
// 	}
// 	dijkstra(s);
// 	cout << dist[t];
// 	return 0;
// }

//2.SPFA算法
#include<bits/stdc++.h>
using namespace std;
#define N 2505
struct Edge
{
	int v, w;
	Edge(){}
	Edge(int a, int b):v(a), w(b){}
};
vector<Edge> edge[N];               //邻接表 
bool vis[N];                        //vis[i]：顶点i是否在队列中 
int n, m, s, t, dis[N];             //dis[i]：起点到i的最短路径距离 
void spfa(int sv)
{
	memset(dis, 0x3f, sizeof(dis));
	queue<int> que;
	dis[sv] = 0;
	que.push(sv);
	vis[sv] = true;
	while(que.empty() == false)
	{
		int u = que.front();
		que.pop();
		vis[u] = false;
		for(Edge e : edge[u])
		{
			int v = e.v, w = e.w;
			if(dis[v] > dis[u]+w)
			{
				dis[v] = dis[u]+w;
				if(vis[v] == false)
				{
					que.push(v);
					vis[v] = true;
				}
			}
		}
	}
}
int main()
{
	int u, v, w;
	cin >> n >> m >> s >> t;//n:顶点数 m:边数 s:起点 t:终点 
	for(int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		edge[u].push_back(Edge(v, w));
		edge[v].push_back(Edge(u, w));
	}
	spfa(s);
	cout << dis[t];
	return 0;
}

