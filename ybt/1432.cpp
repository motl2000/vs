// 1432：糖果传递
#include <bits/stdc++.h>

long long a[1000005], c[1000005];
using namespace std;
int main(int argc, char *argv[])
{
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    // 计算平均值
    int average = sum / n;

    /*
    x1...n表示i小朋友给左边小朋友的糖果数量,正数为给，负数为索取
    当前小朋友手头的糖果 - 给左边的糖果 + 右边给的糖果 = 平均值
    a1 - x1 + x2 = average ==> x2 = x1 + average - a1 ==> x2 = x1 - (a1 - average)
    ......
    ......
    最终可以写成如下的式子：                      ==>在数组c中存放了x1减去的一系列值，第一个数是0
    x1 = x1 - 0                               ==>c[1] = 0
    x2 = x1 - (a1 - average)                  ==>c[2] = c[1] + a[1] - average
    x3 = x1 - (a1 -average + a2 - average)    ==>c[3] = c[2] + a[2] - average
    ......
    xn = x1 - (a1 + ... an-1 - (n-1)*average) ==>c[n] = c[n-1] + a[n-1] - average
    */
    c[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        c[i] = c[i - 1] + a[i - 1] - average;
    }
    /*
    x1 + x2 + x3 +...+ xn的值最小，即移动代价最小才符合题目要求，转化为求点到所有点之间的距离和。
    因为是要求x1-ci的和的最小值，将每个c_i视为数轴上的点，寻找x1的位置使得该点到所有c_i点的总距离最小。
    先排序，取中位数点进行计算，中位点就是x1的位置
    */
    // 升序
    sort(c + 1, c + n + 1);

    long long ans = 0;
    // 队列的中位数
    int mid = c[n / 2 + 1];
    // 求点到所有点之间的距离和
    for (int i = 1; i <= n; i++)
    {
        ans += abs(c[i] - mid);
    }
    cout << ans;
    return 0;
}