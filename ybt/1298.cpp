//计算字符串距离
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];   //dp[i][j]表示字符串s1的前i个字符和字符串s2的前j个字符的编辑距离
string a,b;
int n;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        int len1=a.length(),len2=b.length();
        for (int i=0;i<=len1;i++)
            dp[i][0]=i;
        for (int i=0;i<=len2;i++)
            dp[0][i]=i;
        for (int i=1;i<=len1;i++)
            for (int j=1;j<=len2;j++)
                if (a[i-1]==b[j-1])         //如果当前字符相等
                    dp[i][j]=dp[i-1][j-1];
                else                        //如果当前字符不相等
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;//dp[i-1][j]表示删除一个字符，dp[i][j-1]表示增加一个字符，dp[i-1][j-1]表示替换一个字符
        cout<<dp[len1][len2]<<endl;
    }
}