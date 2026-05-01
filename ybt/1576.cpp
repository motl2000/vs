//1576：【例 2】选课
#include<bits/stdc++.h>
using namespace std;
#define N 305
int n, m, w[N], dp[N][N];//dp[u][i][j]：结点u的前i个孩子，最多选择j门课能获得的最大学分 
vector<int> edge[N];
void dfs(int u)
{
	dp[u][1] = w[u];//选1门课，就只能选自己 
	for(int v : edge[u])
	{
		dfs(v);
		for(int j = m; j >= 1; --j)//在树中选j门课 
			for(int k = 1; k < j; ++k)//在子树v中选了k门课 （因为还要选v，最多选j-1门） 
				dp[u][j] = max(dp[u][j], dp[u][j-k]+dp[v][k]); 
	}
}
int main()
{
	int f;
	cin >> n >> m;
	n++, m++;//算上0号结点 
	for(int i = 1; i < n; ++i)
	{
		cin >> f >> w[i];
		edge[f].push_back(i);
	}
	dfs(0);
	cout << dp[0][m];
	return 0;
}
