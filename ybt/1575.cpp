//1575：【例 1】二叉苹果树
// 解法1，树形DP，二叉树
#include <bits/stdc++.h>
using namespace std;
#define N 105
struct Edge
{
	int v, w;
};
vector<Edge> edge[N];
int n, q, dp[N][N];//dp[i][j]：以i为根的树中保留j条边能够得到的最大边权加和
void dfs(int u, int fa)
{
	int l = 0, r = 0, lw, rw;
	if(edge[u].size() == 1)//叶子结点 
		return;
	for(Edge e : edge[u])       //遍历u的所有子节点
	{
		int v = e.v, w = e.w;   //v为u的子节点，w为u->v的边权
		if(v != fa)             //如果v不是u的父节点
		{
			if(l == 0)          //如果左子树还没有被访问过，则将v作为左子树的根节点
				l = v, lw = w;
			else                //如果左子树已经被访问过，则将v作为右子树的根节点
				r = v, rw = w;
			dfs(v, u);          //递归访问v的子节点
		}
	}
	for(int j = 1; j <= q; ++j) //枚举保留j条边
	{
		dp[u][j] = max(lw+dp[l][j-1], rw+dp[r][j-1]);//左子树或右子树完全没有的情况，因为从u到子树至少要一条边，所以最多只能保留j-1条边
		for(int k = 0; k <= j-2; ++k)//同时有左右子树，左子树保留k条边,右子树保留j-2-k条边
			dp[u][j] = max(dp[u][j], lw+rw+dp[l][k]+dp[r][j-2-k]);
	}
} 
int main()
{
	int f, t, w;
	cin >> n >> q;
	for(int i = 1; i < n; ++i)          //读入n-1条边,构建领接表，无向图
	{
		cin >> f >> t >> w;
		edge[f].push_back(Edge{t, w});
		edge[t].push_back(Edge{f, w});
	}
	dfs(1, 0);
	cout << dp[1][q];
	return 0;
}

// 解法2，树形DP，有依赖的背包
// #include <bits/stdc++.h>
// using namespace std;
// #define N 105
// struct Edge
// {
// 	int v, w;
// };
// vector<Edge> edge[N];
// int n, q, dp[N][N];//dp[u][i][j]：以u为根的树中前i个子树保留j条边（包括和u连接的边）能够得到的最大权值加和
// void dfs(int u, int fa)
// {
// 	for(Edge e : edge[u])
// 	{
// 		int v = e.v, w = e.w;
// 		if(v != fa)
// 		{
// 			dfs(v, u); 
// 			for(int j = q; j >= 1; --j)
// 				for(int k = 1; k <= j; ++k)//一定包含u到v的边 子树v保留k-1条边 
// 					dp[u][j] = max(dp[u][j], dp[u][j-k]+dp[v][k-1]+w);
// 		}
// 	}
// } 
// int main()
// {
// 	int f, t, w;
// 	cin >> n >> q;
// 	for(int i = 1; i < n; ++i)
// 	{
// 		cin >> f >> t >> w;
// 		edge[f].push_back(Edge{t, w});
// 		edge[t].push_back(Edge{f, w});
// 	}
// 	dfs(1, 0);
// 	cout << dp[1][q]; 
// 	return 0;
// }
