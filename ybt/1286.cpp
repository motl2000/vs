//怪盗基德的滑翔翼,动态规划
#include <iostream>
#include <algorithm>
using namespace std;
int k,ans;
int main(){
    cin>>k;
    for (int i=1;i<=k;i++){
        int n;
        cin>>n;
        //求最大上升子序列和最大下降子序列
        int a[n],dp1[n],dp2[n];
        for (int j=0;j<n;j++)
            cin>>a[j];

        for (int j=0;j<n;j++){
            dp1[j]=1;
            dp2[j]=1;
            for (int k=0;k<j;k++){
                if (a[j]>a[k])
                    dp1[j]=max(dp1[j],dp1[k]+1);
                if (a[j]<a[k])
                    dp2[j]=max(dp2[j],dp2[k]+1);
            }
        }
        ans=0;
        for (int j=0;j<n;j++)
            ans=max(ans,max(dp1[j],dp2[j]));
        cout<<ans<<endl;
    }
    return 0;

}


