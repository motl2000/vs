//【例9.22】复制书稿(book)
#include <iostream>
#include <algorithm>
using namespace std;
int m,k,a[501],dp[501][501],sum[501];       //k为人数，m为书的数量，a为每本书的页数，sum为前缀和，dp[i][j]表示前j本书分给i个人的所需的最少时间
int print(int i,int j){                     //i为剩余的书，j为剩余的人数，因为有相同解时要让后面的人尽量多抄些书，所以要逆序处理
    int t,x;
    if (j==0)                               //递归结束条件
        return 0;
    if (j==1){                              //只有一个人时
        cout<<1<<" "<<i<<endl;
        return 0;
    }
    t=i;
    x=a[i];
    while (x+a[t-1]<=dp[k][m]){             //找到分割点,使得当前区间的和小于等于dp[k][m]，即这区间内的书分给这个人的时间小于等于dp[k][m]
        t--;
        x+=a[t];
    }
    print(t-1,j-1);                         //递归，前t-1本书分给j-1个人
    cout<<t<<" "<<i<<endl;
    return 0;
}
int main(){
    cin>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];               //前缀和
        dp[1][i]=sum[i];                    //只有一个人时，前i本书的时间
    }
    for(int i=2;i<=k;i++){                  //k个人时
        for(int j=1;j<=m;j++){              //j本书时
            dp[i][j]=0x7fffffff;            //初始化为最大值
            for(int l=1;l<j;l++){           //枚举分割点
                //sum[j]-sum[l]为第l+1到第j本书的页数和
                //max(dp[i-1][l],sum[j]-sum[l])为前l本书分给i-1个人的最少时间和第l+1到第j本书的页数和的最大值
                //取最小值
                dp[i][j]=min(dp[i][j],max(dp[i-1][l],sum[j]-sum[l]));   
            }
        }
    }
    print(m,k);                             //递归输出
    return 0;   
}