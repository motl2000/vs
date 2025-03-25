// 1376：信使(msner)
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAXN = 105;
const int INF = INT_MAX;

vector<pair<int, int>> adj[MAXN]; // 邻接表存储图
int dist[MAXN];                   // 存储从起点到各点的最短距离
//最简洁的Dijkstra算法
void dijkstra(int start)                
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 小根堆，存储距离和顶点，按距离排序，方便取出最小距离的顶点
    fill(dist, dist + MAXN, INF);                                                       // 初始化距离为无穷大
    dist[start] = 0;
    pq.push({0, start}); // 起点入队

    while (!pq.empty())
    {
        int u = pq.top().second;        // 顶点
        int d = pq.top().first;         // 距离
        pq.pop();

        if (d > dist[u])                // 如果当前距离大于最短距离，则跳过
            continue;

        for (const auto &edge : adj[u])       // 遍历所有邻接点
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])  
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)             // 读入m条通信线路，构建邻接表
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});           // 假设通信线路是双向的
    }

    dijkstra(1);

    int maxDist = 0;                        
    for (int i = 1; i <= n; ++i)            // 找到最大的最短距离
    {
        if (dist[i] == INF)                 // 如果有点不可达，则输出-1
        {
            cout << -1 << endl;
            return 0;
        }
        maxDist = max(maxDist, dist[i]);
    }

    cout << maxDist << endl;
    return 0;
}
