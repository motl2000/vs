//买书
//小明手里有n元钱全部用来买书，书的价格为10元，20元，50元，100元。
//问小明有多少种买书方案？（每种书可购买多本）
//输入：一个整数n(0<=n<=1000)
//输出：一个整数，表示方案数
#include <iostream>
#include <algorithm>
using namespace std;
int n,dp[1001],a[4]={10,20,50,100}; //dp[i]表示总额为i时的方案数
int main(){
    cin>>n;
    dp[0]=1;                        //总额为0时只有一种方案，即不买书
    for (int i=0;i<4;i++)
        for (int j=a[i];j<=n;j+=10) //由于间隔至少为10，所以每次加10，提高效率
            dp[j]+=dp[j-a[i]];
    cout<<dp[n]<<endl;
    return 0;
}