//1987：【19CSPS提高组】括号树
//DFS递归版，不能过17到20，栈的深度过大，洛谷上可以全过，一本通不行
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 
const int MAXN = 5e5 + 10; // 节点数上限
vector<int> tree[MAXN]; // 邻接表存树
char s[MAXN]; // 括号序列
int fa[MAXN]; // 父节点数组
long long r[MAXN], k[MAXN]; // r[i]表示i节点匹配的左括号组成的子串作为整体后的连续的合法子串数，k[i]表示根节点到i节点的合法子串数
stack<int> stk; // 存储未匹配左括号
 
void dfs(int u) { // 递归遍历节点u
    int t = 0; // 记录匹配的右括号
    if (s[u] == '(') { // 左括号入栈
        stk.push(u);
    } else if (!stk.empty()) { // 匹配右括号
        t = stk.top(); // 获取栈顶，即匹配的左括号
        stk.pop(); // 弹出
        r[u] = r[fa[t]] + 1; // 当前)匹配上后，就是在fa[t]合法子串数+1，因为如果当前)不能匹配，fa[t]后的到u的子串就不可能是一个合法的（虽然其中可能含有合法的子子串）
    }
    
    k[u] = k[fa[u]] + r[u]; // 累加子树深度和
    
    for (int v : tree[u]) { // 遍历子节点
        dfs(v);
    }
    //回溯，恢复
    if (s[u] == '(') { // 如果当前节点是左括号，回溯时把自己从栈中弹出
        if (!stk.empty() && stk.top() == u) {
            stk.pop();
        }
    } else if (t!= 0) { // 如果当前节点是右括号，回溯时把匹配的左括号压回栈中
        stk.push(t);
    }
}
 
int main() {
    int n;
    cin >> n; // 读入节点数
    cin >> (s + 1); // 读入括号序列（从s[1]开始）
    
    for (int i = 2; i <= n; ++i) { // 建立树边（从2开始）
        cin >> fa[i];
        tree[fa[i]].push_back(i);
    }
    
    dfs(1); // 从根节点开始DFS
    
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans ^= (i * k[i]); // 异或乘积
    }
    
    cout << ans << endl;
    return 0;
}

//DFS非递归版，可以在一本通上全部过
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 5e5 + 10;

// int n, fa[MAXN], top, stk[MAXN], dp[MAXN];
// long long sum[MAXN];
// char s[MAXN];
// vector<int> G[MAXN];

// int dfsStk[MAXN], dfsTop, ptr[MAXN];
// int undoTop, undoStk[MAXN];  // 只记录“弹出”的左括号，回溯时压回

// void dfs() {
//     dfsTop = 1;
//     dfsStk[1] = 1;
//     while (dfsTop) {
//         int u = dfsStk[dfsTop];
//         if (ptr[u] == 0) {  // 首次
//             if (s[u] == '(') {
//                 stk[++top] = u;
//             } else if (top) {
//                 int l = stk[top--];
//                 dp[u] = dp[fa[l]] + 1;
//                 undoStk[++undoTop] = l;  // 记录要恢复的左括号
//             }
//             sum[u] = sum[fa[u]] + dp[u];
//             ptr[u] = 1;
//         }
//         if (ptr[u] - 1 < (int)G[u].size()) {
//             int v = G[u][ptr[u] - 1];
//             dfsStk[++dfsTop] = v;
//             ptr[u]++;
//         } else {  // 回溯
//             if (s[u] == '(' && top && stk[top] == u) --top;
//             else if (dp[u]) stk[++top] = undoStk[undoTop--];  // 恢复
//             dfsTop--;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n >> (s + 1);
//     for (int i = 2; i <= n; ++i) {
//         cin >> fa[i];
//         G[fa[i]].push_back(i);
//     }
//     dp[0] = 0;
//     dfs();
//     long long ans = 0;
//     for (int i = 1; i <= n; ++i) ans ^= 1LL * i * sum[i];
//     cout << ans << '\n';
//     return 0;
// }

//动态规划版，可以全部过
#include <cstdio>
#define int long long
const int maxm=5e5+100;
int fa[maxm];
int k[maxm],last[maxm],r[maxm];
int n;
char s[maxm];
signed main()
{
	int ans=0;
	scanf("%lld\n",&n);
	for(int i=1;i<=n;i++) 
        s[i]=getchar();
	for(int i=2,u;i<=n;i++)
	{
		scanf("%lld",&u);
		fa[i]=u;
	}
	for(int i=1;i<=n;i++)
	{
		int fat=fa[i];                       //fat是i的父节点
		k[i]=k[fat];                         //k[i]是i的合法子串数，初始化为父节点的合法子串数
        last[i]=last[fat];                   //last[i]是i的最近的左括号，初始化为父节点的最近的左括号
		if(s[i]=='(') 
            last[i]=i;                       //如果i是左括号，则i是最近的左括号
		else if(s[i]==')'&&last[i])          //如果i是右括号，且i的最近的左括号不为空，则i的合法子串数+1，last[i]的最近的左括号变为i
		{   
		    r[i]=r[fa[last[i]]]+1;           //r[i]是i的最近的左括号的合法子串数，初始化为父节点的最近的左括号的合法子串数+1
            last[i]=last[fa[last[i]]];       //last[i]的最近的左括号变为父节点的最近的左括号，相当于消掉了和i匹配的左括号
            k[i]+=r[i];                      //k[i]加上i的最近的左括号的合法子串数
		}
		//printf("%d %d %d\n",dp[i],last[i],r[i]);
		ans^=(i*k[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
