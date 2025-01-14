//摘花生
#include <iostream>
#include <algorithm>
using namespace std;
int t;
int main(){
    cin>>t;
    for (int i=1;i<=t;i++){
        int m,n;
        cin>>m>>n;
        int a[m][n];
        for (int j=0;j<m;j++)
            for (int k=0;k<n;k++)
                cin>>a[j][k];
        int dp[m][n];
        for (int j=0;j<m;j++)
            for (int k=0;k<n;k++){
                if (j==0&&k==0)
                    dp[j][k]=a[j][k];
                else if (j==0)
                    dp[j][k]=dp[j][k-1]+a[j][k];
                else if (k==0)
                    dp[j][k]=dp[j-1][k]+a[j][k];
                else
                    dp[j][k]=max(dp[j-1][k],dp[j][k-1])+a[j][k];
            }
        cout<<dp[m-1][n-1]<<endl;
    }
    return 0;
}