#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        
        // 检查 (a[i] - b[i]) 的奇偶性是否一致
        int diff = a[0] - b[0];
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (diff % 2 != 0) {
                ok = false;
                break;
            }
        }
        
        cout << (ok ? "Yes" : "No") << '\n';
    }
}

int main() {
    solve();
    return 0;
}

