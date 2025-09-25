//4090：【GESP2412一级】奇数和偶数
#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    int odd = 0, even = 0;  //odd为奇数个数，even为偶数个数
    // 读入n个整数，统计奇数和偶数的个数
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        // 判断x是否为奇数或偶数，并分别计数
        if (x & 1) 
            ++odd;
        else       
            ++even;
    }
    cout << odd << ' ' << even << '\n';
    return 0;
}
