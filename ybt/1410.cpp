//最大质因子序列
//任意输入两个正整数m,n(1<m<n≤5000)，依次输出m到n之间每个数的最大质因子(包括m和n；如果某个数本身是质数，则输出这个数自身)。
#include <iostream>
#include <cmath>
using namespace std;
int m, n;

// Function to find the maximum prime factor of a given number
int maxPrimeFactor(int num) {
    int maxFactor = 0;
    for (int j = 2; j <= sqrt(num); j++) {
        if (num % j == 0) {
            maxFactor = j;
            while (num % j == 0) {
                num /= j;
            }
        }
    }
    if (num > maxFactor) {
        maxFactor = num;
    }
    return maxFactor;
}

int main() {
    cin >> m >> n;
    
    for (int i = m; i <= n; i++) {
        //输出一行，每个整数的最大质因子，以逗号间隔。
        cout << maxPrimeFactor(i);
        if (i < n) {
            cout << ",";
        }
    }
    return 0;
}