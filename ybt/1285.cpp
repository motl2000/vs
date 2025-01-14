//最大上升子序列和
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],dp[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++){
        dp[i]=a[i];
        for (int j=0;j<i;j++)
            if (a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+a[i]);
    }
    int ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}