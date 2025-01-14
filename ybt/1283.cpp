//登山
//求从左到右的最长上升子序列和从右到左的最长上升子序列的和减1的最大值
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n],dp1[n],dp2[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    //求从左到右的最长上升子序列
    for (int i=0;i<n;i++){
        dp1[i]=1;
        for (int j=0;j<i;j++)
            if(a[i]>a[j])
                dp1[i]=max(dp1[i],dp1[j]+1);
    }
    //求从右到左的最长上升子序列
    for (int i=n-1;i>=0;i--){
        dp2[i]=1;
        for (int j=n-1;j>i;j--)
            if(a[i]>a[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
    }
    int ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans,dp1[i]+dp2[i]-1);       //减1是因为重复计算了一次
    cout<<ans<<endl;
    return 0;
}