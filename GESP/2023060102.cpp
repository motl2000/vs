//4006：【GESP2306一级】累计相加
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0;    // 累加和
    int cur = 0;    // 当前括号内的和
    // 1 到 n 的情况
    for (int i = 1; i <= n; ++i) {
        // 当前括号内的和
        cur += i;        
        // 累加到总和中
        res += cur;      
    }

    cout << res << endl;
    return 0;
}
