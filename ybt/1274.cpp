//【例9.18】合并石子
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[101],dp[101][101],sum[101];             //n表示石子数量，a表示石子重量，dp表示合并i到j的石子的最小代价，sum表示前缀和
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){                     //输入数据
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];                   //前缀和
    }
    for (int len=2;len<=n;len++)                //枚举合并的石子数量
        for (int i=1;i<=n-len+1;i++){           //枚举合并的区间段
            int j=i+len-1;                      
            dp[i][j]=0x7fffffff;                //初始化为最大值
            for (int k=i;k<j;k++)               //枚举区间段内所有合并可能
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);//dp[i][k]表示左堆，dp[k+1][j]表示右堆，sum[j]-sum[i-1]表示i到j的石子重量和
        }
    cout<<dp[1][n]<<endl;
    return 0;
}