//数字选取
//线性筛，oula
#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1e5 + 5;
 int n, p[N], cnt;      // p[1..cnt] 存放所有质数
 bool np[N];            // 标记数组，np[i] 表示 i 是否是质数，0 表示是质数，1 表示是合数
 int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (!np[i])             // 如果 i 是质数
            p[++cnt] = i;       // 存入质数数组
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            np[i * p[j]] = 1;   // 标记 i * p[j] 为合数
            if (i % p[j] == 0) 
                break;
        }
    }
    printf("%d\n", 1 + cnt);
    return 0;
 }

 