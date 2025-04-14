//1386：打击犯罪(black)
#include <bits/stdc++.h>
using namespace std;
#define N 1005
int fa[N], ct[N], n;            //ct[i]:以i为根结点的集合的顶点数 
vector<int> edge[N];            //edge[i]：保存i的邻接点，i和t有联系。
void initFa(int n)              
{
    for(int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        ct[i] = 1;
    }
}
int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return fa[x] = find(fa[x]);
}
void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if(x != y)
    {
        ct[y] += ct[x];
        fa[x] = y;
    }
}
int main()
{
    int m, t;
    cin >> n;
    for(int f = 1; f <= n; ++f)
    {
        cin >> m;
        for(int i = 1; i <= m; ++i)
        {
            cin >> t;
            edge[f].push_back(t);  //edge[f]：保存f的邻接点，f和t有联系。
            edge[t].push_back(f);  //无向图，双向添加边
        }
    }
    initFa(n);                      //初始化并查集
    /*
    逆向思维：倒序遍历时，我们实际上是在模拟逐步保留更大编号的节点（相当于逆向删除小编号节点）
    ，这样当首次发现某个k的连通分量超过n/2时，说明必须保留k节点才能避免触发条件，因此需要删除1~k节点
    */
    for(int k = n; k >= 1; --k)     
    {
    	for(int v : edge[k])
        	if(v > k)               //只取大于k的顶点
                merge(k, v);        //与k进行合并 
        if(ct[find(k)] > n/2)       //如果合并后k所在的连通分量（集合）顶点数大于n/2 
        {
            cout << k;//应该删除1~k 
            return 0;
        } 
    }
    return 0;
}
