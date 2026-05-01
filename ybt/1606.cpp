// 1606：【 例 1】任务安排 1
#include <bits/stdc++.h>
using namespace std;
long long f[5010], sumt[5010], sumc[5010];//f[i]表示前i个任务的最小花费，sumt[i]表示前i个任务的总时间，sumc[i]表示前i个任务的总代价
int n, s;
int main()
{
    cin >> n >> s;
    // 读入数据，计算前缀和
    for (int i = 1; i <= n; i++)    
    {
        int t, c;
        scanf("%d%d", &t, &c);
        sumt[i] = sumt[i - 1] + t;
        sumc[i] = sumc[i - 1] + c;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;                       //初始化f[0]=0，表示前0个任务的最小花费为0
    for (int i = 1; i <= n; i++)    //枚举前i个任务
        for (int j = 0; j < i; j++) //枚举前j个任务，把任务分割为0到j，j+1到i，0到j为多个批次，j+1到i为一次批次
            f[i] = min(f[i]
                , f[j] + sumt[i] * (sumc[i] - sumc[j]) //sumt[i] * (sumc[i] - sumc[j])表示前i个任务的完成时间*(任务j到i的代价和)，因为i到j的代价和是sumt[i]*c[j]+sumt[i]*c[j+1]+...+sumt[i]*c[i]=sumt[i]*(sumc[i]-sumc[j])
                    + s * (sumc[n] - sumc[j]));//启动成本对后续任务的影响,sumc[n] - sumc[j]表示后续任务的总代价,两者相乘 = 这次启动影响所有后续任务的总成本，由于本次启动，会造成j后的所有任务都多等待s时间，所以总代价为s*(sumc[n] - sumc[j])
    cout << f[n] << endl;

    return 0;
}