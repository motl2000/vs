//1488：新的开始
/*建立一个虚拟节点（编号为0），表示“电网”。
每个矿井到这个虚拟节点的边权是建发电站的费用。
矿井之间的连接费用就是电网连接费用。
然后在这个扩展图中跑一个最小生成树,可以用 Kruskal 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, cost;
};

bool cmp(Edge a, Edge b) {
    return a.cost < b.cost;
}

int parent[1005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return false;//如果这条边连接了两个已经连通的分量，则不需要连接
    parent[fy] = fx;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> power(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
    }

    vector<Edge> edges;

    // 添加虚拟节点0到每个矿井的发电站边
    for (int i = 1; i <= n; i++) {
        edges.push_back({0, i, power[i]});
    }

    // 添加矿井之间的电网边
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int p;
            cin >> p;
            if (i < j) { // 避免重复添加
                edges.push_back({i, j, p});
            }
        }
    }

    sort(edges.begin(), edges.end(), cmp);

    // 初始化并查集
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int total_cost = 0;
    int num_edges = 0;
    for (auto e : edges) {
        if (unite(e.u, e.v)) {
            total_cost += e.cost;
            ++num_edges;
            if (num_edges == n) break; // 当连接了n个节点时，可以提前结束
        }
    }
    cout << total_cost << endl;

    return 0;
}
