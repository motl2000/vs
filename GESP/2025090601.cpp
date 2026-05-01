//GESP2025年9月6级划分字符串
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 5;  // 最大字符串长度
int n;                  // 字符串实际长度
char s[N];              // 存储字符串（1-indexed，s[1]到s[n]）
int a[N];               // 价值数组，a[i]表示长度为i的子串的价值
long long f[N];         // DP数组，f[i]表示前i个字符能得到的最大价值

int main() {
    // 读取输入
    scanf("%d", &n);
    scanf("%s", s + 1);  // 从下标1开始存储字符串
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    // 动态规划核心过程
    // 遍历每个位置i，计算前i个字符的最大价值
    for (int i = 1; i <= n; i++) {
        int mask = 0;  // 位掩码，记录当前子串中出现的字母
                       // 第k位为1表示字母('a'+k)在当前子串中出现过
        
        // 从位置i向前遍历j，尝试以s[j..i]作为最后一个子串
        for (int j = i; j; j--) {
            int cur = 1 << (s[j] - 'a');  // 当前字符对应的比特位
            
            // 如果当前字符已在子串中出现过，说明出现重复
            // 子串s[j..i]不满足"每个字母至多出现一次"的条件，跳出循环
            if (mask & cur) break;
            
            // 将当前字符加入掩码，表示该字符已在子串中出现
            mask |= cur;
            
            // 状态转移：尝试用f[j-1] + a[i-j+1]更新f[i]
            // f[j-1]: 前j-1个字符的最大价值
            // a[i-j+1]: 子串s[j..i]的长度为i-j+1，其价值为a[i-j+1]
            f[i] = max(f[i], f[j - 1] + a[i - j + 1]);
        }
    }
    
    // 输出结果：前n个字符的最大价值
    printf("%lld\n", f[n]);
    return 0;
}
