#include<bits/stdc++.h>
using namespace std;
const int N = 10005, K = 100, INF = 0x3f3f3f3f;
struct Path
{
	int u, t;//存在到达顶点u，时刻为t的路径 
	bool operator < (const Path &b) const//重载 < ，构成最小优先队列 
	{
		return t>b.t;//时刻t更小更优先，大的下沉
	}
};
struct Edge
{
	int v, a;
};
int n, m, k, dp[N][K];//在k的整数倍时刻从起点出发到达顶点i，到达顶点i的时刻模k等于j的最早时刻。
vector<Edge> edge[N];
int divCeil(int a, int b)//ceil(a/b)，向上取整
{
	return (a-1)/b+1; 
} 
void dijkstra()
{
	priority_queue<Path> pq;
	memset(dp, 0x3f, sizeof(dp));//求最短路径，先将状态设为无穷 
	dp[1][0] = 0;//到达顶点1（起点），到达时刻模k为0的最早时刻为0
	pq.push(Path{1, 0});//将到达时刻为0，到达顶点1的路径放入最小堆 
	while(!pq.empty())
	{
		int u = pq.top().u; //当前要测试的顶点T
        int t = pq.top().t; //测试顶点的到达时间
		pq.pop();
		for(Edge e : edge[u])   //遍历和u点相连的所有的边
		{
			int v = e.v, a = e.a, tmin;//tmin：想要从u通过<u,v>，到达v的最早时刻 
			if(t >= a)                  //如果到达u的时间大于v的开放时间，就可以直接走过v
				tmin = t+1;
			else                         //不然的话就需要调整坐车时间，以保证可以在k的整数倍时刻通过<T,u>到达u 
			 	tmin = t+1+divCeil(a-t, k)*k;//a-t为激活u需要等待的时间，除k向上取整就是要等几轮,乘k即为实际等待的时间 
			if(dp[v][tmin%k] > tmin)    //取到达顶点v的时刻为tmin%k的最小值 
			{
				dp[v][tmin%k] = tmin;
				pq.push(Path{v, tmin});
			}
		}
	}
}
int main()
{
	int u, v, a;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> a;
		edge[u].push_back(Edge{v, a});
	}
	dijkstra();
	cout << (dp[n][0] == INF ? -1 : dp[n][0]);
	return 0;
}
