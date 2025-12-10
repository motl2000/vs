//1504：【例 1】Word Rings
//二分答案，SPFA_DFS判断正环
//查找最小平均环长，相当于查找每条边长减去平均值后是否存在正环，证明看书P141
#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct Edge
{
	int v;
	double w;
};
int sn, n;
vector<Edge> edge[N];   //邻接表存储图
map<string, int> num;   //将长为2的字符串转为数字编号,num[s]表示字符串s的编号
bool inStk[N];          //判断是否在栈中，防止出现负环
double dis[N];
bool spfa_dfs(int u, double ave)//每条边权值减去ave，判断是否存在正环 
{
	inStk[u] = true;
	for(Edge e : edge[u])
	{
		int v = e.v;
		double w = e.w-ave; 
		if(dis[v] <= dis[u]+w)//等于时也松弛，可以找到0权环
		{
			dis[v] = dis[u]+w;
			if(inStk[v] || spfa_dfs(v, ave))//如果在栈中或者存在正环，则返回true
				return true;
		}
	}
	inStk[u] = false;
	return false;
}
bool check(double ave)//在每条边边权都减去ave后，是否存在正权环 
{
	memset(dis, 0, sizeof(dis));
	memset(inStk, 0, sizeof(inStk));
	for(int i = 1; i <= n; ++i)	
        if(spfa_dfs(i, ave))
		    return true;
	return false;
} 
int main()
{
	string s;
	while(cin >> sn && sn != 0)         //读取第一行和最后一行
	{
		for(int i = 0; i < N; ++i)
			edge[i].clear();
		num.clear();
		n = 0;
		for(int i = 1; i <= sn; ++i)
		{
			cin >> s;
			if(s.length() < 2)
				continue;
            //建图
			string front = s.substr(0, 2);          //边的起始点
            string back = s.substr(s.length()-2);   //边的终点
			if(num.find(front) == num.end())        //如果没有找到，则添加到map中，并给编号
				num[front] = ++n;               
			if(num.find(back) == num.end())
				num[back] = ++n;
            //在领接表中添加该起始节点对应的领结节点
			edge[num[front]].push_back(Edge{num[back], (double)s.length()});	
		}
		if(!check(0))//ave为0，判断原图是否有正环 
		{
			cout << "No solution." << '\n';
			continue;
		}
		double l = 0, r = 1e8;
		while(r-l >= 1e-8)
		{
			double mid = (l+r)/2;
			if(check(mid))
				l = mid;
			else
				r = mid;
		}
		cout << fixed << setprecision(2) << l << '\n';
	}
	return 0;
}
