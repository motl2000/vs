//P2672 [NOIP 2015 普及组] 推销员
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,sum[100010],q[100010],h[100010];//n 疲劳前缀和 前i个最大值 后i个最大值 
struct node{
    int s;//距离
    int a;//疲劳 
}v[100010];
bool cmp(node x,node y){return x.a>y.a;}
int main()
{	scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i].s); 
    for(int i=1;i<=n;i++)scanf("%d",&v[i].a);
    sort(v+1,v+1+n,cmp);//按疲劳排序 
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+v[i].a; 	//求每个节点到它自己时的疲劳值总和，这样就不用每次判断都要去求一次和 
    for(int i=1;i<=n;i++)q[i]=max(q[i-1],2*v[i].s);	//存储当从左自右顺序访问到自己就返回的距离的最大值 
    for(int i=n;i>=1;i--)h[i]=max(h[i+1],2*v[i].s+v[i].a);//存储i后的节点中可以提供的最大贡献，即i后节点中 距离*2+自己值 的最大值 
    for(int i=1;i<=n;i++)printf("%d\n",max(sum[i]+q[i],sum[i-1]+h[i]));//在 前i段的疲劳总和+最大距离*2  和  前i-1段的疲劳总和+ i后节点中可以提供的最大贡献
    return 0;
}
/*
1 2 3 4 5
5 4 3 4 1
按疲劳值从大到小排列
1 2 4 2 5
5 4 4 3 1
如果X==3，就取前三个
1 2 4
5 4 4
但此时可能存在一种情况，后两个里的距离更长，从而使总量更大。
尝试舍去第三个，并去后两个里找一个最大情况后加上前两个，比较两种情况哪个值更大。
情况1
1 2 4
5 4 4
情况2
1 2			2 5
5 4			3 1
后两个里取 2*距离+疲劳值 最大的那个,2*2+3<5*2+1
1 2		5
5 4		1
比较两种情况的最大值，取大的那个
为何舍去一个去比较就可以了？因为后两个中的距离最大值不会有变化，在后两个里观察更多个都不会造成因距离变大而使总和变大的情况发生。
*/