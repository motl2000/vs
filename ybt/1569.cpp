//1569：【 例 1】石子合并
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200; // 最多 100 堆，复制后最多 200

int n;
int a[MAXN];
int sum[MAXN]; // 前缀和
int dp_min[MAXN][MAXN]; // 最小得分
int dp_max[MAXN][MAXN]; // 最大得分

// 计算区间 [l, r] 的和
int get_sum(int l, int r) {
    return sum[r] - sum[l - 1];
}

// 区间 DP 求最小和最大得分
void solve() {
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            dp_min[i][j] = 0x3f3f3f3f;
            dp_max[i][j] = 0;

            for (int k = i; k < j; ++k) {
                int cost = get_sum(i, j); // 合并 i~j 的代价
                int left_cost = dp_min[i][k];
                int right_cost = dp_min[k+1][j];
                dp_min[i][j] = min(dp_min[i][j], left_cost + right_cost + cost);

                left_cost = dp_max[i][k];
                right_cost = dp_max[k+1][j];
                dp_max[i][j] = max(dp_max[i][j], left_cost + right_cost + cost);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 复制数组，处理环形，由于题目要求处理环形数组，所以将数组复制一份
    for (int i = 1; i <= 2 * n; ++i) {
        if (i <= n) {
            a[i] = a[i];
        } else {
            a[i] = a[i - n];
        }
    }

    // 构建前缀和
    sum[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        sum[i] = sum[i-1] + a[i];
    }

    // 初始化 DP 数组
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            dp_min[i][j] = 0x3f3f3f3f;
            dp_max[i][j] = 0;
        }
    }

    // 对每个长度为 n 的区间进行 DP
    int min_total = 0x3f3f3f3f;
    int max_total = 0;

    for (int start = 1; start <= n; ++start) {
        int end = start + n - 1;
        // 初始化单个点
        for (int i = start; i <= end; ++i) {
            dp_min[i][i] = 0;
            dp_max[i][i] = 0;
        }
        // 执行 DP
        for (int len = 2; len <= n; ++len) {        // 枚举区间长度
            for (int i = start; i <= end - len + 1; ++i) {// 枚举区间起点
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {       // 枚举分割点
                    int cost = get_sum(i, j);       // 合并 i~j 的代价
                    int left_cost = dp_min[i][k];   // 左边区间最小得分
                    int right_cost = dp_min[k+1][j];// 右边区间最小得分
                    dp_min[i][j] = min(dp_min[i][j], left_cost + right_cost + cost);

                    left_cost = dp_max[i][k];       // 左边区间最大得分
                    right_cost = dp_max[k+1][j];    // 右边区间最大得分
                    dp_max[i][j] = max(dp_max[i][j], left_cost + right_cost + cost);
                }
            }
        }
        min_total = min(min_total, dp_min[start][end]);
        max_total = max(max_total, dp_max[start][end]);
    }

    cout << min_total << endl;
    cout << max_total << endl;

    return 0;
}