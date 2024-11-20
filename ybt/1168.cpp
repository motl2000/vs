#include <bits/stdc++.h>
using namespace std;
int a[201],b[201];
string x,y,ans;
string cut(string s){
	int i=0;
	while (s[i]=='0'&&i<s.length()){
		i++;
	}
	return s.substr(i,s.length()-i);
}
int main() {
	    // visualize `myGraphJson`!
	cin>>x>>y;
	x=cut(x);
	y=cut(y);
	int l1=x.length();
	for (int i=0;i<l1;i++){
		a[i]=x[l1-i-1]-'0';
	}
	int l2=y.length();
	for (int i=0;i<l2;i++){
		b[i]=y[l2-i-1]-'0';
	}
	int l=max(l1,l2);
	int g=0;
	for (int i=0;i<l;i++){
		int d=a[i]+b[i]+g;
		g=d/10;
		char t='0'+d%10;
		ans=t+ans;
	}
	if (g>0)
		ans='1'+ans;
	cout<<ans;
	return 0;
}
