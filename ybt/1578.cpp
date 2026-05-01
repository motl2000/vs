//1578：【例 4】战略游戏
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1500; // 节点最大数量

vector<int> adj[MAXN]; // 邻接表
int dp[MAXN][2];       // dp[u][0] 不选，dp[u][1] 选
bool visited[MAXN];    // 访问标记

// DFS 构建树并进行树形DP
void dfs(int u) {
    visited[u] = true;
    dp[u][0] = 0;  // 不选 u，初始值为0
    dp[u][1] = 1;  // 选 u，初始值为1

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            // 更新父节点状态
            dp[u][0] += dp[v][1];           // 不选 u → 子节点必须选
            dp[u][1] += min(dp[v][0], dp[v][1]); // 选 u → 子节点可选可不选
        }
    }
}

int main() {
    int N;
    cin >> N;

    // 构建邻接表
    for (int i = 0; i < N; ++i) {
        int k;
        cin >> i >> k; // 注意输入格式：先读节点编号 i，再读 k
        for (int j = 0; j < k; ++j) {
            int neighbor;
            cin >> neighbor;
            adj[i].push_back(neighbor);
            adj[neighbor].push_back(i); // 无向图，双向添加
        }
    }

    // 从节点 0 开始 DFS
    dfs(0);

    // 输出结果
    cout << min(dp[0][0], dp[0][1]) << endl;

    return 0;
}