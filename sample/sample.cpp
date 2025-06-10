// 斐波那契数列，用数组递推
#include <iostream>
using namespace std;
int f[100];
/**
 * @brief 计算斐波那契数列的第n项
 * 
 * 使用动态规划方法计算斐波那契数列的第n项，并输出结果。
 * 数列定义：f(1)=1, f(2)=1, f(n)=f(n-1)+f(n-2) (n>2)
 * 
 * @note 需要用户输入整数n作为参数
 * @warning 代码中使用了未定义的数组f，需要预先定义足够大的数组
 */
int main()
{
    int n;
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    cout << f[n] << endl;
    return 0;
}