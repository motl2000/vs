//最低通行费
#include <iostream>
#include <algorithm>
using namespace std;
int a[101][101],dp[101][101];
int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    dp[0][0]=a[0][0];
    for (int i=1;i<n;i++){              //初始化第一行和第一列
        dp[0][i]=dp[0][i-1]+a[0][i];
        dp[i][0]=dp[i-1][0]+a[i][0];
    }
    for (int i=1;i<n;i++)
        for (int j=1;j<n;j++)
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
    cout<<dp[n-1][n-1]<<endl;
    return 0;
}