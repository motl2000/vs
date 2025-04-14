//1422：【例题1】活动安排
//思路：按结束时间排序，找下一个最先开始的不冲突的活动。
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int s;
    int f;
};
bool cmp(node a, node b)
{
    return a.f < b.f;
}
int main()
{
    int n;
    cin >> n;
    node a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].s >> a[i].f;
    }
    sort(a, a + n, cmp);
    int ans = 1;
    int end = a[0].f;
    for (int i = 1; i < n; i++)
    {
        if (a[i].s >= end)
        {
            ans++;
            end = a[i].f;
        }
    }
    cout << ans << endl;
    return 0;
}