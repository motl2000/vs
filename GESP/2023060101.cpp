//4005：【GESP2306一级】时间规划
#include <iostream>
using namespace std;

int main() {
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    //统一成分钟数后，后一时刻 - 前一时刻
    cout << (h2 * 60 + m2) - (h1 * 60 + m1) << endl;
    return 0;
}
