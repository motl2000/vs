//图上移动
#include <cstdio>
 using namespace std;
 const int K = 25;
 const int N = 505;
 const int E = N << 1;
 int n, m, k;
 int h[N], to[E], nx[E], et;
 int f[K][N][N];
 void ae(int u, int v) {                //邻接表
    et++;                               //边数
    to[et] = v;                         //边终点
    nx[et] = h[u];                      //节点u的领接表首加上et这条边
    h[u] = et;
 }
 int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {       //构建邻接表
        int u, v;
        scanf("%d%d", &u, &v);
        ae(u, v);
        ae(v, u);
    }
    for (int i = 1; i <= n; i++)        //初始化
        f[0][i][i] = 1;                 //每个节点一步都不走，可以到达自己
    for (int t = 1; t <= k; t++)
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= n; y++)
                if (f[t - 1][x][y])     //如果f[t-1][x][y]为真，说明x到y一步可以到达
                    for (int i = h[y]; i; i = nx[i])//遍历y的邻接表
                        f[t][x][to[i]] = 1;//第t步x可以y的邻接点
    for (int i = 1; i <= n; i++) {
        for (int t = 1; t <= k; t++) {
            int ans = 0;
            for (int j = 1; j <= n; j++)
                ans += f[t][i][j];      //统计节点i移动t步可以到达的节点数
            printf("%d%c", ans, " \n"[t == k]);
        }
    }
    return 0;
 }