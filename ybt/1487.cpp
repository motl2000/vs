//1487：【例 2】北极通讯网络
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510;
int n,k,vis[N],p[N];//p[i]表示i的父节点
pair<int,int>v[N];
struct node{
	int dis,a,b;
	bool operator<(const node& t)const{
		return dis<t.dis;
	}
};
vector<node>e;
int find(int x){
	if(x!=p[x]) p[x]=find(p[x]);
	return p[x];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) 
        scanf("%d%d",&v[i].first,&v[i].second);
	for(int i=1;i<=n;i++)//枚举所有点对，存入e
		for(int j=1;j<=n;j++){
			int dis=pow(v[i].first-v[j].first,2)+pow(v[i].second-v[j].second,2);
			e.push_back({dis,i,j});
		}		
	sort(e.begin(),e.end());
	for(int i=1;i<=n;i++) //并查集初始化
        p[i]=i;
	int res=0,cnt=n;
	for(int i=0;i<e.size();i++){//kruskal算法
		if(cnt<=k) break;
		int x=find(e[i].a),y=find(e[i].b),w=e[i].dis;//x,y是e[i]的两个端点，w是e[i]的权值
		if(x!=y){
			p[x]=y;
			cnt--;
			res=w;
		}
	}		
	printf("%.2lf",sqrt(res));
	return 0;
}