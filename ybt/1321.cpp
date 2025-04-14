#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
string s;
string dp[241][241];
int n;
char a[250];
int main() {
//动态规划做法 
//	cin>>s;
//	cin>>n;
//	int l=s.length();

//	dp[l-1][1]=s[l-1];
//	for (int i=l-2;i>=0;i--){
//		for (int j=1;j<=l-i;j++){
//			string tc=s[i]+dp[i+1][j-1];
//			if (dp[i+1][j]==""){
//				dp[i][j]=tc;
//			}
//			else{
//				if (tc<dp[i+1][j]){
//					dp[i][j]=tc;
//				}
//				else{
//					dp[i][j]=dp[i+1][j];
//				}
//			}
//		}
//	}
//	int i=0;
//	string ans=dp[0][l-n];
//	while (ans[i]=='0'){
//		i++;
//	}
//	cout<<ans.substr(i,ans.length()-i);

//贪心做法 
//删除数位得到数最小，就从高位看起。 
//在低一位不是0的情况下：如果高位比它低的一位大，就删除这个高位。其它位依次补上来 
//再从最高位查过来(k大于1时），反复进行
//如果高位都比下一位小，删除最后的一位。 
//用字符串来做
	scanf("%s%d",a,&n);//第一个看作字串，第二个是整数 
	int l=strlen(a);
	while (n--){ 
		for (int i=0;i<l;i++){
			if (a[i]>a[i+1]){
				for (int j=i;j<l;j++){
					a[j]=a[j+1];
				}
				break;
			}
		}
		s[l]='\0';
		l--;
	}
	int i=0;
	while (a[i]=='0'){
		i++;
	}
	for(;i<l;i++)//从第一个不是0的位输出 
		 printf("%c",a[i]);
	return 0;
}