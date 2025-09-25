#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 105;          //食材总数的最大值
const int C = 505;          //酸度和甜度的最大值
const int D = N * C * 2;    //酸度和甜度的差值状态最大总数，总的状态空间是从-N*C 到 N*C
int n;      //食材总数
int f[D];   //记录酸度和甜度的差值状态，表示当前差值下最大的酸度和甜度的总和
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < D; i++)
        f[i] = -1e9;            
    f[N * C] = 0;                   //表示初始状态（酸度和甜度差值为 0）的总和为 0
    while (n--)                     //遍历所有操作
    {
        int a, b;
        scanf("%d%d", &a, &b);
        int x = a + b, y = a - b;   //x表示选择该食材时，酸度和甜度的总和，y表示选择该食材时，酸度和甜度的差值
        if (y <= 0)                 //甜度大于或等于酸度
        {
            //遍历每一种酸甜差值状态，判断选择当前食材后，可以为每一种酸甜差值状态提供更大的酸甜综合
            for (int i = -y; i < D; i++)    //从 -y 开始正向更新状态，这里的y<=0，所以循环相当于从 0 开始到 D - y - 1
                //注意，y<=0，所以i+y一定小于i
                //f[i] + x表示第i个差值选择该食材后的酸甜综合
                //如果选择当前食材，就相当于当前酸甜差值i要减去|y|
                //如果f[i] + x > f[i + y]，则更新f[i + y] = f[i] + x
                f[i + y] = max(f[i + y], f[i] + x);//选择该食材后，酸度和甜度的差值状态从 i 转移到 i + y，并更新总和。
        }
        else
        {
            for (int i = D - y - 1; i; i--)//从 D - y - 1 开始反向更新状态
                f[i + y] = max(f[i + y], f[i] + x);
        }
    }
    printf("%d\n", f[N * C]);//N*C 表示酸度和甜度的差值为 0 的状态
    return 0;
}