// 2025年3月六级考试
// 树上漫步
//思路：对于每个节点，可以停留在自己和每个与自己相隔偶数步的节点上，所以一共只有两个情况
//可以用深搜把这两类节点标记出来，并分别计数。
//官方答案用了“链式前向星”，这不一定容易理解
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// const int N = 2e5 + 5;
// const int E = N << 1;
// int n;
// int h[N], to[E], nx[E], et;         //et:树边数量，to[i]:
// int cnt[N], bel[N];
// void ae(int u, int v)
// {
//     et++;                           //当前边的编号
//     to[et] = v;                     //边指向v
//     nx[et] = h[u];                  //原来h[u]指向的边是u的第一个子树边，现在et接上这上一个“第一个子树边”
//     h[u] = et;                      //u的第一个子树边是et，相当于栈
// }
// void dfs(int u, int c, int f)               //u:当前节点，c:当前标记，f:父节点
// {
//     bel[u] = c;                             //给u打上标记，一共就两种标记，不是1就是0
//     cnt[c]++;                               //给当前标记计数
//     for (int i = h[u]; i; i = nx[i])        //遍历u的子树(边)
//         if (to[i] != f)                     //如果to[i]不是u的父节点，避免回溯到父节点
//             dfs(to[i], c ^ 1, u);           //u的子树是c的子树，u的子树根是u
// }
// int main()
// {
//     scanf("%d", &n);
//     for (int i = 1; i < n; i++)
//     {
//         int u, v;
//         scanf("%d%d", &u, &v);
//         ae(u, v);
//         ae(v, u);
//     }
//     dfs(1, 0, 0);
//     for (int i = 1; i <= n; i++)
//         printf("%d%c", cnt[bel[i]], " \n"[i == n]);//就喜欢玩花样，意思是如果不是最后一个就输出数字和空格，如果是最后一个就输出数字和换行
//     return 0;
// }

// 2025年3月六级考试 - 树上漫步（vector邻接表版本）
#include <cstdio>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];  // 邻接表
int cnt[2], bel[N];  // cnt[0]表示停在0的次数，cnt[1]表示停在1的次数,bel[i]表示节点i的标记0或1

void dfs(int u, int c, int f) {
    bel[u] = c;
    cnt[c]++;
    for (int v : adj[u]) {        // 直接遍历邻接节点
        if (v != f) {             // 排除父节点
            dfs(v, c ^ 1, u);     // 递归子节点
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 建树（更直观的方式）
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);  // 添加双向边
        adj[v].push_back(u);
    }
    
    dfs(1, 0, 0);
    
    // 输出结果（保持原有逻辑）
    for (int i = 1; i <= n; i++) {
        printf("%d%c", cnt[bel[i]], " \n"[i == n]);
    }
    return 0;
}
