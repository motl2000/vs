//1348：【例4-9】城市公交网建设问题
//解法1：Prim算法 邻接矩阵 使用set排序
// #include<bits/stdc++.h>
// using namespace std;
// #define N 105
// struct Edge
// {
// 	int v, w;
// 	Edge(){}
// 	Edge(int a, int b):v(a),w(b){}
// };
// int n, m, dis[N], from[N];  //from[i]u顶点是从最小生成树中的哪个顶点连出来的，dis[i]:i到顶点的最小距离
// bool vis[N];
// vector<Edge> edge[N];
// set<pair<int, int>> tree;   //保存生成树的所有边 
// void prim()
// {
// 	memset(dis, 0x3f, sizeof(dis));                                 //初始化dis数组为最大值
// 	dis[1] = 0;
// 	for(int k = 1; k <= n; ++k)
// 	{
// 		int u = 0;
// 		for(int i = 1; i <= n; ++i)                                 //寻找不在生成树中的，且距离已经被标记的最小的顶点u
// 			if(vis[i] == false && (u == 0 || dis[i] < dis[u]))      //i:当前不在生成树中的顶点中，距离最小的顶点
// 				u = i; 
// 		vis[u] = true;
// 		if(from[u] != 0)
// 			tree.insert(make_pair(min(from[u], u), max(from[u], u)));//from[u]和u的较小值为pair的first，较大值为second 
// 		for(Edge e : edge[u])                                        //遍历u的所有邻接边
// 		{
// 			int v = e.v, w = e.w;
// 			if(vis[v] == false && dis[v] > w)                        //如果v不在生成树中，且之前已标记的v到生成树的距离大于u到v的距离   
// 			{ 
// 				dis[v] = w;                                          //更新v到生成树的距离，取更小的w
// 				from[v] = u;                                         //更新v是从哪个顶点连出来的
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	int f, t, w;
// 	cin >> n >> m;
// 	for(int i = 1; i <= m; ++i)
// 	{
// 		cin >> f >> t >> w;
// 		edge[f].push_back(Edge(t, w));
// 		edge[t].push_back(Edge(f, w));
// 	}
// 	prim();
// 	for(pair<int, int> p : tree)
//         cout << p.first << "  " << p.second << endl;
//     return 0;
// }



// //解法2：Prim算法堆优化 邻接表 使用vector及sort完成排序
// #include<bits/stdc++.h>
// using namespace std;
// #define N 105
// struct Edge
// {
// 	int v, w;
// 	Edge(){}
// 	Edge(int a, int b):v(a),w(b){}
// 	bool operator < (const Edge &b) const
// 	{
// 		return b.w < w;
// 	}
// };
// int n, m, dis[N], from[N];//from[i]到顶点i的一条边是最小生成树中的边 
// bool vis[N];
// vector<Edge> edge[N];
// priority_queue<Edge> pq;
// set<pair<int, int>> tree;//保存生成树的所有边 
// void prim()//prim算法堆优化 
// {
// 	memset(dis, 0x3f, sizeof(dis));
// 	dis[1] = 0;
// 	pq.push(Edge(1, 0));
// 	int visNum = 0;
// 	while(pq.empty() == false)
// 	{ 
// 		int u = pq.top().v;
// 		pq.pop();                           //每次取出一个不在生成树中的，且距离已经被标记的最小的顶点u
// 		if(vis[u])
// 			continue;
// 		vis[u] = true;
// 		if(from[u] != 0)
// 			tree.insert(make_pair(min(from[u], u), max(from[u], u)));
// 		if(++visNum == n)
// 			break;
// 		for(Edge e : edge[u])
// 		{
// 			int v = e.v, w = e.w;
// 			if(vis[v] == false && dis[v] > w)
// 			{ 
// 				dis[v] = w;
// 				from[v] = u;
// 				pq.push(e);
// 			}
// 		}
// 	}
// }
// int main()
// {
// 	int f, t, w;
// 	cin >> n >> m;
// 	for(int i = 1; i <= m; ++i)
// 	{
// 		cin >> f >> t >> w;
// 		edge[f].push_back(Edge(t, w));
// 		edge[t].push_back(Edge(f, w));
// 	}
// 	prim();
// 	for(pair<int, int> p : tree)
//         cout << p.first << "  " << p.second << endl;
//     return 0;
// }

//解法3：Kruskal算法 保存所有边 使用vector及sort完成排序
#include<bits/stdc++.h>
using namespace std;
#define N 105
struct Edge
{
	int f, t, w;
	Edge(){}
	Edge(int a, int b, int c):f(a),t(b),w(c){}
};
int n, m, fa[N], edgeNum;
vector<Edge> edges, tree;           //edges：所有的边 tree：最小生成树的所有边 
void initFa(int n)
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
bool cmp_edges(Edge a, Edge b)
{
	return a.w  < b.w;
}
bool cmp_tree(Edge a, Edge b)
{
	if(a.f == b.f)
		return a.t < b.t;
	else
		return a.f < b.f;
}
void kruskal()
{
	sort(edges.begin(), edges.end(), cmp_edges);//按照权值从小到大排序 
	for(Edge e :edges)
	{
		int f = e.f, t = e.t;
		if(find(f) != find(t))                  //如果f和t不在同一个集合中
		{
			tree.push_back(e);                  //将这条边加入最小生成树中
			merge(f, t);                        //合并两个集合
			if(++edgeNum == n-1)                //如果加入的边数等于n-1，说明最小生成树已经构造完成
				break;
		}
	}
}
int main()
{
	int f, t, w;
	cin >> n >> m;
	initFa(n);
	for(int i = 1; i <= m; ++i)
	{
		cin >> f >> t >> w;
		if(f > t)                               //强行让小的编号在前，大的编号在后 
			swap(f, t);
		edges.push_back(Edge(f, t, w));         //加入的边保证f<t 
	}
	kruskal();
	sort(tree.begin(), tree.end(), cmp_tree);   //按照边的f从小到大，如f相同，按t从小到大排序。 
	for(Edge e : tree)
		cout << e.f << "  " << e.t << endl;
	return 0;
}




