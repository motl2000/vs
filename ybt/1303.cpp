//鸣人的影分身
#include <iostream>
using namespace std;
int dp[11][11],t;                                   //dp[i][j]表示查克拉为i，影分身为j时的情况
int main(){
    cin>>t;
    for (int i=1;i<=t;i++){
        int m,n;
        cin>>m>>n;
        for (int i=0;i<=m;i++)
            for (int j=0;j<=n;j++)
                if(i==0||j==1)                      //查克拉为0或只有一个影分身时，只有一种情况
                    dp[i][j]=1;
                else if(i<j)                        //查克拉小于影分身数时，只有dp[i][i]种情况
                    dp[i][j]=dp[i][i];
                else
                    dp[i][j]=dp[i-j][j]+dp[i][j-1]; //这里和盘子里分苹果的问题一样，影分身是盘子，查克拉是苹果
                                                    //分成两种情况，一种是每个影分身都有至少一个查克拉，一种是至少有一个影分身没有查克拉（其中包含了所有1到j-1个影分身的情况）
                                                    //dp[i-j][j]表示一共i个查克拉分配给j个影分身，
                                                    //j个影分身中每个影分身都有至少分配一个查克拉，剩下i-j个查克拉分配给j个影分身的情况
                                                    //dp[i][j-1]表示一共i个查克拉分配给j个影分身，
                                                    //j个影分身中至少有一个影分身没有分配到查克拉，i个查克拉分配给j-1个影分身的情况
        cout<<dp[m][n]<<endl;
    }
    return 0;
}