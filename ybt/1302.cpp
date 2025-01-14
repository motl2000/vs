//股票买卖，这题不像动态规划，更像贪心
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100001;
int a[maxn],t;
int mmin[maxn],mmax[maxn];                         //mmin[i]表示从左往右比较的最小值，mmax[i]表示从右往左比较的最大值
int li[maxn],ri[maxn];                             //li[i]表示从左往右计算的第i天的最大利润，ri[i]表示从右往左计算的第i天的最大利润
int main(){
    cin>>t;
    for (int i=1;i<=t;i++){
        int n;
        cin>>n;
        for (int j=1;j<=n;j++)
            cin>>a[j];
        mmin[1]=a[1];
        for (int j=2;j<=n;j++)
            mmin[j]=min(mmin[j-1],a[j]);           //计算mmin，即从左往右比较的最小值
        li[1]=0;
        for (int j=2;j<=n;j++)
            li[j]=max(li[j-1],a[j]-mmin[j-1]);     //计算li，即从左往右计算的最大利润
        mmax[n]=a[n];
        for (int j=n-1;j>=1;j--)
            mmax[j]=max(mmax[j+1],a[j]);           //计算mmax，即从右往左比较的最大值
        ri[n]=0;
        for (int j=n-1;j>=1;j--)
            ri[j]=max(ri[j+1],mmax[j+1]-a[j]);     //计算ri，即从右往左计算的最大利润
        int ans=0;
        for (int j=1;j<=n;j++)
            ans=max(ans,li[j]+ri[j]);               //计算最大利润，即第j天从左往右和从右往左的最大利润之和
                                                    //因为只能买卖两次，且第二次买入必须在第一次卖出之后，所以第j天的最大利润就是第j天从左往右的最大利润加上第j天从右往左的最大利润
        cout<<ans<<endl;                            //输出最大利润
    }
    return 0;
}