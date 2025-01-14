//公共子序列
//输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。
//对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dp[201][201];               //dp[i][j]表示第一个序列的前i个字符和第二个序列的前j个字符的最大公共子序列的长度
int main(){
    string s1,s2;
    while (cin>>s1>>s2){
        int len1=s1.length(),len2=s2.length();
        for (int i=1;i<=len1;i++)
            for (int j=1;j<=len2;j++)
                if (s1[i-1]==s2[j-1])      //如果两个字符相等
                    dp[i][j]=dp[i-1][j-1]+1;    //最大公共子序列长度加1
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    //否则取两个序列的前一个字符的最大公共子序列长度
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}  