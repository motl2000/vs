//采药，01背包
#include <iostream>
#include <algorithm>
using namespace std;
int t,m;                        //t表示时间，m表示草药种类
int a[101],b[101];              //a表示采摘时间，b表示价值
int dp[1001];                   //dp[i]表示时间为i时的最大价值
int main (){
    cin>>t>>m;
    for (int i=1;i<=m;i++)
        cin>>a[i]>>b[i];
    for (int i=1;i<=m;i++)
        for (int j=t;j>=a[i];j--)   //01背包，只能从大到小遍历
            dp[j]=max(dp[j],dp[j-a[i]]+b[i]);       
    cout<<dp[t]<<endl;
    return 0;
}