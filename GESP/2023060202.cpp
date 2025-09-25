//4008：【GESP2306二级】自幂数判断
#include <iostream>
using namespace std;

/* 快速幂：base^pow */
int pow_int(int base, int pow) {
    int res = 1;
    //自乘 pow 次
    while (pow--) res *= base;
    return res;
}

/* 判断 x 是否为自幂数 */
bool isArmstrong(int x) {
    if (x <= 0) return false;
    int tmp = x, digits = 0;
    // 求位数 digits
    while (tmp) { 
        ++digits; 
        tmp /= 10; 
    }   
    tmp = x;
    int sum = 0;
    //每位的digits次方相加求和
    while (tmp) {
        int d = tmp % 10;
        sum += pow_int(d, digits);
        tmp /= 10;
    }
    return sum == x;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int x;
        cin >> x;
        cout << (isArmstrong(x) ? 'T' : 'F') << '\n';
    }
    return 0;
}
