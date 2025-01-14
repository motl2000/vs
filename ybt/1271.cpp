//【例9.15】潜水员
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m,n,k;                              //m,n,k分别代表潜水员的氧气量，氮气量和气瓶的数量
int a[1001],b[1001],c[1001],dp[1001][1001]; //a,b,c分别代表每个气瓶的氧气量，氮气量和气瓶的重量，dp[i][j]代表氧气量为i，氮气量为j时的最小气瓶重量
int main(){
    memset (dp,127,sizeof(dp));         //初始化为最大值，这里表示无穷大，128是无穷小
    dp[0][0]=0;
    cin>>m>>n>>k;
    for (int i=1;i<=k;i++)
        cin>>a[i]>>b[i]>>c[i];
    for (int i=1;i<=k;i++)
        for (int j=m;j>=0;j--)
            for (int l=n;l>=0;l--){
                //书上的写法，不太好理解
                // int t1=j+a[i];          //t1,t2分别代表加上当前气瓶的氧气量和氮气量
                // int t2=l+b[i];
                // if (t1>m)               //如果氧气量超过m，就取m
                //     t1=m;   
                // if (t2>n)               //如果氮气量超过n，就取n
                //     t2=n;
                // dp[t1][t2]=min(dp[t1][t2],dp[j][l]+c[i]);
                //简化，下面这行更容易理解
                dp[j][l]=min(dp[j][l],dp[max(0,j-a[i])][max(0,l-b[i])]+c[i]);//使用当前钢瓶时的最小重量，max(0,j-a[i])是为了防止j-a[i]为负数
            }
    cout<<dp[m][n]<<endl;
}