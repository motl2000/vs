//4007：【GESP2306二级】找素数
//埃氏筛
#include <iostream>
using namespace std;

int main() {
    const int N = 1000;
    bool isPrime[N];
    // 初始化全部视为素数
    for (int i = 0; i < N; ++i) 
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;    //0 和 1 不是素数

    // 埃氏筛
    for (int i = 2; i * i < N; ++i)
        if (isPrime[i])//如果 i 是素数
            for (int j = i * i; j < N; j += i)//筛掉 i 的倍数
                isPrime[j] = false;

    int A, B;
    cin >> A >> B;
    int cnt = 0;
    for (int i = A; i <= B; ++i)
        if (isPrime[i]) ++cnt;

    cout << cnt << endl;
    return 0;
}
