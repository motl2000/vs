//鸡蛋的硬度
//这题非常难理解，要把下面的注释看明白
#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][101],n,m;                           //dp[i][j]表示i个楼层j个鸡蛋时判断最坏的情况下最少需要多少次
int main(){
    int n,m;
    while (cin>>n>>m){
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                dp[i][j]=i;                     //初始化为i,即最坏的情况下最少需要i次
        for (int i=1;i<=n;i++)                  //枚举每种楼层
            for (int k=1;k<=i;k++)              //枚举每个楼层
                for (int j=2;j<=m;j++)          //枚举每个鸡蛋
                    dp[i][j]=min(dp[i][j],max(dp[k-1][j-1],dp[i-k][j])+1);  //dp[k-1][j-1]表示在k楼扔第j个鸡蛋碎了，所以最少次数就是k-1楼扔了j-1个鸡蛋都没碎,
                                                                            //因为dp[k-1][j-1]表示k-1楼扔了j-1个鸡蛋没碎的次数临界值是dp[k-1][j-1]，
                                                                            //所以最少次数就是k-1楼扔了j-1个鸡蛋都没碎+1次，所以是dp[k-1][j-1]+1
                                                                            //dp[i-k][j]表示在k楼扔第j个鸡蛋没碎，
                                                                            //即表明鸡蛋碎在k楼以上，所以最少次数就是在k楼扔了第一次以后，
                                                                            //在k楼以上的楼层中继续扔j个鸡蛋并测出最少次数，而楼上的楼层数为i-k，
                                                                            //此处楼上的n层楼的测试次数和楼下n层楼的测试次数是一样的，所以是dp[i-k][j]
        cout<<dp[n][m]<<endl;                   //输出最坏的情况下最少需要多少次
    }
    return 0;
}