//4028：【GESP2312二级】小杨的 H 字矩阵
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int mid = N / 2;          // 中间行下标
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char c;
            if (j == 0 || j == N - 1)        // 左右两列
                c = '|';
            else if (i == mid)               // 中间行
                c = '-';
            else
                c = 'a';
            cout << c;
        }
        cout << endl;
    }
    return 0;
}
