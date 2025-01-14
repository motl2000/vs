//【例9.11】01背包问题
#include <bits/stdc++.h>
using namespace std;
int m,n,wight[201],value[201],dp[201][201],dp1[201];    //m代表背包容量，n代表物品数量,dp1是一维DP数组,dp是二维DP数组,dp[i][j]代表前i个物品放入容量为j的背包的最大价值,dp1[j]代表容量为j的背包的最大价值
int main() {
	cin>>m>>n;
	for (int i=1;i<=n;i++){
		cin>>wight[i]>>value[i];
	}
	
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++){
//			if (wight[i]<=j){
//				dp[i][j]=max(dp[i-1][j],dp[i-1][j-wight[i]]+value[i]);
//			}
//			else
//				dp[i][j]=dp[i-1][j];
//		}
//	}
	//一维DP的原理，由于每次推导得出的dp[i][j]保存下来是多余的， 只要保存每次得出的最大值然后保存在dp[j]里即可 
	for (int i=1;i<=n;i++){
		for (int j=m;j>=wight[i];j--){//一维DP需要倒序遍历背包容量 
			dp1[j]=max(dp1[j],dp1[j-wight[i]]+value[i]);
		}
	}
//	cout<<dp[n][m]<<endl;
	cout<<dp1[m];
	return 0;
}
