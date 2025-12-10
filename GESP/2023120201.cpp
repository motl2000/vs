//4027：【GESP2312二级】小杨做题
#include <iostream>
using namespace std;

int main() {
    int a, b, m, N;
    cin >> a >> b >> m >> N;

    long long total = a + b;   // 前两天总和
    int prev2 = a, prev1 = b;  // 分别表示“前两天”和“前一天”

    for (int day = 3; day <= N; ++day) {
        int today = prev2 + prev1;
        total += today;         // 先累加当天
        if (today >= m)         // 当天做完后，从明天起不再做题
            break; 
        prev2 = prev1;
        prev1 = today;
    }
    cout << total << endl;
    return 0;
}
