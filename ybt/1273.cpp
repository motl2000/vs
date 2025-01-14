//【例9.17】货币系统
#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
long long dp[10001];                //dp[i]表示总额为i时的方案数
int main(){
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dp[0]=1;

    //方案一，理解起来略微复杂
    // for (int i=1;i<=n;i++)
    //     for (int j=m;j>=a[i];j--)        //小于a[i]的情况不用考虑，因为a[i]已经大于j了，且只能从大到小遍历，否则会重复计算
    //         for (int k=1;k<=j/a[i];k++)  //a[i]的个数
    //             dp[j]+=dp[j-k*a[i]];     //已有的j金额的方案数加上加上k个a[i]后的方案数
    //方案二
    for (int i=1;i<=n;i++)
        for (int j=a[i];j<=m;j++)    //小于a[i]的情况不用考虑，因为a[i]已经大于j了
            dp[j]+=dp[j-a[i]];       //已有的j金额的方案数加上加上a[i]后的方案数
    cout<<dp[m]<<endl;
    return 0;
}