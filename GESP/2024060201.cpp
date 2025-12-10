//4059：【GESP2406二级】平方之和
// #include <bits/stdc++.h>
// using namespace std;

// const int MAXV = 1e6 + 5;
// bool ok[MAXV];

// int main() {
//     // 预处理
//     int lim = sqrt(MAXV) + 2;
//     for (int x = 1; x <= lim; ++x) {
//         int x2 = x * x;
//         if (x2 >= MAXV) break;
//         for (int y = 1; y <= lim; ++y) {
//             int s = x2 + y * y;
//             if (s >= MAXV) break;
//             ok[s] = true;
//         }
//     }

//     int n;
//     if (!(cin >> n)) return 0;
//     while (n--) {
//         int a;
//         cin >> a;
//         cout << (ok[a] ? "Yes\n" : "No\n");
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        bool found = false;     
        for (int x = 1; x * x <= a; ++x) {
            int y = sqrt(a - x * x);
            if (y>0 && x * x + y * y == a) {
                cout << "Yes\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No\n";
    }
    return 0;
}