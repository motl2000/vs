// 1429：线段
// 题目：在一个数轴上有n条线段，现选取其中k条线段使得这k条线段两两没有重合部分，问最大的k为多少?
// 输入：第一行为一个正整数n，下面n行每行2个数字ai，bi描述每条线段。
// 输出：输出一个正整数，表示最大的k值。
#include <iostream>
#include <algorithm>
using namespace std;
struct line
{
    int a, b;
};
bool cmp(line a, line b)
{
    if (a.b < b.b)
        return true;
    else if (a.b == b.b)
        return a.a < b.a;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    line *l = new line[n];
    for (int i = 0; i < n; i++)
    {
        cin >> l[i].a >> l[i].b;
    }
    sort(l, l + n, cmp);
    int ans = 1;
    int last = l[0].b;
    for (int i = 1; i < n; i++)
    {
        if (l[i].a >= last)
        {
            ans++;
            last = l[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}