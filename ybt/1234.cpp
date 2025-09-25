#include <bits/stdc++.h>
using namespace std;
int n,a[201],ans,l;
void divide(){
	int g=0;
	for (int i=l-1;i>=0;i--){
		g=g*10+a[i];
		a[i]=g/2;
		g=g%2;
	}
	while (a[l-1]==0&&l>1){
		l--;
	}
}
void quickPow(int x){
	while (l>1||(l==1&&a[l-1]!=0)){//l==1&&a[l-1]!=0是为了处理l==1时，a[0]为0的情况，如2^0=1,0^0=1
		if (a[0]%2){               //如果个位为1，ans乘以x
			ans=ans*x%10000;
		}
		divide();
		x=x*x%10000;
	}
}
int main() {
	cin>>n;
	for (int i=0;i<n;i++){
		ans=1;
		memset (a,0,sizeof(a));
		string s;
		cin>>s;
		l=s.length();
		for (int i=0;i<s.length();i++)
			a[i]=s[l-i-1]-'0';
		quickPow(2011);
		cout<<ans<<endl;
	}

	return 0;
}