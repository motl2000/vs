//【例9.12】完全背包问题
#include <bits/stdc++.h>
using namespace std;
int m,n,wight[201],value[201],dp[201],dp2[201][201];
int main() {
	cin>>m>>n;
	for (int i=1;i<=n;i++){
		cin>>wight[i]>>value[i];
	}
//	//二维
//	for (int i=1;i<=n;i++) {
//		for (int j=1;j<=m;j++){
//			if (j<wight[i])
//				dp2[i][j]=dp2[i-1][j];
//			else
//				dp2[i][j]=max(dp2[i-1][j],dp2[i][j-wight[i]]+value[i]);
//		}
//	}
	
	//一维 
//	//逆推，当前背包容量可以放多少个当前物品 
//	for (int i=1;i<=n;i++){
//		for (int j=m;j>=1;j--){
//			for (int k=1;k<=j/wight[i];k++) 
//				dp[j]=max(dp[j],dp[j-k*wight[i]]+k*value[i]);
//		}
//	}
//	cout<<dp[m]<<endl;
	//简化，以上逆推公式可以推导出 dp[j]=max(dp[j],dp[j-wight[i]]+value[i]); 推导原理见图片 
	for (int i=1;i<=n;i++){
		for (int j=wight[i];j<=m;j++){
			dp[j]=max(dp[j],dp[j-wight[i]]+value[i]);
		}
	}
//	cout<<"max="<<dp2[n][m]<<endl;	 
	cout<<"max="<<dp[m]<<endl;	 
	return 0;
}
