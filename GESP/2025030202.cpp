//4123：【GESP2506二级】数三角形
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;

    for (int a = 1; a <= n; ++a) {
        for (int b = a; b <= n; ++b) {  // a <= b，避免重复
            if ((a * b) % 2 == 0) {     // ab 是偶数 → 面积是整数
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

//高级算法
// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     int total = n * (n + 1) / 2;        // 所有a、b的组合数,b>=a
//     int odd = (n + 1) / 2;              // 奇数个数
//     int odd_pairs = odd * (odd + 1) / 2;// 奇数对数

//     cout << total - odd_pairs << endl;  // 总数 - 奇数对数 = 偶数对数

//     return 0;
// }