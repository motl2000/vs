//开餐馆
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int main(){
    cin>>t;
    int n,k;                        //n表示地点数量，k表示距离限制
    while (t--){
        cin>>n>>k;
        int m[1001],p[1001];        //m表示地点的位置，p表示地点的餐馆利润
        for (int i=1;i<=n;i++)
            cin>>m[i];
        for (int i=1;i<=n;i++)
            cin>>p[i];
        int dp[1001];               //dp[i]表示前i个地点的最大利润
        memset(dp,0,sizeof(dp));    //初始化dp数组,必须
        for (int i=1;i<=n;i++){
            dp[i]=p[i];             //初始化dp[i]
            int mm=i-1;             //mm表示前i个地点中距离第i个地点最近的地点
            while (m[i]-m[mm]<=k && mm>0)
                mm--;               //找到前i个地点中距离第i个地点最近的地点
            dp[i]=max(dp[i-1],dp[mm]+p[i]); //状态转移方程，选择把第i个地点作为餐馆还是不作为餐馆
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }

}