//【例9.16】分组背包
#include <iostream>
#include <algorithm>
using namespace std;
int v,n,t,w[31],c[31],a[11][31],dp[201];
int main(){
    cin>>v>>n>>t;
    for (int i=1;i<=n;i++){
        int p;                  //p代表组号
        cin>>w[i]>>c[i]>>p;
        a[p][++a[p][0]]=i;      //a[p][0]代表第p组有多少个物品，a[p][i]代表第p组的第i个物品，此处同时记录该分组物品对应的i，可以和w[i]、c[i]对应,方便后面的循环

    }
    for(int k=1;k<=t;k++){              //遍历每个组
        for (int j=v;j>=0;j--){         //遍历每个容量
            for (int i=1;i<=a[k][0];i++){//遍历每个组的物品
                if (j>=w[a[k][i]])
                    dp[j]=max(dp[j],dp[j-w[a[k][i]]]+c[a[k][i]]);
            }
        }
    }    
    cout<<dp[v]<<endl;
    return 0;
}