//P1094 [NOIP 2007 普及组] 纪念品分组
#include <iostream>
#include <algorithm>
using namespace std;
int w,n,a[30001],ans;
int main() {
	cin>>w>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int i=0,j=n-1;
	while (i<=j){
		if (a[j]+a[i]>w){
			j--;
			ans++;
		}
		else{
			j--;
			i++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}