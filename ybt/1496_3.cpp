//1496：【例 3】架设电话线
//二分
/*
本题的结果显然具有单调性,因为支付的钱更多时,合法的升级方案一定包含花费更少的升级方案。
所以我们可以二分结果,把问题转化为:是否存在一种合法的升级方法,使花费不超过 mid。
转化后判定问题非常容易,只需要把升级价格大于mid的电缆看作长度为1的边,
把升级价格不超过mid的电缆看作长度为0的边,然后求从1到N的最短路是否不超过K即可。
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10,INF = 0x3f3f3f3f;
int head[N],ver[N],nex[N],edge[N],vis[N],dis[N];
typedef pair<int,int> P;
int l=0,r=1e6,mid;
int n,m,k,cnt;
void add(int x,int y,int w){
	ver[++cnt] = y;
	edge[cnt] = w;
	nex[cnt] = head[x];
	head[x] = cnt;
}
void read(){
	int x,y,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
        add(y,x,w);
	} 
}
bool check(int x){
	for(int i=0;i<N;i++) 
	dis[i] = INF,vis[i]=0;	
	priority_queue<P> q;
	q.push(make_pair(0,1));
    dis[1] = 0;
	while(q.size()){
		int u =q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=head[u];i;i=nex[i]){
			int v = ver[i],w = edge[i];
			int nd = dis[u] + (w>x?1:0);
			if(dis[v] > nd){
				dis[v] = nd;
				if(!vis[v])
				q.push(make_pair(-dis[v],v));
			}
		}
	}
	return (dis[n] <= k);
}
void solve(){
	while(l<=r){
		mid = ((r+l)>>1);	
		if(check(mid))
			r = mid-1;
		else l = mid+1;	
	}
	if(r==1e6) puts("-1");
	else printf("%d\n",l);
}
int main(){
	read();
	solve();
	return 0;
}