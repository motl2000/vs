//1495：【例 2】孤岛营救问题
#include <bits/stdc++.h>
using namespace std;

/*================  全局变量  ================*/
int row, line, keyCnt, wallCnt;     // row：行数  line：列数  keyCnt：钥匙种类数  wallCnt：墙数
int nodeID[25][25], nodeTot;        // nodeID[i][j]：第i行第j列的格子编号，nodeTot：格子总数
int maze[205][205];                 // maze[i][j]：i到j的墙或门的类型  -1：墙 0：门 1-15：钥匙
int keyPos[15][25], keyNum[15];     // keyPos[i][j]：第i种钥匙的第j个位置，keyNum[i]：第i种钥匙的数量

const int INF = 0x3f3f3f3f;
int dis[102405];                    // 最短路
bool inq[102405];                   // 是否在队列中
int q[1000005];                     // 队列 

/*================  前向星  ================*/
struct Edge {
    int to, w, next;
} e[1000005];
int head[102405], ecnt;
inline void addEdge(int u, int v, int w) {
    e[++ecnt] = {v, w, head[u]};
    head[u] = ecnt;
}

/*================  SPFA  ================*/
void spfa(int S) {
    memset(dis, 0x3f, sizeof(dis));
    memset(inq, 0, sizeof(inq));
    int h = 0, t = 0;
    q[t++] = S;
    dis[S] = 0; inq[S] = true;
    while (h < t) {
        int u = q[h++]; inq[u] = false;
        for (int i = head[u]; i; i = e[i].next) {
            int v = e[i].to, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!inq[v]) { inq[v] = true; q[t++] = v; }
            }
        }
    }
}

/*================  建图  ================*/
void build() {
    int M = row * line;                // 单层节点数
    int layer = 1 << keyCnt;           // 层数，即钥匙状态数，每种钥匙有0/1两种状态，n种钥匙有2^n种状态
    int N = M * layer;                 // 总节点数

    /* 单层内四连通 */
    for (int mask = 0; mask < layer; ++mask) {  // mask:当前状态，遍历所有钥匙状态的组合
        bool hasKey[15] = {false};              // 是否有这把钥匙
        for (int i = 1; i <= keyCnt; ++i)       // 初始化在当前层，有哪些种钥匙
            hasKey[i] = (mask >> (i - 1)) & 1;  

        for (int i = 1; i <= row; ++i)
            for (int j = 1; j <= line; ++j) {
                int u = nodeID[i][j];           // u:当前起始节点
                /* 右 */
                if (j < line) {
                    int v = nodeID[i][j + 1];   // v:当前目标节点
                    int type = maze[u][v];      // type:u到v的墙或门的类型
                    if (type != -1) {           // 不是墙
                        if (type == 0 || hasKey[type]) {//如果可以通过，则添加边
                            addEdge(mask * M + u, mask * M + v, 1);
                            addEdge(mask * M + v, mask * M + u, 1);
                        }
                    }
                }
                /* 下 */
                if (i < row) {
                    int v = nodeID[i + 1][j], type = maze[u][v];
                    if (type != -1) {
                        if (type == 0 || hasKey[type]) {
                            addEdge(mask * M + u, mask * M + v, 1);
                            addEdge(mask * M + v, mask * M + u, 1);
                        }
                    }
                }
            }

        /* 拾钥匙转移 */
        for (int k = 1; k <= keyCnt; ++k) {
            if (hasKey[k]) continue;            // 已有这把钥匙
            // 当前层捡到的新钥匙
            int nxt = mask | (1 << (k - 1));    // 捡到新钥匙后可以去往的层数
            for (int i = 1; i <= keyNum[k]; ++i) {
                int x = keyPos[k][i];
                addEdge(mask * M + x, nxt * M + x, 0);// 
            }
        }
    }
}

/*================  读入  ================*/
void read() {
    cin >> row >> line >> keyCnt >> wallCnt;
    /* 给格子编号 */
    int id = 0;
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= line; ++j)
            nodeID[i][j] = ++id;
    nodeTot = id;

    memset(maze, 0, sizeof(maze));
    /* 墙或门 */
    for (int i = 1; i <= wallCnt; ++i) {
        int x1, y1, x2, y2, p;
        cin >> x1 >> y1 >> x2 >> y2 >> p;
        int u = nodeID[x1][y1], v = nodeID[x2][y2];
        maze[u][v] = maze[v][u] = (p == 0 ? -1 : p);    // 墙或门
    }
    /* 钥匙 */
    int keyTot;  
    cin >> keyTot;
    for (int i = 1; i <= keyTot; ++i) {
        int x, y, type;  
        cin >> x >> y >> type;
        //type钥匙类型，keyNum[type]:type类型的钥匙数量
        //type类型的第keyNum[type]+1个钥匙的位置为nodeID[x][y]
        keyPos[type][++keyNum[type]] = nodeID[x][y];
    }
}

/*================  主过程  ================*/
void solve() {
    int M = row * line;
    int layer = 1 << keyCnt;
    int S = 0 * M + nodeID[1][1];      // 起点：第一层，(1,1)
    spfa(S);

    int T = nodeID[row][line];
    int ans = INF;
    for (int mask = 0; mask < layer; ++mask)
        ans = min(ans, dis[mask * M + T]);
    cout << (ans == INF ? -1 : ans) << endl;
}

/*================  main  ================*/
int main() {
    read();
    build();
    solve();
    return 0;
}
