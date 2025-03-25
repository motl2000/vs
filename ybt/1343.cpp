//1343：【例4-2】牛的旅行
//这题太复杂了，等我学完图论再来做
#include<bits/stdc++.h>
using namespace std;
#define N 200
#define MAXDOUB 1e9
struct Cord
{
    int x, y;
};
Cord cord[N];
bool edge[N][N];            //邻接矩阵 
vector<int> conn[N];        //conn[i]:第i个连通分量，里面保存了这个连通分量中的各个顶点
int n, cn;                  //n:顶点数 cn连通分量的个数，conn的数量 
bool vis[N];
double dis[N][N];
int dv[N];                  //dv[i]:与顶点i在同一连通分量中的 到顶点i最短路径最长的顶点
double mxDis[N];            //mxDis[i]:第i个连通分量中两点间最长的最短路径长度 
double ans = MAXDOUB; 
double getDis(Cord &a, Cord &b)//两点间距离 
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
} 
void initGraph()            //初始化图
{
    char c;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> cord[i].x >> cord[i].y;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            cin >> c;
            edge[i][j] = c - '0';//如果c为'0'，edge[i][j]为0，如果c为'1'，edge[i][j]为1 
        }
}
void dfs(int v)             //深度优先搜索,找出连通分量
{
    for(int i = 1; i <= n; ++i)
    {
        if(edge[v][i] && vis[i] == false)
        {
            vis[i] = true;
            conn[cn].push_back(i);
            dfs(i);
        }
    }
}
void initConn()             //初始化连通分量vector数组 
{                           //类似解连通块问题 
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i] == false)
        {
            vis[i] = true;
            conn[++cn].push_back(i);//conn从下标1开始存
            dfs(i);
        }
    }
}
void floyd()                //floyd算法求最短路径
{
    memset(dis, 0x43, sizeof(dis));//将dis各元素设为无穷大 
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
            if(i == j)
                dis[i][j] = 0;
            else if(edge[i][j])
                dis[i][j] = getDis(cord[i], cord[j]);
        }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(dis[i][j] > dis[i][k] + dis[k][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
}
void initDv()                   //初始化dv和mxDis。dv[i]:与顶点i在同一连通分量中的 到顶点i最短路径最长的顶点 
{
    for(int k = 1; k <= cn; ++k)//遍历每个连通分量 
    {
        for(int i = 0; i < conn[k].size(); ++i)
        {
            double mx = -1;     //u到本连通分量中的另一个顶点最短路径中的最大值 
            int u = conn[k][i];
            for(int j = 0; j < conn[k].size(); ++j)
            {
                int v = conn[k][j];
                if(mx < dis[u][v])
                {
                    mx = dis[u][v];
                    dv[u] = v;
                }
            }
            mxDis[k] = max(mxDis[k], mx); 
        }
    }
}
int main()
{
    initGraph();
    initConn();
    floyd();
    initDv();
    for(int a = 1; a <= cn; ++a)//遍历每对连通分量 
        for(int b = a + 1; b <= cn; ++b)
        {
            for(int i = 0; i < conn[a].size(); ++i)
                for(int j = 0; j < conn[b].size(); ++j)
                {
                    int u = conn[a][i], v = conn[b][j];//选择a连通分量中的u与b连通分量中的v进行连线 
                    double x = dis[u][dv[u]] + dis[v][dv[v]] + getDis(cord[u], cord[v]);//从a中某顶点到b中某顶点的最短路径 
                    double d = max(max(mxDis[a], mxDis[b]), x);//将a与b连接后得到的新连通分量的直径 
                    ans = min(ans, d);//结果为新连通分量直径的最小值 
                }
        }
    cout << fixed << setprecision(6) << ans;
    return 0; 
}

