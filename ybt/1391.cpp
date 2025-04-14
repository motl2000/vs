//1391：局域网(net)
//求最小生成树，用累计的总权减去最小生成树的权值
#include<bits/stdc++.h>
using namespace std;
#define N 105
struct Edge
{
	int f, t, w;
	Edge(){}
	Edge(int a, int b, int c):f(a),t(b),w(c){}
};
int n, m, edgeNum, sumTree, sumAll, fa[N];
bool vis[N];
vector<Edge> edges;
bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}
void initFa()
{
	for(int i = 1; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	if(x == fa[x])
		return x;
	else
		return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
	fa[find(x)] = find(y);
}
void kruskal()
{
	sort(edges.begin(), edges.end(), cmp);
	for(Edge e : edges)
	{
		if(find(e.f) != find(e.t))
		{
			sumTree += e.w;
			merge(e.f, e.t);
			if(++edgeNum == n-1)
				return;
		}
	}
}
int main()
{
	int f, t, w;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		cin >> f >> t >> w;
		edges.push_back(Edge(f, t, w));
		sumAll += w;
	}
	initFa();
	kruskal();
	cout << sumAll - sumTree;       
	return 0;
}
