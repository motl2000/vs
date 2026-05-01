// 谐音替换（replace）
#include <bits/stdc++.h>
typedef long long ll;
const int N = 5e6 + 10, V = N + 13;
std::vector<int> ch[N], e[N];   // 字典树的儿子节点和后继节点
int fail[N], cnt[N], n, q, tot, fa[N], fa_w[N], dep[N];// 失败指针,子节点数量,节点数量,字符串数量,节点深度
int id(char x, char y)  //将两个字符编码成一个唯一的整数ID，用于表示"谐音替换对"
{
    return (x - 'a') * 26 + (y - 'a');
}
int head[V], nex[N], fir[N], sec[N], val[N], top;// 哈希表,链地址法
int hash(int x, int y)  //将两个整数编码成一个唯一的哈希值
{
    return (x * 400 % V + y + 1145) % V;
}
/**
 * @brief 检查从节点x出发，标签为y的边是否存在
 * 
 * @param x 起始节点
 * @param y 边的标签
 * @return int 如果边存在则返回边的值，否则返回0
 */
int find(int x, int y)  //检查从节点 x 出发，标签为 y 的边是否存在
{
    int H = hash(x, y) % V;
    for (int i = head[H]; i; i = nex[i])
        if (fir[i] == x && sec[i] == y)
            return val[i];
    return 0;
}
void modify(int x, int y, int z)    //插入"谐音替换对"
{
    int H = hash(x, y) % V;
    nex[++top] = head[H];
    head[H] = top, val[top] = z, fir[top] = x, sec[top] = y;
}
char s1[N], s2[N];      // 用于存储输入的字符串对
std::queue<int> Q;      // 用于BFS遍历
bool ok1[N], ok2[N];    // 标记数组,用于判断是否是"谐音替换对"
void dfs(int u)         // 用于统计每个节点对应的子树中"谐音替换对"的数量
{
    for (int v : e[u]){
        cnt[v] += cnt[u];
        dfs(v);
    }
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %s %s ", s1 + 1, s2 + 1);   // 读入两个字符串
        //构建字典树
        int len = strlen(s1 + 1);           // 两个字符串是等长的
        int u = 0;    
        for (int i = 1; i <= len; i++)
        {
            int w = id(s1[i], s2[i]);       // 将两个字符编码成一个唯一的整数ID，用于表示"谐音替换对"
            if (!find(u, w))
            {
                modify(u, w, ++tot);
                fa[tot] = u;
                fa_w[tot] = w;
                dep[tot] = dep[u] + 1;
                ch[u].push_back(tot);
                // printf ("%d %d %d\n", u, tot, w);
            }
            u = find(u, w);
        }
        cnt[u]++;
    }
    // 计算fail数组
    for (int v : ch[0])     
        Q.push(v);
    while (Q.size())
    {
        int u = Q.front();
        Q.pop();
        int x = fail[fa[u]], w = fa_w[u], y = find(x, w);
        while (x && !y)
            x = fail[x], y = find(x, w);
        if (y)
            fail[u] = y;
        if (!fa[u])
            fail[u] = 0;
        for (int v : ch[u])
            Q.push(v);
    }
    // for (int i = 0; i <= tot; i++) printf ("%d %d\n", i, fail[i]);
    // printf ("\n");
    // 构建后继节点数组
    for (int i = 1; i <= tot; i++)
        e[fail[i]].push_back(i);  

    // 计算每个节点的子节点数量
    dfs(0);
    // for (int i = 1; i <= tot; i++) printf ("%d ", cnt[i]);
    // printf ("\n");
    // 处理询问
    for (int i = 1; i <= q; i++)
    {
        scanf(" %s %s ", s1 + 1, s2 + 1);
        ll ans = 0;
        int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
        if (len1 != len2)   // 排除两个字符串的长度不相等
        {
            printf("0\n");
            continue;
        }
        int len = len1;
        // 标记数组,用于判断是否是"谐音替换对"
        ok1[0] = ok2[len + 1] = 1;
        for (int i = 1; i <= len; i++)
            ok1[i] = ok1[i - 1] && (s1[i] == s2[i]);    // 存储前缀匹配信息,判断s1[1..i]和s2[1..i]是否相同
        for (int i = len; i >= 1; i--)
            ok2[i] = ok2[i + 1] && (s1[i] == s2[i]);    // 存储后缀匹配信息,判断s1[i..len]和s2[i..len]是否相同
        for (int i = 1, u = 0, v = 0; i <= len; i++)
        {
            int w = id(s1[i], s2[i]);
            // u指针：正常AC自动机匹配, 匹配所有以当前位置结尾的模式
            while (!find(u, w) && u)        
                u = fail[u];
            if (find(u, w))             
                u = find(u, w);
            // v指针：匹配所有既以当前位置结尾，又满足前缀约束的模式
            while (!find(v, w) && v)
                v = fail[v];
            if (find(v, w))
                v = find(v, w);
            while (ok1[i - dep[v]] && v)    //dep[v] ：节点v在Trie树中的深度
                v = fail[v];
            if (ok2[i + 1])
                ans += (cnt[u] - cnt[v]);   //cnt[u] - cnt[v] ：计算在当前位置匹配的模式数量
        }
        printf("%lld\n", ans);
    }
    return 0;
}
