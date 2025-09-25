//1434：【例题2】Best Cow Fences
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 1e-6;   // 精度控制

int n, L;
vector<int> A;

// 判断是否存在长度 ≥ L 的区间，其平均数 ≥ mid
bool check(double mid) {
    vector<double> S(n + 1);//S[i] 表示前 i 个元素与 mid 的差值之和
    S[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        S[i] = S[i - 1] + (A[i - 1] - mid);   // 注意数组下标
    }
    double min_prefix = 0.0;   // S[0]，min_prefix 用于快速判断是否存在满足条件的子数组
    for (int i = L; i <= n; ++i) {
        if (S[i] - min_prefix >= 0) return true;
        min_prefix = min(min_prefix, S[i - L + 1]);   // 更新可转移的前缀
    }
    return false;
}

int main() {
        cin >> n >> L;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    double left = *min_element(A.begin(), A.end());
    double right = *max_element(A.begin(), A.end());
    double ans = left;

    // 二分枚举， 50 次足够， 保证精度
    for (int iter = 0; iter < 50; ++iter) {
        double mid = (left + right) / 2.0;
        if (check(mid)) {
            ans = mid;
            left = mid;
        } else {
            right = mid;
        }
    }

    // 输出 1000 倍整数
    cout << static_cast<long long>(ans * 1000 + EPS) << '\n';
    return 0;
}
