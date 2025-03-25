//1380：分糖果(candy)
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define INF 0x3f3f3f3f
int n, p, c, m, mxTime;     //mxTime：顶点c单源最短路径中的最大值，即传递时间的最大值 
vector<int> edge[N];
bool vis[N];                //vis[i]：顶点i是否在队列中
int dis[N];                 //dis[i]：糖从起点传到顶点i的时间 
void spfa(int sv)
{
	memset(dis, 0x3f, sizeof(dis));
	queue<int> que;
	que.push(sv);
	vis[sv] = true;
	dis[sv] = 0;
	while(que.empty() == false)
	{
		int u = que.front();
		que.pop();
		vis[u] = false;
		for(int v : edge[u])
		{
			if(dis[v] > dis[u]+1)
			{
				dis[v] = dis[u]+1;
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
	int f, t;
	cin >> n >> p >> c >> m;
	for(int i = 1; i <= p; ++i)
	{
		cin >> f >> t;
		edge[f].push_back(t);
		edge[t].push_back(f);
	}
	spfa(c);
	for(int i = 1; i <= n; ++i)                 //找出传递时间最长的小朋友
		if(dis[i] != INF && mxTime < dis[i])
			mxTime = dis[i];
	cout << 1+mxTime+m;//起始位置时间为1，传到最后一个接收的小朋友的时间为1+mxTime，吃糖用m时间，吃完时间为1+mxTime+m 
	return 0;
}