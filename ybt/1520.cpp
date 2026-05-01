//1520：【 例 1】分离的路径
#include <bits/stdc++.h>
using namespace std;

#define N 5005  // 最大草场数量

int n, m;                // n: 草场数量, m: 现有道路数量
int fa[N];               // fa[u]: DFS树中u的父节点
int ebc[N];              // ebc[u]: 节点u所属的双连通分量编号
int en;                  // 双连通分量的总数
int deg[N];              // 每个双连通分量在缩点后的树中的度数
vector<int> edge[N];     // 邻接表存储图

int dfn[N], low[N];      // Tarjan算法中:dfn[u]为节点u的访问序号,low[u]为u能回溯到的最小序号
int ts;                  // 时间戳计数器
stack<int> stk;          // 用于存储当前搜索栈中的节点

/**
 * @brief Tarjan算法求边双连通分量(EBC)
 * 
 * 原理：通过dfn和low数组识别桥（割边），桥之间的连通块即为边双连通分量
 * 特殊处理：使用fromEdge计数来处理平行边（重边），确保平行边不被误判为桥
 * 
 * @param u 当前节点
 */
void tarjan(int u)
{
    // t: 临时变量, fromEdge: 记录从父节点fa[u]到u的边的出现次数（处理重边）
    int t, fromEdge = 0;
    
    // 初始化当前节点的访问序号和low值
    dfn[u] = low[u] = ++ts;
    stk.push(u);  // 将当前节点压入栈
    
    // 遍历u的所有邻接点
    for(int v : edge[u])
    {
        // 如果v未被访问过，则是树边
        if(dfn[v] == 0)
        {
            fa[v] = u;      // 记录父节点
            tarjan(v);      // 递归访问子节点
            
            // 用子节点的low值更新当前节点的low值
            low[u] = min(low[u], low[v]);
        }
        // 否则是回边（非树边）或重边
        // 条件v != fa[u] || ++fromEdge > 1的含义：
        // - 如果v不是父节点，一定是回边，更新low
        // - 如果v是父节点，只有这是第二条以上的边（++fromEdge > 1）才更新low，
        //   这样可以确保重边不会使桥被误判
        else if(v != fa[u] || ++fromEdge > 1)
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
    // 如果dfn[u] == low[u]，说明u是双连通分量的根节点
    // 此时栈中从u到栈顶的所有节点构成一个边双连通分量
    if(dfn[u] == low[u])
    {
        en++;  // 双连通分量编号+1
        do
        {
            t = stk.top();    // 取出栈顶节点
            stk.pop();        // 弹出
            ebc[t] = en;      // 标记该节点属于当前双连通分量
        }while(t != u);       // 直到弹出u为止
    }
}

int main()
{
    int f, t;
    int degOneCt = 0;  // 度为1的双连通分量数量（叶子节点数）
    
    // 输入草场数量和道路数量
    cin >> n >> m;
    
    // 读取所有道路并构建无向图
    for(int i = 1; i <= m; ++i)
    {
        cin >> f >> t;
        edge[f].push_back(t);
        edge[t].push_back(f);
    }
    
    // 对每个未访问的节点运行Tarjan算法
    // 虽然题目保证连通，但这样处理更健壮
    for(int v = 1; v <= n; ++v)
    {
        if(dfn[v] == 0)
            tarjan(v);
    }
    
    // 统计双连通分量之间的连接关系（桥）
    // 遍历所有边，如果边的两个端点属于不同分量，则这两个分量之间有桥相连
    for(int u = 1; u <= n; ++u)
    {
        for(int v : edge[u])
        {
            if(ebc[v] != ebc[u])  // 属于不同分量
            {
                deg[ebc[v]]++;    // 两个分量的度数都+1
                deg[ebc[u]]++;
            }
        }
    }
    
    // 由于每条边被统计了两次（u->v和v->u），所以度数要除以2
    for(int i = 1; i <= en; ++i)
        deg[i] /= 2;
    
    // 统计缩点后树中叶子节点的数量（度为1的连通分量）
    // 这些叶子节点代表"瓶颈"区域，必须添加道路使其有两条不相交路径
    for(int i = 1; i <= en; ++i)
    {
        if(deg[i] == 1)
            degOneCt++;
    }
    
    // 关键结论：在树中，最少添加(叶子数+1)/2条边可使图强连通（无桥）
    // 例如：两个叶子之间加一条边可消除两个叶子
    // 所以答案是向上取整的叶子数的一半
    cout << (degOneCt+1)/2;
    
    return 0;
}
