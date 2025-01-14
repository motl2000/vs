//宠物小精灵之收服，二维01背包
#include <iostream>
#include <algorithm>
using namespace std;
int V1,V2,k;                    //V1表示精灵球数量，V2表示皮卡丘初始体力，k表示小精灵数量
int dp[1001][501];              //dp[i][j]表示精灵球数量为i，皮卡丘体力为j时的最大收服数量
int main(){
    cin>>V1>>V2>>k;
    for (int i=1;i<=k;i++){
        int a,b;                    //a表示精灵球数量，b表示捕捉体力
        cin>>a>>b;
        for (int j=V1;j>=a;j--)     //01背包，只能从大到小遍历，表示要抓这只精灵时，每种精灵球总数下的情况
            for (int l=V2;l>=b;l--) //01背包，只能从大到小遍历，表示要抓这只精灵时，每种皮卡丘体力下的情况
                dp[j][l]=max(dp[j][l],dp[j-a][l-b]+1);  //选择抓或不抓这只精灵后的收服数量的最大值
    }
    cout<<dp[V1][V2]<<' ';
    int p=V2;
    while (p>=0 && dp[V1][p]==dp[V1][V2])   //二维表的最后一行，代表精灵球为V1时各种皮卡丘体力下的最大收服数量
        p--;                                //所以从右向左找到第一个不等于dp[V1][V2]的值，其上一个即为皮卡丘消耗体力最小值
    cout<<V2-p-1;                           //皮卡丘剩余体力的最大值，V2-(p+1)
    return 0;
}