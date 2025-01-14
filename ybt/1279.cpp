//【例9.23】橱窗布置(flower)
#include <bits/stdc++.h>
using namespace std;
int f,v,a[101][101],dp[101][101],c[101][101];   //f为花的数量，v为花瓶的数量，a为花的价值，dp[i][j]表示前i朵花放在前j个花瓶的最大价值，c[i][j]表示前i朵花放在前j个花瓶的最后一朵花的位置
int main(){
    cin>>f>>v;
    for(int i=1;i<=f;i++)
        for(int j=1;j<=v;j++)
            cin>>a[i][j];
    memset (dp,128,sizeof(dp));                 //初始化为负无穷，可以保证每束花都至少有一个花瓶
    for (int i=1;i<=v-f+1;i++)                   //初始化第一束花，第一束花最多可以放在前v-f+1个花瓶中
        dp[1][i]=a[1][i];                       
    for (int i=2;i<=f;i++)                      //枚举每束花
        for (int j=i;j<=v-f+i;j++)              //枚举每个花瓶，每束花最多可以放在前v-f+i个花瓶中
            for (int k=i-1;k<j;k++)             //枚举前一束花的最后一个花瓶
                if (dp[i][j]<dp[i-1][k]+a[i][j]){   //如果前i-1束花放在前k个花瓶的最大价值加上第i束花放在第j个花瓶的价值大于前i束花放在前j个花瓶的最大价值
                    dp[i][j]=dp[i-1][k]+a[i][j];    //更新最大价值
                    c[i][j]=k;                      //记录最后一朵花的位置,即第i束花放在第j个花瓶的最后一朵花的位置
                }
    int ans=INT_MIN;
    int k;
    for (int i=f;i<=v;i++){                      //枚举最后一束花放在前v个花瓶中的最大价值，因为最后一束花可以放在f到v个花瓶中，并不是dp[f][v]为最大值，需要从dp[f][f]到dp[f][v]中找最大值
        if (ans<dp[f][i]){                        //如果当前最大价值大于之前的最大价值
            ans=dp[f][i];                         //更新最大价值
            k=i;                                  //记录最后一朵花的位置
        }
    }
    cout<<ans<<endl;                              //输出最大价值
    int x[101];
    for (int i=1;i<=f;i++){                          
        x[i]=k;
        k=c[f-i+1][k];                             //逆序找到每束花的最后一朵花的位置
    }
    for (int i=f;i>=1;i--)                         //输出每束花的最后一朵花的位置
        cout<<x[i]<<" ";
    return 0;
}