//1479：【例题1】Keywords Search
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 5e5 + 5;

int ans, cnt;                        //ans 表示匹配的单词数，cnt 表示 Trie 树节点数 
int nxt[N], ch[N][30], bo[N], que[N];//nxt[i] 表示节点 i 的 fail 指针，ch[i][j] 表示节点 i 的第 j 个子节点，bo[i] 表示节点 i 的单词出现次数，que[i] 表示队列第 i 个元素

/*---------- 1. 构建 Trie 树 ----------*/
//这个结构比较抽象，需要画图深刻理解
void make(char *s) {
    int u = 1, len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int c = s[i] - 'a';
        if (!ch[u][c]) {            // 如果不存在，则新建节点
            ch[u][c] = ++cnt;       // 注意 cnt 在main函数中初始化为 1
            memset(ch[cnt], 0, sizeof(ch[cnt]));
        }
        u = ch[u][c];               // 更新当前节点,u就是当前节点
    }
    bo[u]++;          // 统计单词出现次数（允许重复模式串）
}

/*---------- 2. BFS 构建 fail 指针 ----------*/
void bfs() {
    for (int i = 0; i < 26; ++i) ch[0][i] = 1;   // 0 号虚拟节点指向根 1
    que[1] = 1;
    nxt[1] = 0;                                  // 根节点的 fail 指针指向 0 号虚拟节点
    for (int q1 = 1, q2 = 1; q1 <= q2; ++q1) {   // q1表示队列头，q2表示队列尾
        int u = que[q1];
        for (int i = 0; i < 26; ++i) {
            if (!ch[u][i])                      // 如果不存在此字母，则指向 fail 指针
                ch[u][i] = ch[nxt[u]][i];
            else {                              // 如果存在该字母
                que[++q2] = ch[u][i];           // 加入队列
                int v = nxt[u];
                nxt[ch[u][i]] = ch[v][i];       // 当前节点的 fail 指针指向父节点的fail指针指向节点下的与本字母相同的结点
            }
        }
    }
}

/*---------- 3. 多模式串匹配 ----------*/
//书上的匹配机制有些复杂，多看看才能理解
void find(char *s) {
    int u = 1, len = strlen(s), c, k;
    for (int i = 0; i < len; ++i) {
        c = s[i] - 'a';
        k = ch[u][c];       // k 表示当前节点的编号
        // 如果 k 不为 0，则表示匹配到部分单词
        while (k > 1) {     
            ans += bo[k];   // bo[k]>0表示匹配到单词
            bo[k] = 0;      // 每个单词只算一次（去重）
            k = nxt[k];     // 沿着 fail 指针向前匹配，找到所有可以匹配的单词
        }
        u = ch[u][c];       // 移动到trie树的下一个节点
    }
}

/*---------- 4. 主函数 ----------*/
int main() {
    int t, n;
    char s[N << 1];
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        cnt = 1;                           // 根节点编号为 1
        memset(bo, 0, sizeof(bo));
        for (int i = 0; i < 26; ++i) ch[0][i] = 1, ch[1][i] = 0;

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {  // 读入 n 个模式串
            scanf("%s", s);
            make(s);                    // 构建 Trie 树
        }
        bfs();                          // 构建 fail 指针
        scanf("%s", s);
        find(s);                        // 多模式串匹配
        printf("%d\n", ans);
    }
    return 0;
}
