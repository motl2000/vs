//【例9.21】方格取数
#include <iostream>
#include <algorithm>
using namespace std;
int a[11][11],dp[11][11][11][11];       //a表示方格，dp[i][j][k][l]表示第一条路径到i,j，第二条路径到k,l时的最大值
int main(){
    int n;
    cin>>n;
    while (1){
        int x,y,z;
        cin>>x>>y>>z;
        if (x==0 && y==0 && z==0)
            break;
        a[x][y]=z;
    }
    for (int i=1;i<=n;i++)                      
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
                for (int l=1;l<=n;l++){
                    //状态转移方程,取四种情况的最大值
                    //1.第一条路径到i-1,j，第二条路径到k-1,l，左、左
                    //2.第一条路径到i-1,j，第二条路径到k,l-1，左、上
                    //3.第一条路径到i,j-1，第二条路径到k-1,l，上、左
                    //4.第一条路径到i,j-1，第二条路径到k,l-1，上、上
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i-1][j][k][l-1]),max(dp[i][j-1][k-1][l],dp[i][j-1][k][l-1]))+a[i][j]+a[k][l];
                    if (i==k && j==l)               //如果两个点重合，只能取一次
                        dp[i][j][k][l]-=a[i][j];
                }
    cout<<dp[n][n][n][n]<<endl;
    return 0;
}