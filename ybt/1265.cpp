//1265：【例9.9】最长公共子序列
#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001],ans;//dp[i][j]表示x前i个字符与y前j个字符的LCS
string x,y;
int main() {
	cin>>x>>y;
	int xl,yl;
	xl=x.length();
	yl=y.length();
	for (int i=1;i<=xl;i++){
		for (int j=1;j<=yl;j++){
			if (x[i-1]==y[j-1])//x[i-1]是X中的第i个字符。y同理
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[xl][yl];
	return 0;
}
