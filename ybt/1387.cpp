//1387：搭配购买(buy)
//思路：确定每个集合的价钱和价值，然后进行01背包问题求解
#include<bits/stdc++.h>
using namespace std;
#define N 10005
int n, m, wn;
int fa[N], c[N], d[N];      //c[i]：以i为根结点的集合的总价钱 d[i]：i为根结点的集合的总价值 
int v[N], w[N], an, dp[N];  //背包问题 v:价值 w:重量  dp[j]：前i个物品装入大小为j的背包的最大价值, an:集合的个数
void init()
{
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
}
int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if(x != y)
    {
        fa[x] = y;
        c[y] += c[x];
        d[y] += d[x];
    }
}
int main()
{
    int f, t;
    cin >> n >> m >> wn;
    init();                     //并查集初始化 
    for(int i = 1; i <= n; ++i)
        cin >> c[i] >> d[i];
    for(int i = 1; i <= m; ++i)//根据输入的关系构成集合 
    {
        cin >> f >> t;
        merge(f, t);
    }
    for(int i = 1; i <= n; ++i)//寻找根结点，将每个集合的价钱和价值提取出来 
    {
        if(fa[i] == i)
        {
            v[++an] = d[i];     //d[i]：以i为根结点的集合的总价值
            w[an] = c[i];       //c[i]：以i为根结点的集合的总价钱
        }
    }
    for(int i = 1; i <= an; ++i)//01背包问题：有an个商品，第i商品价值v[i]，重量w[i]，背包大小wn。 
        for(int j = wn; j >= w[i]; --j)
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
    cout << dp[wn];
    return 0;
}