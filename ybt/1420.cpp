//1420：Dijkastra(II),给定一个无向连通图，求从1到n的最短路。
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<utility>//pair的头文件 
using namespace std;
int n,m,tot,vis[200005],head[200005],num;
long long dis[200005];
priority_queue< pair<long long,int> > q;        //大根堆，这里用pair来存储距离和节点编号，pair默认是大根堆，所以不用重载运算符，但由于每次需要取出距离最小的边，因此在下面加入堆时需要取相反数
struct edge{
	int next;
	int t;
	int d;
}e[800005];
inline void add(int s,int t,int d){
	e[++num].next=head[s];
	e[num].t=t;
	e[num].d=d;
	head[s]=num;
}
int main(){
	int s,t,d,k;
	memset(dis,0x7f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&s,&t,&d);
		if(s==t) continue;
		add(s,t,d);
		add(t,s,d);
	} 
	dis[1]=0;
    q.push(make_pair(0,1));                     //make_pair的第一个参数是距离，第二个参数是节点编号
	while(q.size()){
		int x=q.top().second;
        q.pop();
		if(vis[x]) 
            continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next){
			int y=e[i].t,z=e[i].d;              //y是节点编号，z是边权
			if(!vis[y]&&dis[y]>dis[x]+z){
				dis[y]=dis[x]+z;
				q.push(make_pair(-dis[y],y));    //这里取相反数，是为了让堆顶始终是距离最小的边
			}
		}
						
	}
	cout<<dis[n];
	return 0;
}