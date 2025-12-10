//4044：【GESP2403二级】小杨的日字矩阵
#include <iostream>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;          // 读入奇数 N
    int mid = N / 2;                    // 中间行下标

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j == 0 || j == N - 1)
                cout << '|';
            else if (i == 0 || i == N - 1 || i == mid)
                cout << '-';
            else
                cout << 'x';
        }
        cout <<endl;
    }
    return 0;
}
