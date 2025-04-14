//1349：【例4-10】最优布线问题
//kruskal算法
#include<bits/stdc++.h>
using namespace std;
const int SIZN = 105;
struct node {
	int u, v, w;
	node()
	{
		u = 0;
		v = 0;
		w = 0;
	}
	node(int _u, int _v, int _w)
	{
		u = _u;
		v = _v;
		w = _w;
	}
	bool operator<(const node& nxt)const
	{
		return nxt.w < w;           //短的边优先
	}
};
 
int n;
int ans;
int fa[SIZN];
priority_queue<node> pq;
int root(int x)
{
	if (fa[x] == x)return x;
	else return fa[x] = root(fa[x]);
}
void merge(int x, int y)
{
	x = root(x);
	y = root(y);
	fa[x] = y;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int w;
			cin >> w;
			if (i + j <= i * 2)continue;
			pq.push(node(i, j, w));
		}
	}
	for (int i = 1; i <= n; i++)
        fa[i] = i;
	for (int i = 1; i <= n - 1; i++)
	{
		while (!pq.empty())
		{
			const node now = pq.top();
			pq.pop();
			if (root(now.u) == root(now.v)) //已经连通
                continue;
			merge(now.u, now.v);
			ans += now.w;
		}
	}
	cout << ans;
	return 0;
}