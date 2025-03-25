//数的划分
#include <iostream>
using namespace std;
int dp[201][7],n,k;                                   //dp[i][j]表示i分成j份的情况
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            if (i<j)                                    //i小于j时不够分，只有0种情况
                dp[i][j]=0;                 
            else if(i==j || j==1)                       //i等于j 或 j==1 时只有一种情况
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-j][j]+dp[i-1][j-1];       //分成两种情况，1.每份都大于1的情况，2.至少有一份为1的情况
                                                        //dp[i-j][j]表示i分成j份，且每份都大于1即大于等于2的情况
                                                        //原因是，如果i分成j份存在某一份为1，那么每一份都去掉1后，就必然有一份为0，这种情况就不是i分成j份且每份都大于1的情况了
                                                        //所以dp[i-j][j]有意义就一定表示i分成j份且每份都大于1的情况，否则dp[i-j][j]就是0
                                                        //dp[i-1][j-1]表示i分成j份，至少有一份为1的情况，所以就相当于i-1分成j-1份的情况
        }

    }
    cout<<dp[n][k]<<endl;
    return 0;
}