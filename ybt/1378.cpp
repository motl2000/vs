//1378：最短路径(shopth)
//由于存在负权边，所以不能用Dijkstra算法
//1.可以用floyd算法
// # include<iostream>
// # include<cstdio>
// # define inf 0x3f3f3f3f
// using namespace std;
// const int maxn=100+5;
// int d[maxn][maxn];
// int main()
// {
// 	int n,s,w;
// 	cin>>n>>s;
// 	s--;                            //s是源点编号， 输入时从1开始，而数组是从0开始，所以要减一
// 	for(int i=0;i<n;i++)            //初始化邻接矩阵
// 	{
// 		for(int j=0;j<n;j++)
// 		{
// 			if(scanf("%d",&w)==1)
// 			    d[i][j]=w;
// 			else 
//                 d[i][j]=inf;
// 		}
// 	}
// 	for(int k=0;k<n;k++)            //floyd算法 
// 	  for(int i=0;i<n;i++)
// 	    for(int j=0;j<n;j++)
// 	       d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//     for(int i=0;i<n;i++)            //输出源点到其他点的最短路径
//         if(s!=i) 
//             printf("(%d -> %d) = %d\n",s+1,i+1,d[s][i]);
// 	return 0;
//  } 

//2.可以用SPFA算法
# include<iostream>
# include<cstdio>
# include<queue>
# define inf 0x3f3f3f3f
using namespace std;
const int maxn=100+5;
int g[maxn][maxn];
int d[maxn];
bool inq[maxn];   //是否在队列中 
int cnt[maxn];     //顶点进入队列的次数 
bool bellman_spfa(int s,int n)
{
	queue<int> 	q;
	for(int i=0;i<n;i++)
	  d[i]=inf;
	d[s]=0;
	q.push(s);
	inq[s]=true;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		inq[k]=false;
		for(int j=0;j<n;j++)
		{
			if(g[k][j]<inf&&d[j]>d[k]+g[k][j])  
			{
				d[j]=d[k]+g[k][j];
				if(!inq[j])
				{
					q.push(j);
					inq[j]=true;
					if(++cnt[j]>n)
					    return false;
				}	
			}
		}
	}
	return true;
}
int main()
{

int n,s,w;
	cin>>n>>s;
	s--;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(scanf("%d",&w)==1)
			g[i][j]=w;
			else g[i][j]=inf;
		}
	}
	bellman_spfa(s,n);
	 for(int i=0;i<n;i++)
	      if(s!=i) printf("(%d -> %d) = %d\n",s+1,i+1,d[i]);
	return 0;
}
