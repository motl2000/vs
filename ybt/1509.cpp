//1509：【例 1】Intervals
//解法1：差分约束
#include <bits/stdc++.h>
using namespace std;
#define N 50005
struct Edge
{
	int v, w;
};
int n, d[N];//d[i]：1~i中选出数字的数量 d[b]-d[a-1]为a~b中选出数字的数量 
bool inQue[N];
vector<Edge> edge[N];
void spfa(int sv)
{
	queue<int> que;
	memset(d, 0xc0, sizeof(d));
	d[sv] = 0;
	inQue[sv] = true;
	que.push(sv);
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		inQue[u] = false;
		for(Edge e : edge[u])
		{
			int v = e.v, w = e.w;
			if(d[v] < d[u]+w)
			{
				d[v] = d[u]+w;
				if(!inQue[v])
				{
					inQue[v] = true;
					que.push(v);
				}
			}
		}
	}
}
int main()
{
	int a, b, c;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a >> b >> c;//a~b中选出数字的数量大于等于c  d[b]-d[a-1] >= c
		a++, b++;//输入的数字增加1，使得数字范围为1~50001 
		edge[a-1].push_back(Edge{b, c});//d[b]-d[a-1] >= c
	}
	for(int i = 1; i <= 50001; ++i)
	{//i~i中有最少0个数字，最多1个数字，即 0 <= d[i]-d[i-1] <= 1
		edge[i].push_back(Edge{i-1, -1});//d[i-1]-d[i] >= -1
		edge[i-1].push_back(Edge{i, 0});//d[i]-d[i-1] >= 0
		edge[0].push_back(Edge{i, 0});//d[i]-d[0] >= 0 顶点0为超级源点 
	}
	spfa(0);
	cout << d[50001];
	return 0;
}

//解法2：贪心算法+树状数组、并查集优化
// #include<bits/stdc++.h>
// using namespace std;
// #define N 50005
// struct Node
// {
//     int a, b, c;//[a, b]中选c个数
//     bool operator < (const Node &x) const
//     {
//         return b < x.b;
//     } 
// } a[N];
// bool vis[N];//vis[i]:点i是否已被选择 
// int fa[N], tree[N]; 
// void init(int n)
// {
//     for(int i = 1; i <= n; ++i)
//         fa[i] = i;
// } 
// int find(int x)//find(x)：<=x的所有点中第一个vis为false的点 
// {
//     return x == fa[x] ? x : fa[x] = find(fa[x]);
// }
// int lowbit(int x)
// {
//     return x & -x;
// }
// void update(int x, int v)//vis[x] = v
// {
//     for(int i = x+1; i < N; i += lowbit(i))//x可能为0，树状数组下标从1开始 
//         tree[i] += v;
// }
// int sum(int x)//vis[0]+...+vis[x]
// {
//     int res = 0;
//     for(int i = x+1; i > 0; i -= lowbit(i))
//         res += tree[i];
//     return res; 
// }
// int query(int l, int r)//vis[l]+...+vis[r]
// {
//     return sum(r)-sum(l-1);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     init(50000);
//     int n, ans = 0;//ans：总选点数量 
//     cin >> n;
//     for(int i = 1; i <= n; ++i)
//         cin >> a[i].a >> a[i].b >> a[i].c; 
//     sort(a+1, a+1+n);
//     for(int i = 1; i <= n; ++i)
//     {
//         a[i].c -= query(a[i].a, a[i].b);
//         if(a[i].c <= 0)//如果已经不需要再选点 
//             continue;
//         for(int j = find(a[i].b); j >= a[i].a; j = find(j))
//         {
//             vis[j] = true;
//             update(j, 1);
//             ans++;
//             fa[j] = find(j-1);//find(j-1)是<=j-1的第一个vis为false的点的下标，fa[j]设为find(j-1)后，以后find(j)就是find(j-1) 
//             if(--a[i].c <= 0)
//                 break;
//         }
//     }
//     cout << ans;
//     return 0;
// }
