//1392：繁忙的都市(city)
#include<bits/stdc++.h>
using namespace std;
#define N 305
struct Edge
{
    int f, t, w;
    Edge(){}
    Edge(int a, int b, int c):f(a),t(b),w(c){};
    bool operator < (const Edge &b) const
    {
        return w < b.w;
    }
};
vector<Edge> edges;
bool vis[N];
int fa[N];
int n, m, mx, en;
void initFa()
{
    for(int i = 1; i <= n; ++i)
        fa[i] = i;
}
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
void merge(int x, int y)
{
    fa[find(x)] = find(y);
}
void init()
{
    int f, t, w;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i)
    {
        cin >> f >> t >> w;
        edges.push_back(Edge(f, t, w));
    }
}
void kruskal()
{
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); ++i)
    {
        int f = edges[i].f, t = edges[i].t, w = edges[i].w;
        if(find(f) != find(t))
        {
            merge(f, t);
            mx = max(mx, w);        //记录最大边权值
            if(++en == n - 1)
                break;
        }
    }
}
int main()
{
    init();
    initFa();
    kruskal();
    cout << n-1 << ' ' << mx;       //最少的道路数是交叉路口数-1
    return 0;
}

