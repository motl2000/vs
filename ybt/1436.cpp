//1436：数列分段II
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a;

// 判断能否将数组分成 <= m 段，每段和 <= limit
bool check(long long limit) {
    long long cur = 0;
    int cnt = 1;              // 至少一段
    for (int x : a) {
        if (cur + x > limit) { // 必须新开一段
            ++cnt;
            cur = x;
            if (cnt > m || x > limit) return false;
        } else {
            cur += x;
        }
    }
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    long long left = 0, right = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        left = max(left, (long long)a[i]);
        right += a[i];
    }

    // 二分答案
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << '\n';
    return 0;
}
