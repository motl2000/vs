//1505：【例 2】双调路径
//注意：“一条路径越快，或者费用越低，该路径就越好。”，这里用的是“或者”，而不是“且”。
//使用树状数组求区间最值，可以在讲到树状数组时练习此题
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
const int N = 1e4 + 5;
int nxt[605], tim[605], fee[605], to[605], poi[605];
int que[1000005][2], dis[105][N], vis[105][N];//que[i][0]表示第i个点的编号，que[i][1]表示第i个点的费用,dis[i][j]表示从s到i的最短路径，费用为j,vis[i][j]表示i点是否在队列中，费用为j
int delt[105][N];        //delt[i][j]表示从s到i的最短路径，费用为j的最短路径时间，树状数组，下标从1开始，维护前缀最小值
int tot, n, m, s, t, ans;
void add(int x, int y, int z, int w)// x->y, z为时间, w为费用
{
    nxt[++tot] = poi[x];
    poi[x] = tot;
    to[tot] = y;
    tim[tot] = z;
    fee[tot] = w;
}
int query(int x, int y) // 查询 dis[x][0…y]的最小值,y为费用,这里的最小值指的是最短路径时间
{
    ++y; // 树状数组不支持下标为0,所以下标整体加1
    int mn = 1e7;
    for (; y; y -= (y & -y))        // 从y开始,每次减去y的最低位1,即y&-y
        mn = min(mn, delt[x][y]);
    return mn;
}
void updata(int x, int y, int val) // 树状数组的更新
{
    ++y; // 树状数组不支持下标为0,所以下标整体加1
    for (; y <= n * 100; y += (y & -y))
        delt[x][y] = min(delt[x][y], val);
}
void spfa()
{
    memset(dis, 63, sizeof(dis));           // 初始化最短路径时间为无穷大
    memset(delt, 63, sizeof(delt));         // 初始化树状数组为无穷大
    que[1][0] = s, que[1][1] = 0;           // 起点s入队,费用为0
    dis[s][0] = 0;
    updata(s, 0, 0);
    for (int q1 = 1, q2 = 1; q1 <= q2; ++q1)//q1为队首，q2为队尾
    {
        int x = que[q1][0], f1 = que[q1][1];
        vis[x][f1] = 0;
        for (int i = poi[x], y; i && (y = to[i]); i = nxt[i])//i为当前边，y为i的终点，即遍历x的所有出边
        {
            int f2 = f1 + fee[i];                    //f2为i的费用
            // 如果到y点的费用为f2时的最短路径时间小于之前的最短路径时间，满足条件
            if (query(y, f2) > dis[x][f1] + tim[i]) //query(y, f2) 表示从s到y的最短路径，费用为f2,dis[x][f1] + tim[i] 表示从x到y的最短路径，费用为f1+i的费用
            {
                dis[y][f2] = dis[x][f1] + tim[i];
                updata(y, f2, dis[y][f2]);  //更新y点费用为f2的最短路径时间

                if (!vis[y][f2])
                {
                    vis[y][f2] = 1;
                    que[++q2][0] = y, que[q2][1] = f2;//y入队，费用为f2
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; ++i)
    {
        int x, y, w, z;
        scanf("%d%d%d%d", &x, &y, &w, &z);
        add(x, y, z, w);
        add(y, x, z, w);
    }
    spfa();
    int mn = dis[0][0]; // 费用递增,时间递减
    for (int i = 0; i <= n * 100; ++i)
        if (dis[t][i] < mn)
        {
            ++ans;
            mn = dis[t][i];
        }
    printf("%d", ans);
}