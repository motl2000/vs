//1570：【例 2】能量项链
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200; // n <= 100, 所以 2*n <= 200

int n;
int a[MAXN]; // 存储头标记，同时 a[i] 表示第 i 颗珠子的头标记
int dp[MAXN][MAXN]; // dp[i][j] 表示合并第 i 到 j 颗珠子的最大能量

// 计算合并 [i,j] 区间能释放的最大能量
void solve() {
    // 初始化：单个珠子不释放能量
    for (int i = 1; i <= 2 * n; ++i) {
        dp[i][i] = 0;
    }

    // 枚举区间长度
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= 2 * n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = 0;
            for (int k = i; k < j; ++k) {
                // 合并 [i,k] 和 [k+1,j]
                int energy = dp[i][k] + dp[k+1][j] + a[i] * a[k+1] * a[j+1];
                dp[i][j] = max(dp[i][j], energy);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 复制数组，处理环形结构
    for (int i = 1; i <= n; ++i) {
        a[i + n] = a[i];
    }

    // 初始化 dp 数组
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            dp[i][j] = 0;
        }
    }

    solve();

    // 在所有长度为 n 的区间中找最大值
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i][i+n-1]);
    }

    cout << ans << endl;

    return 0;
}