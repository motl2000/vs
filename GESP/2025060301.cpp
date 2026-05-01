//4125：【GESP2506三级】奇偶校验
#include <cstdio>
using namespace std;
int n, v;  // n: 数据个数, v: 统计所有数字二进制中1的总个数
int main() {
    scanf("%d", &n);  
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);  
        // 统计当前数字c的二进制中1的个数
        while (c) {
            v += c & 1;   // c & 1: 取c的最低位，如果是1则加到v中
            c >>= 1;      // c右移一位，继续检查下一位
        }
    }
    printf("%d %d\n", v, v & 1);
    return 0;
}
