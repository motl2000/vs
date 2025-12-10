//1496：【例 3】架设电话线
//分层图
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10,M = 2e5+10,INF = 0x3f3f3f3f;//M = 2e7+10
typedef pair<int,int> P;
int n,m,k,cnt;
int head[M],ver[M],nex[M],edge[M],vis[M],dis[M];
void add(int x,int y,int w){
	ver[++cnt] = y;
	edge[cnt] = w;
	nex[cnt] = head[x];
	head[x] = cnt;
}
void read(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,w;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);add(y,x,w);
		for(int j=1;j<=k;j++){
			add(j*n+x,j*n+y,w);add(j*n+y,j*n+x,w);  //j层的x到y的边权为w
			add((j-1)*n+x,j*n+y,0);                 //j-1层的x到j层的y的边权为0，即免费
			add((j-1)*n+y,j*n+x,0);                 //j-1层的y到j层的x的边权为0，即免费
		}
	}
}
void dj(){
	priority_queue<P> q;
	for(int i=0;i<=M;i++)                           //初始化
        dis[i] = INF;
	q.push(make_pair(0,1)); 
    dis[1] = 0;
	while(q.size()){
		int u = q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=head[u];i;i = nex[i]){
			int v = ver[i],w = edge[i];
			if(dis[v] > max(dis[u],w)){		
				dis[v] = max(dis[u],w);             //取选择v点通路上最贵的边权
				if(!vis[v]) 
                    q.push(make_pair(-dis[v],v));   //因为要选取的是最小的最大权值，q是大根堆，要让最大的权值在下面，所以要取负号
			}
		}
	}
}
void solve(){
	if(dis[k*n+n]!=INF) printf("%d\n",dis[k*n+n]);
	else printf("-1\n");
}
int main(){
	read();
	dj();
	solve();
	return 0;
}