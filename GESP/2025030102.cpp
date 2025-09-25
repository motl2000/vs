//4106：【GESP2503一级】四舍五入
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        //将个位数四舍五入到整十
        int y = (x + 5) / 10 * 10;   // 四舍五入到整十
        cout << y << '\n';
    }
    return 0;
}
