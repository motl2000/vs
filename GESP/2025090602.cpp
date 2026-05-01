//GESP2025年9月6级 货物运输
/*
贪心+树的深搜遍历
问题模型：
城市与道路构成一棵树（n节点，n-1条边）
需要找到从根节点出发，访问所有节点的最短路径
关键观察：
每条边至少走两次（去一次 + 回一次）
如果最后不返回首都，有一条从根到叶子的路径只需走一次（去不回）
最优策略：让最长的那条根到叶子的路径只走一次
*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 5;  // 最大城市数量
int n;                  // 实际城市数量
vector<vector<pair<int, int>>> e;  // 邻接表，pair<相邻城市, 道路长度>
long long s, mx;        // s: 所有道路长度总和，mx: 从首都到最远城市的距离

// 深度优先搜索，计算从首都到每个节点的距离，并找到最远距离
// u: 当前城市, f: 父城市, d: 当前已走路径长度
void dfs(int u, int f, long long d) {
    mx = max(d, mx);  // 更新最远距离
    
    // 遍历所有相邻城市
    for (auto p : e[u]) {
        int v = p.first;   // 相邻城市编号
        int w = p.second;  // 道路长度
        
        // 不返回父城市，避免重复遍历
        if (v != f) {
            dfs(v, u, d + w);  // 继续搜索，累加路径长度
        }
    }
}

int main() {
    scanf("%d", &n);
    e.resize(n + 1);  // 初始化邻接表
    
    // 读取所有道路信息
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].emplace_back(make_pair(v, w));//emplace_back是vector的成员函数，用于在vector的末尾添加一个元素，参数为pair<int, int>(v, w)
        e[v].emplace_back(make_pair(u, w));
        s += w;  // 累加所有道路长度总和
    }
    
    // 从首都(1号城市)出发，计算到每个城市的距离
    dfs(1, 0, 0);
    
    // 关键计算：
    // 遍历所有节点并返回起点需要 2*s 距离（每条边走两次）
    // 最后可以不返回首都，减去最长的返回路径 mx
    printf("%lld\n", s * 2 - mx);
    
    return 0;
}
