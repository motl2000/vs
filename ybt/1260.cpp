#include <bits/stdc++.h> 
using namespace std;
int n,a[1002],dp[1002],ans=1,b[1002];
int main () {
	int i=0;
	int k=0;
	while (cin>>a[i]) {
		
		dp[i]=1;                    
		for (int j=0;j<i;j++){
			if (a[j]>=a[i]){        
				dp[i]=max(dp[j]+1,dp[i]);   
			}
			ans=max(ans,dp[i]);
		}
		//判断需要几套拦截系统，k是套数，b[]存储每套的最低高度 ,b[]从b[1]开始 
		if (k==0){
			k++;//如果一套都没有，就给一套 
			b[k]=a[i];
		}
		else{
			int mini=0;             //可以打击当前导弹且高度最低的系统编号
			int minh=30001; 
			for (int j=1;j<=k;j++){//找到一套可用的且高度最小的系统 
				if (a[i]<=b[j]&&minh>=b[j]){
					minh=b[j];
					mini=j; 
				}
			}
			if (minh<30001&&minh>0){
				b[mini]=a[i];				
			}
			else{
				b[++k]=a[i];//如果没找到可用的系统，添加一套系统
			
			}
		} 
		
		i++;
		if (cin.get() == '\n') break;//没有这句就没法停下来 
	}
	cout<<ans<<endl;
	cout<<k<<endl;
	return 0;
}