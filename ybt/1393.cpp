//1393：联络员(liaison)
#include <bits/stdc++.h>
using namespace std;
#define N 2005
struct Edge
{
	int u, v, w;
	bool operator < (const Edge &b) const
	{
		return w < b.w;
	}
};
int fa[N], ans;
vector<Edge> edges;
void initFa(int n)
{
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	fa[find(x)] = find(y);
}
void kruskal()
{
	sort(edges.begin(), edges.end());
	for(Edge e : edges)
	{
		int u = e.u, v = e.v, w = e.w;
		if(find(u) != find(v))
		{
			merge(u, v);
			ans += w;
		}
	}
}
int main()
{
	int n, m, p, u, v, w;
	cin >> n >> m;
	initFa(n);
	for(int i = 1; i <= m; ++i)
	{
		cin >> p >> u >> v >> w;
		if(p == 1)                          //如果必须，就先合并进生成树
		{
			merge(u, v);
			ans += w;
		}
		else
			edges.push_back(Edge{u, v, w}); //否则就加入边集
	}
	kruskal();
	cout << ans;
	return 0;
}
