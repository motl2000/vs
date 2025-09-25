#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1005;
int n, a[N];
long long ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] = max(a[i - 1] + 1, a[i]);//第i位小朋友的糖果要比上一位的数量多，要么他要的就多，要么比上一位多1
        ans += a[i];
    }
    printf("%lld\n", ans);
    return 0;
}