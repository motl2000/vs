//4043：【GESP2403二级】乘法问题
#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    const long long LIMIT = 1000000;
    long long product = 1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        product *= x;
        if (product > LIMIT) {          // 提前溢出判断
            cout << ">1000000\n";
            return 0;
        }
    }

    cout << product << '\n';
    return 0;
}
