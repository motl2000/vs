//1223：An Easy Problem
//思路：要保持1的数量不变
#include <bits/stdc++.h>
using namespace std;
const int maxN=1000000;
int n,a[maxN+1];
void f(int x){
	memset (a,0,sizeof(a));
	int l=0;
	while (x!=0){
		a[maxN-l]=x%2;
		x/=2;
		l++;
	}
	int j=maxN;
	while (a[j]==0)
		j--;

	//记录右侧连续的有几个1 
	int i=0; 
	while (a[j]==1){
		a[j]=0;		
		j--;
		i++;
	}
	//连续的1段左移一个 
	a[j]=1;
	//剩下的1放到末尾 
	int t=i-1;
	while (t){
		a[maxN-t+1]=1;
		t--;
	}
	j=maxN-j+1;
	j=max(j,l);
	int ans=0;
	for(int k=0;k<j;k++) {
		if (a[maxN-k])
			ans+=pow(2,k);
	}
	cout<<ans<<endl;
}
int main() {
	while (cin>>n&&n!=0) {
		f(n);
	}
	
	return 0;
}