//4003：【GESP2303二级】画三角形
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;               // 2 < n <= 40
    char ch = 'A';          // 当前要输出的字母

    for (int i = 1; i <= n; ++i) {        // 第 i 行输出 i 个字母
        for (int j = 0; j < i; ++j) {
            cout << ch;
            ++ch;
            if (ch > 'Z') ch = 'A';       // 超过 Z 回到 A
        }
        cout << endl;
    }
    return 0;
}
