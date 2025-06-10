// 2025年3月八级考试
// 割裂
//本题知识点倍增法求解最近公共祖先(LCA)，树上差分
#include <bits/stdc++.h>
 using namespace std;
 const int N = 1e6+10;
 int n, k;
 vector<int> e[N];
 int f[N][25], dep[N], g[N], h[N];
 /**
  构建LCA跳跃表
  */
 void dfs(int u, int fa){       
    dep[u] = dep[fa] + 1;               //记录深度
    f[u][0] = fa;                       //记录父节点，f[u][i]表示节点u向上跳2^i层后的节点
    for(int i = 1; i <= 20; i++){       //记录LCA跳跃表
        f[u][i] = f[f[u][i - 1]][i - 1];//跳1层等于父节点跳0层，跳2层等于父节点跳1层，跳3层等于父节点跳2层，以此类推
    }
    for(auto v: e[u]){                  //遍历子节点
        if(v == fa) continue;
        dfs(v, u);
    }
 }
 /**
  * 使用倍增法求解最近公共祖先(LCA)。首先将两个节点调整到相同深度,
  * 然后从高到低按二进制位进行向上跳转,直到找到最近公共祖先。
  * dep[]存储节点深度,f[][]存储祖先节点信息。
  */
 int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);     //保证u的深度大于v的深度
    int t = dep[u] - dep[v];            //计算深度差
    //将u调整到与v相同深度,二进制跳跃法（Binary Lifting）
    for(int i = 0; i <= 20; i++){       //<=20是因为节点数<=10^6，2^20=1048576，足够覆盖
        if(t & (1 << i)) u = f[u][i];   //如t=5,二进制为101,则u先跳到f[u][0]父节点，然后父节点再跳f[u][2]，跳两层，等于一共跳了5层。
    }
    for(int i = 20; i >= 0; i--){       //u和v同深度后，一起向上寻找父节点，知道父节点相同
        if(f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    }
    if(u == v) return u;
    return f[u][0];                     
 }
 int ans;
 /**
  * 计算满足"不在任何好节点对路径上，但在坏节点对路径上"的边数
  */
 void dfs2(int u, int fa)
 {
     for (auto v : e[u])
     {
         if (v == fa)
             continue;
         dfs2(v, u);
         g[u] += g[v]; // 累计子节点的好标记
         h[u] += h[v]; // 累计子节点的坏标记
     }
     if (!g[u] && h[u])
     {          // 如果没有好标记但有坏标记
         ans++; // 计数增加
     }
 }
 void solve(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){     //构建树的邻接表
        int u, v;
        cin >> u >> v;              //输入所有节点对
        e[u].push_back(v);          //无向图，虽然是树，因为要求连通性，所以按一个没有环的图处理
        e[v].push_back(u);
    }
    dfs(1, 0);                      //构建LCA跳跃表
 /**
  * 利用树上差分
  * 在树结构中，要标记从节点 u 到 v 的路径上的所有节点，可以通过以下差分操作：
        在 u 和 v 处 +1（表示路径起点和终点）
        在它们的最近公共祖先 lc 处 -1（避免重复统计）
        在 lc 的父节点 f[lc][0] 处 -1（确保标记不向上扩散到其他分支）
    其核心思想是将路径操作分解为树节点的差分标记，通过 ​后序遍历（DFS/BFS）​​ 累加标记值，最终得到每个节点或边的统计结果。
  */    
    for(int i = 1; i <= k; i++){
        int u, v;
        cin >> u >> v;              //输入好节点对
        int lc = lca(u, v);         //计算好节点对的最近公共祖先
        g[u]++;                     //标记u到v的路径上的所有节点为好节点
        g[v]++;                     
        g[lc]--;                    
        g[f[lc][0]]--;              
    }
    int u, v;
    cin >> u >> v;                  //输入坏节点对
    int lc = lca(u, v);             //计算最近公共祖先
    h[u]++;                         //标记u到v的路径上的所有节点为坏节点
    h[v]++;                         
    h[lc]--;                        
    h[f[lc][0]]--;                  
    dfs2(1, 0);
    cout << ans << '\n';
 }
 int main(){
    solve();
 }        