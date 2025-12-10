// 有趣的数字和
// 分治
#include <algorithm>
#include <cstdio>
using namespace std;
int l, r;
long long ans;
// 计算[0,n]中所有数字和，p表示奇数或偶数，0表示偶数，1表示奇数
// 返回值为pair，first表示数字个数，second表示数字和
pair<int, long long> cal2(int n, int p)
{
    if (n == 0)
    {
        return {1 - p, 0};
    }
    if (n == 1)
    {
        return {1, p};
    }
    return {(n + 1) / 2, 1ll * n * (n + 1) / 4};//此处仅是近似值，因此需要分治后修正
}
// 计算[0,n]中所有数字和，p表示奇数或偶数，0表示偶数，1表示奇数
pair<int, long long> cal(int n, int p)
{
    if (n <= 1)
    {
        return cal2(n, p);
    }
    long long x = 1ll << (31 - __builtin_clz(n));       //取n的二进制最高位
    auto l = cal2(x - 1, p);                            //计算0..x-1的p和
    auto r = cal(n - x, 1 - p);                         //计算x..n的1-p和,即奇偶翻转，
    return {l.first + r.first, l.second + r.second + x * r.first};//l.first + r.first 表示数字个数，统计的目的是为了给上层的r.first使用，l.second + r.second + x * r.first 表示数字和，即本层的左右两部分的和加上前面x-1的那个以1开头后面都是0的那个数和他右边那些1的合计数
}
int main()
{
    scanf("%d%d", &l, &r);
    ans -= cal(l - 1, 1).second;
    ans += cal(r, 1).second;
    printf("%lld\n", ans);
    return 0;
}