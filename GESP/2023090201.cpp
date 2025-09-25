//4015：【GESP2309二级】小杨的X字矩阵
#include <iostream>
using namespace std;
int main() {
    int N;
    cin>>N;
    int mid = N / 2;                         // 中心行/列下标
    for (int i = 0; i < N; ++i) {            // 逐行输出
        for (int j = 0; j < N; ++j) {
            // 两条对角线：主对角线 i==j 或副对角线 i+j==N-1
            char c;
            c = (i == j || i + j == N - 1) ? '+' : '-';
            cout << c;
        }
        cout << endl;                   // 行末换行，不额外输出空格
    }
    return 0;
}
