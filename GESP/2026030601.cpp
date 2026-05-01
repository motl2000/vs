//GESP2026年3月 6级
//DP + 前缀最大值优化
//详解见白板
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;  // 数组最大范围：10^5 + 5

int n;                  // 数组长度
int a[N], b[N];         // a: 价值数组, b: 间隔数组
long long f[N], ans;    // f[i]: 来到位置i时的最大准备值（前缀最大值,前i-1个位置的最优结果）
                        // ans: 最终答案（所有选法中最大的和）

int main() {
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    
    // 动态规划主过程
    // f[i] 初始为0，表示前i个位置不选任何数的价值为0
    for (int i = 1; i <= n; i++) {
        // 【关键1】更新答案：考虑以位置i结尾的情况
        ans = max(ans, f[i] + a[i]);
        
        // 【关键2】跳跃转移：如果选了位置i，下一个能选的位置是i+b[i]
        // 将当前最优值传递到i+b[i]位置
        if (i + b[i] <= n)
            f[i + b[i]] = max(f[i + b[i]], f[i] + a[i]);
        
        // 【关键3】前缀最大值传递：即使i位置不能跳，即前i+1个位置的最优值不会小于前i个
        // 这是本算法的核心：维护前缀最大值，支持任意位置的转移
        f[i + 1] = max(f[i + 1], f[i]);
        printf("%lld\n", f[i]);
    }
    
    printf("%lld\n", ans);
    return 0;
}
