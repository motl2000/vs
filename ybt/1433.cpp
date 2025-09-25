//1433：【例题1】愤怒的牛
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<long long> a;

// 判断能否在至少相距 d 的条件下放进 C 头牛
bool canPlace(long long d) {
    int cnt = 1;          // 第一头牛放在最左隔间
    long long last = a[0];
    for (int i = 1; i < N; ++i) {
        if (a[i] - last >= d) {
            ++cnt;
            last = a[i];
            if (cnt >= C) return true;
        }
    }
    return cnt >= C;
}

int main() {
    // 读入
    cin >> N >> C;
    a.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // 排序
    sort(a.begin(), a.end());

    // 二分答案
    long long left = 0;
    long long right = a.back() - a.front();
    long long ans = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canPlace(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
