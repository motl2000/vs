//1490：秘密的牛奶运输
/*
1. 先用 Kruskal 求出最小生成树（MST），并记录用了哪些边。
2. 对于每条不在 MST 中的边，尝试替换 MST 中路径上的最大边，得到一个新的生成树。
3. 所有这样得到的生成树中，权值最小且严格大于 MST 的，就是次小生成树。
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 2005;
const int MAXM = 20005;
const int LOG = 12;
const int INF = 1e9;

struct Edge {
    int u, v, w;
    bool used;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int n, m;               //n个点，m条边
Edge edges[MAXM];
int parent[MAXN];

// LCA 和路径最大值、次大值
int depth[MAXN];        // 深度
int up[MAXN][LOG];      // 2^i 祖先
int max1[MAXN][LOG];    // 最大值,max1[u][i] 表示 u 到 2^i 祖先的最大边权
int max2[MAXN][LOG];    // 严格次大值
vector<pair<int, int>> adj[MAXN]; // to, weight, 邻接表

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    parent[fy] = fx;
    return true;
}

// 深度优先搜索，用于构建LCA和路径最大值、次大值信息
void dfs(int u, int p, int w) {
    depth[u] = depth[p] + 1;        // 深度
    up[u][0] = p;                   // 2^0 祖先
    max1[u][0] = w;                 // 2^0 祖先的最大边权
    max2[u][0] = -INF;              // 2^0 祖先的次大边权
    for (int i = 1; i < LOG; i++) {
        up[u][i] = up[up[u][i-1]][i-1]; // 2^i 祖先
        int a = max1[u][i-1];           // 2^i 祖先的最大边权
        int b = max1[up[u][i-1]][i-1];  // 2^i 祖先的次大边权
        max1[u][i] = max(a, b);
        max2[u][i] = max(max2[u][i-1], max2[up[u][i-1]][i-1]);
        if (a != b) max2[u][i] = max(max2[u][i], min(a, b));
    }
    for (auto [v, c] : adj[u]) {
        if (v == p) continue;
        dfs(v, u, c);
    }
}

// 查询 u-v 路径上严格小于 lim 的最大边权
int query(int u, int v, int lim) {
    if (depth[u] < depth[v]) swap(u, v);
    int res = -INF;
    for (int i = LOG-1; i >= 0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) {
            if (max1[u][i] < lim) res = max(res, max1[u][i]);
            else if (max2[u][i] < lim) res = max(res, max2[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return res;
    for (int i = LOG-1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            if (max1[u][i] < lim) res = max(res, max1[u][i]);
            else if (max2[u][i] < lim) res = max(res, max2[u][i]);
            if (max1[v][i] < lim) res = max(res, max1[v][i]);
            else if (max2[v][i] < lim) res = max(res, max2[v][i]);
            u = up[u][i];
            v = up[v][i];
        }
    }
    if (max1[u][0] < lim) res = max(res, max1[u][0]);
    else if (max2[u][0] < lim) res = max(res, max2[u][0]);
    if (max1[v][0] < lim) res = max(res, max1[v][0]);
    else if (max2[v][0] < lim) res = max(res, max2[v][0]);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].used = false;
    }
    sort(edges, edges + m);

    for (int i = 1; i <= n; i++) parent[i] = i;

    long long mst = 0;                          // 最小生成树的权值
    for (int i = 0; i < m; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            mst += edges[i].w;
            edges[i].used = true;
            adj[edges[i].u].push_back({edges[i].v, edges[i].w});
            adj[edges[i].v].push_back({edges[i].u, edges[i].w});
        }
    }

    depth[0] = 0;
    dfs(1, 0, -INF);

    long long second_mst = 1e18;
    for (int i = 0; i < m; i++) {   // 枚举每条边，尝试替换MST中路径上的最大边
        if (!edges[i].used) {       // 如果这条边不在MST中，
            int max_e = query(edges[i].u, edges[i].v, edges[i].w);// 找出u-v路径上最大边权
            if (max_e != -INF) {    // 如果存在最大边
                long long new_cost = mst - max_e + edges[i].w;  // 替换最大边
                if (new_cost > mst) second_mst = min(second_mst, new_cost);
            }
        }
    }

    cout << second_mst << endl;

    return 0;
}
