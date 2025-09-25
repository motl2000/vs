//4026：【GESP2312一级】小杨报数
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        //如果i不是M的倍数，输出i
        if (i % M != 0) {
            cout << i << '\n';
        }
    }
    return 0;
}
