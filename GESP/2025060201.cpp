//4124：【GESP2506二级】幂和数
#include <iostream>
#include <cstring> // for memset (optional)
using namespace std;

const int MAX_N = 10000;
bool isPowerSum[MAX_N + 1]; // index from 0 to 10000

int main() {
    int l, r;
    cin >> l >> r;

    // 初始化数组为 false
    for (int i = 0; i <= MAX_N; ++i) {
        isPowerSum[i] = false;
    }

    // 枚举 x 和 y
    for (int x = 0; ; ++x) {
        long long two_x = 1LL << x;
        if (two_x > MAX_N) break; // 2^x a    lready > 10000, no need to continue

        for (int y = x; ; ++y) {
            long long two_y = 1LL << y;
            long long sum = two_x + two_y;
            if (sum > MAX_N) break;
            isPowerSum[(int)sum] = true;    //用isPowerSum记录的目的是避免有重复的幂和数
        }
    }

    // 统计 [l, r] 中的幂和数个数
    int count = 0;
    for (int i = l; i <= r; ++i) {
        if (isPowerSum[i]) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}