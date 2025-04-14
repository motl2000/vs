//2025年3月GESP 四级
//二阶矩阵
#include <bits/stdc++.h>
 using namespace std;
 const int N = 505;
 int n, m;
 int a[N][N];
 int ans;
 int main() {
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 500 && 1 <= m && m <= 500);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            assert(-100 <= a[i][j] && a[i][j] <= 100);
        }
    //遍历每个二阶矩阵，看是否满足条件
    for (int i = 1; i < n; i++)     
        for (int j = 1; j < m; j++)
            if (a[i][j] * a[i + 1][j + 1] == a[i + 1][j] * a[i][j + 1])
                ans++;
    printf("%d\n", ans);
    return 0;
 }