//大盗阿福
#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001],t,a[100001];                           //dp[i]表示前i个房间的最大价值
int main(){
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        for (int j=1;j<=n;j++)
            cin>>a[j];
        dp[1]=a[1];
        for (int j=2;j<=n;j++)
            dp[j]=max(dp[j-1],dp[j-2]+a[j]);           //dp[j-1]表示不偷第j个房间，dp[j-2]+a[j]表示偷第j个房间
        cout<<dp[n]<<endl;                              //输出最大价值
    }
}