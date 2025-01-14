//Charm Bracelet
#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int w[3501],d[3501],dp[12881];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>w[i]>>d[i];
    for (int i=1;i<=n;i++)
        for (int j=m;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
    cout<<dp[m]<<endl;
    return 0;
}