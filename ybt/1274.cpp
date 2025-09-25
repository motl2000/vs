//【例9.18】合并石子
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n,a[101],dp[101][101],sum[101];             //n表示石子数量，a表示石子重量，dp表示合并i到j的石子的最小代价，sum表示前缀和
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){                     //输入数据
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];                   //前缀和
    }
    memset(dp,0x3f3f3f3f,sizeof(dp));           //将dp初始化为一个极大值
    for(int i=1;i<=n;i++) dp[i][i]=0;           //合并自己的代价为0
    //求dp
    for (int i=n-1;i>=1;i--){                   //i枚举所有石堆，从大到小
        /*
        动态规划的依赖关系：
        dp[i][j] 的值依赖于 dp[i][k] 和 dp[k+1][j] （即更小的区间）。
        倒序枚举 i 可以确保在计算 dp[i][j] 时， dp[k+1][j] 已经被计算过（因为 k+1 > i ）。
        如果从 1 到 n 枚举 i ，可能会依赖未计算的 dp[k+1][j] ，导致逻辑错误。
        */
        for (int j=i+1;j<=n;j++){               //枚举i到n的所有区间段
            for (int k=i;k<j;k++){              //枚举i到j的区间分成两块合并，k是分割点
                //两个区间段各自合并一次代价加上这两个区间段合并代价的总和的最小值
                //两个区间合并一次的代价是区间左端石堆到右端石堆的和，是固定的
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    //输出数据
    cout<<dp[1][n]<<endl;
    return 0;
}