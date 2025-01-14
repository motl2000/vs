//装箱问题
#include <iostream>
#include <algorithm>
using namespace std;
int n,v,w[31],dp[20001];            //n表示物品数量，v表示背包容量，w表示物品重量，dp表示背包容量为i时的最大重量
int main(){
    cin>>v>>n;
    for (int i=1;i<=n;i++)
        cin>>w[i];
    for (int i=1;i<=n;i++)
        for (int j=v;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
    cout<<v-dp[v]<<endl;
    return 0;
}