//1314：【例3.6】过河卒(Noip2002)
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int m,n,x,y;
long long dp[21][21];
int ax[8]={-1,-2,-2,-1,1,2,2,1};
int ay[8]={-2,-1,1,2,2,1,-1,-2};
int main() {
	cin>>n>>m>>x>>y;
	dp[0][0]=1;
	bool b=true;
	for (int i=0;i<=n;i++){
		for (int j=0;j<=m;j++){
			if (i==0&&j==0)
				continue;
			b=true;
			if (i==x&&j==y)
				b=false;
			for (int k=0;k<8;k++){
				if (i==x+ax[k]&&j==y+ay[k]){
					b=false;
					break;
				}
			}
			if (b) {
				if (i-1<0){
					dp[i][j]=dp[i][j-1];
				}
				else if (j-1<0){
					dp[i][j]=dp[i-1][j];
				}
				else{
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
				}				
			}
		}
	}
	cout<<dp[n][m];
	return 0;
}