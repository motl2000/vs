//1527：【例 1】欧拉回路
//这是书上代码，ybt站点会爆栈，有一个测试点无法通过
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
const int E = 10 * N;      // 无向图边数翻倍

int type, n, m, tot = 1;   // tot 从 1 开始，方便 i/2 得到边号，第一条边的编号为2
/*无向图的边号存储方式：由于无向图需要记录反向边，所以需要存储两条边
索引 i	边的方向	实际边编号 c = i / 2
2	    A → B	    2 / 2 = 1
3	    B → A	    3 / 2 = 1 （反向边）
4	    B → C	    4 / 2 = 2
5	    C → B	    5 / 2 = 2 （反向边）
*/
int head[N], ver[E], Next[E];//head: 邻接表,值为该顶点的第一条边，ver: 边，值为该边指向的另一个顶点，Next: 该边下一条边
int in[N], out[N];
bool flag[E];              // flag[c] 表示边 c 已用
vector<int> ans;

inline void add(int x, int y) {//添加边
    ver[++tot] = y;
    Next[tot] = head[x];
    head[x] = tot;
}

/* ---------- Hierholzer 递归版 ---------- */
void dfs(int x) {
    /* &i 与 head[x] 同步移动，实现当前弧优化，避免重复检查已经处理过的边 
    1. int &i = head[x] ：
        i 是 head[x] 的引用，直接绑定到 head[x] 。
        对 i 的修改会同步修改 head[x] 。
    2. i = Next[i] ：
        每次迭代后， i （即 head[x] ）会被更新为下一条边的索引（ Next[i] ）。
        效果：下次从 x 出发时，会直接从尚未处理的边开始，跳过已处理的边
    */
    for (int &i = head[x], y; y = ver[i], i; i = Next[i]) {//i是边号，y是该边指向的顶点
        int c = (type == 1 ? i / 2 : i - 1);   // 边号，无向图为 i/2，有向图为 i-1
        int sig = i % 2;                       // 1 表示反向边
        if (flag[c]) continue;                 // 如果边已用，则跳过
        flag[c] = true;
        dfs(y);
        if (type == 1) 
            ans.push_back(sig ? -c : c);//注意：这题需要输出无向图边的方向
        else           
            ans.push_back(c);
    }
}

int main() {
    scanf("%d%d%d", &type, &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        if (type == 1) add(y, x);   // 无向图再加反向边
        out[x]++; in[y]++;
    }

    /* ---------- 判定 ---------- */
    if (type == 1) {
        for (int i = 1; i <= n; ++i)
            if ((in[i] + out[i]) % 2) { printf("NO\n"); return 0; }
    } else {
        for (int i = 1; i <= n; ++i)
            if (in[i] != out[i]) { printf("NO\n"); return 0; }
    }

    /* ---------- 跑欧拉回路 ---------- */
    for (int i = 1; i <= n; ++i)
        if (head[i]) { dfs(i); break; }   // 从第一个有边点出发

    if ((int)ans.size() != m) { printf("NO\n"); return 0; }

    /* ---------- 输出 ---------- */
    printf("YES\n");
    for (int i = m - 1; i >= 0; --i)      // 递归序要逆序
        printf("%d ", ans[i]);
    return 0;
}

//以下优化的代码可以完全通过
// #include <cctype>
// #include <cstdio>
// namespace io {
// using namespace std;
// #define fastcall __attribute__((optimize("-O3")))
// #define IL __inline__ __attribute__((always_inline))
// struct istream {
// #define M (1 << 25)
//     int f;
//     char buf[M], *ch = buf - 1;
//     fastcall IL istream() {
//         fread(buf, 1, M, stdin);
//     }
//     fastcall IL istream &operator>>(int &x) {
//         f = 1;
 
//         while (!isdigit(*++ch))
//             if (*ch == '-')
//                 f = -1;
 
//         for (x = *ch & 15; isdigit(*++ch);)
//             x = x * 10 + (*ch & 15);
 
//         x *= f;
//         return *this;
//     }
//     fastcall IL istream &operator>>(long long &x) {
//         f = 1;
 
//         while (!isdigit(*++ch))
//             if (*ch == '-')
//                 f = -1;
 
//         for (x = *ch & 15; isdigit(*++ch);)
//             x = x * 10 + (*ch & 15);
 
//         x *= f;
//         return *this;
//     }
//     fastcall IL istream &operator>>(char &c) {
//         c = *++ch;
//         return *this;
//     }
// #undef M
// } cin;
// struct ostream {
// #define M (1 << 23)
//     char buf[M], *ch = buf - 1;
// #define endl (char)10
//     fastcall IL ostream &operator<<(int x) {
//         if (!x) {
//             *++ch = '0';
//             return *this;
//         }
 
//         if (x < 0) {
//             x = -x;
//             *++ch = '-';
//         }
 
