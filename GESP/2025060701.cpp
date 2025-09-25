#include <cstdio>
using namespace std;
const int N = 1e5 + 5;
int n, m, deg[N];
long long ans;
int main()
{
    scanf("%d%d", &n, &m);
    while (m--)                 //遍历所有边，统计每个节点的度数
    {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++;
        deg[v]++;
    }
    //G中每个节点的度数说明该节点可以直接连接到的顶点数，
    //这些顶点可以形成 deg[i] * (deg[i] - 1) / 2 条边(简单图最大边数)
    //这些边就是可以在L中形成的边
    for (int i = 1; i <= n; i++)
        ans += 1ll * deg[i] * (deg[i] - 1) / 2; 
    printf("%lld\n", ans);
    return 0;
}