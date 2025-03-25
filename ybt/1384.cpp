//1384：珍珠(bead)
//已知n是奇数，那么n/2(n整除2)的结果等于(n-1)/2。
//如果比i重的珍珠数量大于n/2，超过了一半，那么i的重量一定不是中间重量
//如果比i轻的珍珠数量大于n/2，超过了一半，那么i的重量也一定不是中间重量
//统计不可能是中间重量的珍珠的数量，输出结果。
#include<bits/stdc++.h>
using namespace std;
#define N 105
int n, m, e[N][N], ct;              //n：顶点数 m：边数 e[i][j]：输入数据中i比j重 
int main()
{
	int x, y;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i)
	{
		cin >> x >> y;
		e[x][y] = 1;
	}
	for(int k = 1; k <= n; ++k)        //floyd算法
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				if(e[i][j] == 0 && e[i][k] && e[k][j])
					e[i][j] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(e[i][j])
			{
				e[i][0]++;              //e[i][0]：比i轻的数量 
				e[0][j]++;              //e[0][j]：比j重的数量
			}
	for(int i = 1; i <= n; ++i)
		if(e[i][0] > n/2 || e[0][i] > n/2)  //如果比i轻的数量大于n/2或者比i重的数量大于n/2，则i
			ct++;
	cout << ct;
	return 0;
}