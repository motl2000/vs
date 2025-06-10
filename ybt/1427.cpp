//1427：数列极差
/*
如果保证最后得到一个最大的数字，那么每次去掉两个最小的数字，换来一个较大的数字（这样最后结果会越来越大）
如果保证最后得到一个最小的数字，那么每次去掉两个最大的数字
，换来一个新数字（由于你去掉了两个最大的数字，那么在最后你就失去了乘最大数让结果最大的机会
，所以这个操作过程使得结果呈现递减趋势，结果就最小啦）
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<functional>

using namespace std;

int n,maxn,minn,shu,x,y,ac[10001];
priority_queue<int,vector<int> ,greater<int> > a;   //大根堆
priority_queue<int> b;                              //小根堆

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&ac[i]);
    
    for(int i=1;i<=n;i++)
        a.push(ac[i]);  
    for(int i=1;i<=n;i++)
        b.push(ac[i]);
    
    for(int i=1;i<=n-1;i++)         //求最大值
    {
        x=a.top();
        a.pop();
        y=a.top();
        a.pop();
        a.push(x*y+1);
        
    }
    maxn=a.top();
    
    for(int i=1;i<=n-1;i++)         //求最小值
    {
        x=b.top();
        b.pop();
        y=b.top();
        b.pop();
        b.push(x*y+1);
    }
    minn=b.top();
  
    printf("%d",maxn-minn);
    
    return 0;
}