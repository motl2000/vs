//2025年3月五级考试
//平均分配

#include <bits/stdc++.h>
 using namespace std;
 const int N = 2e5 + 5;
 int n;
 long long b[N], c[N], d[N];
 long long ans;
 int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%lld", &b[i]);
    for (int i = 1; i <= 2 * n; i++)
        scanf("%lld", &c[i]);
    for (int i = 1; i <= 2 * n; i++) {
        ans += b[i];
        d[i] = c[i] - b[i];                 //求两个价格的差值
    }
    sort(d + 1, d + 2 * n + 1);                                     
    for (int i = n + 1; i <= 2 * n; i++)    //加上c-b的n个差值，注意这里是从n+1开始
        ans += d[i];
    printf("%lld\n", ans);
    return 0;
 }
