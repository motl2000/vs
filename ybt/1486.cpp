//1486：【例题1】黑暗城堡
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const long long MOD = pow(2, 31) - 1;//别忘了取膜
int n, m, x, y, num, head[1000001], vis[1000001];
long long ans, z, dis[1000001], f[1001][1001];//这些变量最好开long long
struct node
{
    int next, to;
    long long val;
}stu[1000001];
inline void add(int x, int y, int z)
{
    stu[++num].next = head[x];
    stu[num].to = y;
    stu[num].val = z;
    head[x] = num;
    return;
}
inline void spfa(int s)//SPFA最短路
{
    memset(vis, 0, sizeof(vis));
    memset(dis, INF, sizeof(dis));
    queue < int > pru;
    pru.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while(!pru.empty())
    {
        int u = pru.front();
        pru.pop();
        vis[u] = 0;
        for(register int i = head[u]; i; i = stu[i].next)
        {
            int k = stu[i].to;
            if(dis[k] > dis[u] + stu[i].val)
            {
                dis[k] = dis[u] + stu[i].val;
                if(!vis[k])
                {
                    vis[k] = 1;
                    pru.push(k);
                }
            }
        }
    }
    return;
}
int main()
{
    memset(f, INF, sizeof(f));//初始化
    scanf("%d %d", &n, &m);
    for(register int i = 1; i <= m; ++i)
    {
        scanf("%d %d %lld", &x, &y, &z);
        add(x, y, z);//无向图
        add(y, x, z);
        f[x][y] = f[y][x] = z;
    }
    spfa(1);//从1号节点出发的到每个节点的最短路径长度
    ans = 1;//初始化为1
    for(register int i = 2; i <= n; ++i)//1号节点不算
    {
        int sum = 0;//当前节点的方案数
        for(register int j = 1; j <= n; ++j)//枚举
        {
            if(dis[i] == dis[j] + f[i][j])//如果现在连接点i和j，从1到i的最短路径长度等于从1到j的最短路径长度加上i到j的边长，则i和j是连通的，方案数+1
            {
                ++sum;
            }
        }
        ans = ans * sum % MOD;//乘法原理 + 边乘边膜，每一层有n1,n2,n3...nk个点，则方案数为n1*n2*n3...nk，所以每一层的方案数乘起来，最后取膜
    }
    printf("%lld", ans);
    return 0;
}