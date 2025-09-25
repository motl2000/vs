//4004：【GESP2303二级】百鸡问题
#include <iostream>
using namespace std;

int main() {
    int a, y, z, n, m;
    cin >> a >> y >> z >> n >> m;

    int cnt = 0;
    // i 只公鸡，j 只母鸡，k 只小鸡
    for (int i = 0; i <= m; ++i) {               // 公鸡最多 m 只
        for (int j = 0; j <= m - i; ++j) {       // 母鸡最多 m - i 只
            int k = m - i - j;                   // 小鸡数量固定
            if (k < 0) continue;
            // 计算总价钱：公鸡*i + 母鸡*j + 小鸡*k/z
            // 要求总价钱恰好为 n 元，且 k 必须能被 z 整除
            if (k % z == 0 && a * i + y * j + k / z == n) {
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
