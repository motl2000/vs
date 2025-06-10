// 2025年3月八级考试
// 上学
// Dijkstra算法，用优先队列优化
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
const int N = 2e5 + 5;
const int E = N << 1;
const long long oo = 1e18;
int n, m, s, q;         //n节点数，m边数，s起点节点编号，q终点节点编号
int h[N], to[E], nx[E], wt[E], et;
int vis[N];
long long d[N];
priority_queue <pair<long long, int>> pq;
void ae(int u, int v, int w) {          //邻接表
   et++;
   to[et] = v;
   nx[et] = h[u];
   wt[et] = w;
   h[u] = et;
}
int main() {
   scanf("%d%d%d%d", &n, &m, &s, &q);
   for (int i = 1; i <= m; i++) {
       int u, v, l;
       scanf("%d%d%d", &u, &v, &l);
       ae(u, v, l);
       ae(v, u, l);
   }
   for (int i = 1; i <= n; i++)
       d[i] = oo;                       //初始化，oo表示无穷大
   d[s] = 0;
   pq.push({0, s});                     //从s点出发
   while (!pq.empty()) {
       auto p = pq.top();
       pq.pop();
       int u = p.second;
       if (vis[u])
           continue;
       vis[u] = 1;
       for (int i = h[u]; i; i = nx[i])     //遍历u的所有邻接点
           if (d[u] + wt[i] < d[to[i]]) {   //松弛操作
               d[to[i]] = d[u] + wt[i];
               pq.push({-d[to[i]], to[i]}); //入队，放负数是为了使优先队列按距离从小到大排序
           }
   }
   while (q--) {
       int p;
       scanf("%d", &p);
       printf("%lld\n", d[p]);          //s点到p点的最短距离
   }
   return 0;
}