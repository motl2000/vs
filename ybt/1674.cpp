//1674：堆蛋糕
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
int n,ans,mx;
int tj[maxn];               //用于统计每种半径的蛋糕数量
int js;
priority_queue<int>q;
int min(int a,int b,int c)
{
	if(a>b)a=b;
	if(a>c)a=c;
	return a;
}
int main()
{
	scanf("%d",&n);
	for(int x,i=1;i<=n;++i)
	{
		scanf("%d",&x);
		tj[x]++;                //统计每种半径的蛋糕数量
		mx=max(mx,x);           //记录最大半径
	}
	for(int i=1;i<=mx;++i)
		if(tj[i])
			q.push(tj[i]);      //将半径种类放入队列
	while(q.size()>=3)          //当半径种类大于3时
	{
		int a=q.top();q.pop();  //取出三个蛋糕
		int b=q.top();q.pop();
		int c=q.top();q.pop();
		ans++;                  //计算堆蛋糕数量
		if(a>1)q.push(a-1);     //这三个蛋糕堆起来后，对应的半径种类数量减一
		if(b>1)q.push(b-1);
		if(c>1)q.push(c-1);
	}
	cout<<ans<<endl;
	return 0;
}

