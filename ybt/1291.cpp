//数字组合,求方案数
#include <iostream>
#include <algorithm>
using namespace std;
int n,t,a[21],dp[1001];
int main(){
    cin>>n>>t;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=t;j>=a[i];j--)
            dp[j]+=dp[j-a[i]];          //dp[j]表示总额为j时的方案数
    cout<<dp[t]<<endl;
    return 0;
}