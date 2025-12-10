//4060：【GESP2406二级】计数
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x) {
            if (x % 10 == k) ++cnt;
            x /= 10;
        }
    }
    cout << cnt << '\n';
    return 0;
}
