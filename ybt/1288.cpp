//三角形最佳路径问题
#include <iostream>
#include <algorithm>
using namespace std;
int n,a[101][101],dp[101][101];
int main(){
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<=i;j++)          //注意这里是j<=i
            cin>>a[i][j];
    dp[0][0]=a[0][0];
    for (int i=1;i<n;i++){              //初始化第一行,第一列
        dp[i][0]=dp[i-1][0]+a[i][0];
        dp[i][i]=dp[i-1][i-1]+a[i][i];
    }
    for (int i=1;i<n;i++)
        for (int j=1;j<i;j++)           
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
    int ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans,dp[n-1][i]);
    cout<<ans<<endl;
    return 0;
}