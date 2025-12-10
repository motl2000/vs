#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, q, a[N], g;
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    return gcd(b, a % b);
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++)
        g = gcd(g, a[i] - a[i - 1]);
    for (int i = 1; i <= q; i++)
        printf("%d\n", gcd(g, a[1] + i));
    return 0;
}