//         static int S[20], *top;
//         top = S;
 
//         while (x) {
//             *++top = x % 10 ^ 48;
//             x /= 10;
//         }
 
//         for (; top != S; --top)
//             *++ch = *top;
 
//         return *this;
//     }
//     fastcall IL ostream &operator<<(long long x) {
//         if (!x) {
//             *++ch = '0';
//             return *this;
//         }
 
//         if (x < 0) {
//             x = -x;
//             *++ch = '-';
//         }
 
//         static int S[20], *top;
//         top = S;
 
//         while (x) {
//             *++top = x % 10 ^ 48;
//             x /= 10;
//         }
 
//         for (; top != S; --top)
//             *++ch = *top;
 
//         return *this;
//     }
//     fastcall IL ostream &operator<<(const char &x) {
//         *++ch = x;
//         return *this;
//     }
//     fastcall IL ~ostream() {
//         fwrite(buf, 1, ch - buf + 1, stdout);
//     }
// #undef M
// } cout;
// }  // namespace io
// using namespace io;
 
// #include <cstring>
// #include <queue>
// namespace eulercircuit {
// using namespace std;
// #define fastcall __attribute__((optimize("-O3")))
// #define IL __inline__ __attribute__((always_inline))
// template <int maxn>
// class EulerCircuit {
// public:
//     EulerCircuit(void) {
//         init();
//     }
//     fastcall IL void init(const int &n = 0, const bool &f = false) {
//         this->n = n;
//         directed = f;
//         memset(G, 0, sizeof(G));
//         memset(head, 0, sizeof(head));
//         cnt = 0;
//         return;
//     }
//     fastcall IL void AddEdge(const int &u, const int &v) {
//         G[++cnt].to = v;
//         G[cnt].nxt = head[u];
//         head[u] = cnt;
//         deg[0][u]++, deg[1][v]++;
//         f[u] = f[v] = true;
//         return;
//     }
//     int ans[maxn], c;
//     fastcall IL bool eulercircuit(void) {
//         if (directed) {
//             for (int i = 1; i <= n; i++)
//                 if (deg[0][i] != deg[1][i])
//                     return false;
//         } else {
//             for (int i = 1; i <= n; i++)
//                 if ((deg[0][i] & 1) || (deg[1][i] & 1))
//                     return false;
//         }
 
//         tot = c = 0;
 
//         for (int i = 1; i <= n; i++)
//             if (f[i]) {
//                 stack[++tot] = i;
//                 break;
//             }
 
//         bool flag;
//         int v = !directed, val = 0;
 
//         while (tot) {
//             flag = false;
 
//             for (int i = head[stack[tot]]; i; i = G[i].nxt)
//                 if (!vis[((i - 1) >> v) + 1]) {
//                     val++;
//                     head[stack[tot]] = G[i].nxt;
//                     flag = true;
//                     vis[((i - 1) >> v) + 1] = 1;
//                     stack[++tot] = G[i].to;
//                     tmp[tot] = i;
 
//                     if (v) {
//                         tmp[tot] = ((i - 1) >> 1) + 1;
 
//                         if (!(i & 1))
//                             tmp[tot] = 1 + ~tmp[tot];
//                     }
 
//                     break;
//                 }
 
//             if (!flag) {
//                 if (tot != 1)
//                     ans[++c] = tmp[tot];
 
//                 tot--;
//             }
//         }
 
//         for (int p = 1; (p << 1) <= c; p++)
//             ans[p] ^= ans[c - p + 1] ^= ans[p] ^= ans[c - p + 1];
 
//         return val == cnt >> v;
//     }
//     struct edge {
//         int to, nxt;
//     };
//     edge G[maxn];
//     int head[maxn], cnt;
//     bool directed;
//     int n;
 
// private:
//     bool vis[maxn], f[maxn];
//     int stack[maxn], tot;
//     int deg[2][maxn];
//     int tmp[maxn];
// };
// }  // namespace eulercircuit
// using namespace eulercircuit;
 
// EulerCircuit<400010> s;
 
// int main() {
//     int t, n, m;
//     cin >> t >> n >> m;
 
//     if (!m) {
//         cout << 'Y' << 'E' << 'S' << endl;
//         return 0;
//     }
 
//     s.init(n, !(t & 1));
//     int u, v;
 
//     while (m--) {
//         cin >> u >> v;
//         s.AddEdge(u, v);
 
//         if (t & 1)
//             s.AddEdge(v, u);
//     }
 
//     if (s.eulercircuit()) {
//         cout << 'Y' << 'E' << 'S' << endl;
 
//         for (int i = 1; i < s.c; i++)
//             cout << s.ans[i] << ' ';
 
//         cout << s.ans[s.c] << endl;
//     } else
//         cout << 'N' << 'O' << endl;
 
//     return 0;
// }