//1344：【例4-4】最小花费
//输入:第一行输入两个正整数n,m，分别表示总人数和可以互相转账的人的对数。以下m行每行输入三个正整数x,y,z，表示标号为x的人和标号为y的人之间互相转账需要扣除z%的手续费 (z<100)。最后一行输入两个正整数A,B。数据保证A与B之间可以直接或间接地转账。
//输出:输出A使得B到账100元最少需要的总费用。精确到小数点后8位。
//找最短路径
#include <iostream>
using namespace std;
double z,p[2002][2002],dis[2002],maxn;
int n,m,x,y,vis[2002],k;
void dijkstra(int x){
	for(int i=1;i<=n;i++) 
        dis[i]=p[x][i];
	dis[x]=1;
    vis[x]=1;
	for(int i=1;i<=n-1;i++){
		maxn=0;
		for(int j=1;j<=n;j++)
			if(vis[j]==0 && dis[j]>maxn){
				k=j;
                maxn=dis[j];
			}
		vis[k]=1;
		if(k==y)                                //找到了终点，直接退出
            break;
		for(int j=1;j<=n;j++)
			if(vis[j]==0&&dis[k]*p[k][j]>dis[j])
				dis[j]=dis[k]*p[k][j];
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		p[x][y]=p[y][x]=(100-z)/100;            //转换为每到账100元的实际转账金额
	}
	cin>>x>>y;
	dijkstra(x);
	printf("%.8lf",100/dis[y]);                 //输出转账100元到账的实际转账金额
	return 0;
}