//2025 CSP S 2 道路修复（road）
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 5;
const int K = 15;

struct Edge {
    int u, v, from;     // from=0 表示原始道路，from=i 表示第 i 个乡镇的边
    ll  w;              // 道路修复费用
};

int n, m, k;
int fa[N + K];               // 并查集
ll  c[K], a[K][N];           // 乡镇费用和造路费用
ll  ans = 0;                 // 初始为原始 MST 权值
vector<Edge> g;              // 初始 MST 边 + 所有乡镇边（已按 w 排序）

/* ---------- 并查集 ---------- */
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
//这里不写union函数的原因是，在两个不同的地方需要有两种不同的union方式
//与其写两个union函数还不如直接写在代码里，这样更清晰

/* ---------- 对当前乡镇状态 mask 求 MST ---------- */
void solve(int mask) {      //mask:第几个乡镇是否被选中进行城市化改造
    ll res = 0;
    for (int i = 1; i <= k; ++i)        //统计改造费用
        if (mask & (1 << (i - 1))) 
            res += c[i];

    for (int i = 1; i <= n + k; ++i)    // 初始化并查集n+k
        fa[i] = i;

    for (const Edge &e : g) {           
        if (e.from && !(mask & (1 << (e.from - 1)))) //如果不是原始道路，并且不是被选中的乡镇的道路，则跳过
            continue;
        //在原始道路和被选中的乡镇的道路上，都进行并查集操作，并统计总费用
        int u = find(e.u), v = find(e.v);
        if (u != v) {
            fa[v] = u;
            res += e.w;
        }
    }
    ans = min(ans, res);    //更新最小总费用
}

/* ---------- 主函数 ---------- */
int main() {
    cin >> n >> m >> k;

    /* 读原始道路 */
    vector<Edge> orig(m);
    for (int i = 0; i < m; ++i) {
        cin >> orig[i].u >> orig[i].v >> orig[i].w;
        orig[i].from = 0;
    }

    /* 读乡镇信息 */
    for (int i = 1; i <= k; ++i) {
        cin >> c[i];
        for (int j = 1; j <= n; ++j) cin >> a[i][j];
    }

    /* 对原始边排序，求初始 MST */
    sort(orig.begin(), orig.end(),
         [](const Edge &x, const Edge &y) { return x.w < y.w; });

    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (const Edge &e : orig) {            //g里存放了原始的MST
        int u = find(e.u), v = find(e.v);
        if (u != v) {
            fa[v] = u;
            ans += e.w;
            g.push_back(e);
        }
    }

    /* 加入所有乡镇边并排序 */
    for (int i = 1; i <= k; ++i)
        for (int j = 1; j <= n; ++j)
            g.push_back({n + i, j, i, a[i][j]});//这里的from=i，表示第i个乡镇的边

    sort(g.begin(), g.end(),
         [](const Edge &x, const Edge &y) { return x.w < y.w; });

    /* 枚举所有非零乡镇状态从1到2^k-1 */
    for (int mask = 1; mask < (1 << k); ++mask) 
        solve(mask);

    cout << ans << '\n';
    return 0;
}
