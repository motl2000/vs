//糖果
#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][101],n,k;                           //dp[i][j]表示前i个糖果中数量和%k为j的最大值
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        dp[i][x%k]=x;                           //初始化前i个糖果中和%k的最大值为x
        for (int j=0;j<k;j++)
            if (dp[i-1][j]){
                dp[i][(j+x)%k]=dp[i-1][j]+x;    //如果前i-1个糖果中有和%k为j，那么前i个糖果中和为(j+x)%k的最大值为前i-1个糖果中和%k为j的最大值加上第i个糖果
            }
        for (int j=0;j<k;j++)
            dp[i][j]=max(dp[i][j],dp[i-1][j]);  //用新的dp[i][j]和旧的dp[i-1][j]中的最大值更新dp[i][j]
    }
    cout<<dp[n][0]<<endl;                       //输出前n个糖果中和%k为0的最大值
    return 0;
}