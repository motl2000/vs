//1496：【例 3】架设电话线
//dijkstra + dp
#include<bits/stdc++.h>
using namespace std;
const int N = 100050,M = 10005,INF = 0x3f3f3f3f; 
struct node{
	int now,k,w;    //now:当前点  k:当前点使用的免费次数  w:当前点到起点的最短距离
	node(){}
	node(int now,int k,int w):now(now),k(k),w(w){}
	bool operator < (const node &b) const{
		return w > b.w;
	}
};
int head[N],ver[N],edge[N],nex[N];
int n,m,k,cnt,vis[M][21],d[M][21];   //n:点数  m:边数  k:免费次数  cnt:边数  vis:是否在队列中  d[i][j]:i点使用j次免费次数的最短路径 
void add(int a,int b,int w){
	ver[++cnt] = b;
	edge[cnt] = w;
	nex[cnt] = head[a];
	head[a] = cnt;
}
void read(){
	int x,y,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);add(y,x,w);
	} 
}
void dj(){
	for(int i=0;i<=n;i++)
	    for(int j=0;j<=k;j++)
	        d[i][j] = INF;
	priority_queue<node> q;
	q.push(node(1,0,0));
    d[1][0] = 0;
	while(q.size()){
		node now = q.top();q.pop();
		int u = now.now,num = now.k;                 //u:当前点  num:当前点使用的免费次数
		if(vis[u][num]) continue;
		vis[u][num] = 1;
		for(int i=head[u];i;i=nex[i]){
			int v = ver[i],w = edge[i];              //v:u的邻接点  w:u到v的边权
			if(d[v][num] > max(d[u][num],w)){        //如果v点不使用免费次数，选择这条通路上最贵的那条边的权
				d[v][num] = max(d[u][num],w);        
				if(!vis[v][num])                     //在免费num次的情况下使用v点
				    q.push(node(v,num,d[v][num]));   //v点免费使用num次的情况入堆
			}
			if(num < k && d[v][num+1] > d[u][num]){  //如果v点使用免费次数
				d[v][num+1] = d[u][num];             //v点使用免费次数的最短路径等于u点不使用免费次数的最短路径
				if(!vis[v][num+1])                   //v点使用免费次数的最短路径入堆
				    q.push(node(v,num+1,d[v][num+1]));
			}
		}
	}	
}
void solve(){
	if(d[n][k] != INF)
	printf("%d\n",d[n][k]);
	else printf("-1\n");
}
int main(){
	read();
	dj();
	solve();
	return 0;
}