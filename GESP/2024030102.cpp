//4042：【GESP2403一级】找因数
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    //枚举1到n之间的所有数，判断是否是n的因数
    for (int i = 1; i <= n; ++i) {
        //如果i是n的因数，输出i
        if (n % i == 0) {
            cout << i << '\n';
        }
    }
    return 0;
}
