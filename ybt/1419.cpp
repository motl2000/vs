//1419：SPFA(II),给定一个有向连通图，求从1到n的最短路。
//示例代码 SPAF
#include <bits/stdc++.h>
using namespace std;
const int N=100005;
const long long IFN=0x3F3F3F3F3F3F3F3F;
long long num,nex[10*N],to[10*N],w[10*N],head[N];
bool vis[N];               //标记
long long dis[N];           //距离
long long n,m;
void add(int a,int b,int c){//邻接表存储
	if(a==b)                    //防止出现自环
        return;
	nex[num]=head[a];
	to[num]=b;
	w[num]=c;
	head[a]=num++;
}
void Spfa(int g){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	queue<int> q;
	dis[g]=0;
	q.push(g);
	vis[g]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=false;
		for(long long i=head[x];i!=-1;i=nex[i]){
			long long y=to[i],z=w[i];
			if(dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				if(!vis[y]){
					vis[y]=true;
					q.push(y);
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	num=0;
	int a,b,c;
	for(int i=1;i<=n;i++) 
        head[i]=-1;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
	}
	Spfa(1);
	if(dis[n]>=IFN) 
        dis[n]=-1;
	cout<<dis[n];
	return 0;
}