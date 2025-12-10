//1529：欧拉回路
// #include<cstdio>
// #include<cstring>
// #include<vector>
// #include<set>
// using namespace std;
// struct sd//定义结构体，存储边
// {
// 	int a,b;
// 	bool operator < (const sd& c) const
// 	{
// 		if (a<c.a) ;
// 		return 1;
// 		if (a==c.a && b<c.b) ;
// 		return 1;
// 		return 0;
// 	}
// } p;
// int n,m,pt=0;//pt为当前点数
// int x[1005];
// vector<int> mp[1005]; //邻接表存储图
// set<sd> kk;
// void dfs(int v)
// {
// 	for (int i=mp[v].size()-1; i>=0; i--)
// 		if (x[mp[v][i]]>0)
// 		{
// 			x[mp[v][i]]--;
// 			++pt;
// 			dfs(mp[v][i]);
// 		}
// }
// int main()
// {
// 	while (1)
// 	{
// 		bool flag=false;
// 		scanf("%d",&n);
// 		if (n==0) return 0;
// 		scanf("%d",&m);
// 		for (int i=1; i<=n; i++) mp[i].clear();
// 		memset(x,0,sizeof x);
// 		kk.clear();
// 		for (int a,b,t,i=1; i<=m; i++)
// 		{
// 			scanf("%d%d",&a,&b);
// 			if (a==b) continue ;
// 			if (a>b) swap(a,b);
// 			p.a=a,p.b=b;
// 			if (kk.count(p)) continue;//如果已经存在，则跳过
// 			kk.insert(p);
// 			mp[a].push_back(b);
// 			++x[a];
// 			mp[b].push_back(a);
// 			++x[b];
// 		}
// 		for (int i=1; i<=n; i++)
// 			if (x[i]==0 || x[i] % 2==1)//如果有奇数个点，则不存在欧拉回路
// 			{
// 				flag=1;
// 				break;
// 			}
// 		if (flag)
// 		{
// 			printf("0\n");
// 			continue;
// 		}
// 		x[1]=-1;
// 		pt=1;
// 		dfs(1);
// //      if (pt==n)
// 		printf("1\n");
// 	}
// 	return 0;
// }

#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <numeric>      // iota
using namespace std;

struct sd {
    int a, b;
    bool operator<(const sd& c) const {
        if (a != c.a) return a < c.a;
        return b < c.b;
    }
} p;

const int MAXN = 1005;
int n, m;
int deg[MAXN], fa[MAXN];
vector<int> mp[MAXN];
set<sd> kk;

/* ---------- 并查集 ---------- */
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
    while (1) {
        scanf("%d", &n);
        if (n == 0) return 0;
        scanf("%d", &m);

        /* ---- 初始化 ---- */
        for (int i = 1; i <= n; ++i) mp[i].clear();
        memset(deg, 0, sizeof(deg));
        kk.clear();
        iota(fa + 1, fa + n + 1, 1);   // 并查集初始化

        /* ---- 读边 + 去重 + 建邻接表 + 合并 ---- */
        for (int a, b, i = 0; i < m; ++i) {
            scanf("%d%d", &a, &b);
            if (a == b) continue;
            if (a > b) swap(a, b);
            p.a = a, p.b = b;
            if (kk.count(p)) continue;   // 重边跳过
            kk.insert(p);
            mp[a].push_back(b);
            mp[b].push_back(a);
            ++deg[a];
            ++deg[b];
            fa[find(a)] = find(b);       // 合并连通块
        }

        /* ---- 度数奇偶检查 ---- */
        bool ok = true;
        for (int i = 1; i <= n; ++i)
            if (deg[i] & 1) { ok = false; break; }

        if (!ok) { printf("0\n"); continue; }

        /* ---- 并查集连通性检查 ---- */
        int pivot = 0;
        for (int i = 1; i <= n; ++i)
            if (deg[i]) { pivot = i; break; }

        if (pivot) {                       // 有边才需要检查
            int root = find(pivot);
            for (int i = pivot + 1; i <= n; ++i)
                if (deg[i] && find(i) != root) { ok = false; break; }
        }

        printf("%d\n", ok ? 1 : 0);
    }
    return 0;
}
