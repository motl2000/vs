//1489：构造完全图
/*
要让 T 是唯一 MST，必须满足：对于任意不在 T 中的边 (u, v)，其权值必须严格大于 T 中 u 到 v 路径上的最大边权。
为了最小化 G 的总边权和，我们应将这些非树边的权值设为 T 中路径上的最大边权 + 1。
所以我们可以：
1. 遍历所有非树边 (u, v)。
2. 找出 T 中 u 到 v 路径上的最大边权  max_edge 。
3. 把这条非树边的权值设为  max_edge + 1 。
4. 累加所有边权（树边 + 非树边）即为答案。

用 并查集 + Kruskal 逆向思维：
按边权从小到大处理树边。
每加入一条树边 (u, v, w)，它会连接两个连通块 A 和 B。
那么所有跨越 A 和 B 的非树边，其权值必须 ≥ w + 1。
这样的非树边共有  |A| * |B| - 1  条（减去已加入的树边）。
所以这些边的总贡献为： (size[A] * size[B] - 1) * (w + 1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent[MAXN];
int sz[MAXN];           

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return false;
    if (sz[fx] < sz[fy]) swap(fx, fy);
    sz[fx] += sz[fy];
    parent[fy] = fx;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<Edge> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;                  
    }

    long long total = 0;
    for (auto e : edges) {
        int u = e.u, v = e.v, w = e.w;
        int fu = find(u);
        int fv = find(v);
        total += (long long)(sz[fu] * sz[fv] - 1) * (w + 1);
        total += w; // 树边本身也要加
        unite(fu, fv);
    }

    cout << total << endl;

    return 0;
}
